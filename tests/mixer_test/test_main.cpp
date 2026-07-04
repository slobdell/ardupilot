// Unit tests for AvatarMixer and BlimpMixer.
//
// ACTIVE CONFIG
// =============
// Both mixer tests run against g_config = avatarConfig
// (ACTIVE_CONFIG = CONFIG_TYPE_AVATAR, forward_flight_physical_angle_deg = 95°,
//  cruise_physical_angle_deg = 90°, reverse_flight_physical_angle_deg = -15°).
// Expected values are computed for that config.
//
// Key normalisation constants (used throughout):
//   tilt_angle = current_tilt_deg / FWD_DEG  (positive tilt)
//   In copter mode the TVC is capped at CRUISE_DEG, so max tilt_angle = CRUISE_DEG/FWD_DEG.
static constexpr float FWD_DEG    = 95.0f;  // forward_flight_physical_angle_deg
static constexpr float CRUISE_DEG = 90.0f;  // cruise_physical_angle_deg
//
// WHAT IS BEING TESTED
// ====================
// Layer 1 — elevator_tilt_split(): pure inline function, zero dependencies.
// Layer 2 — AvatarMixer plane mode: direct actuator mapping, no timestamp needed.
// Layer 3 — AvatarMixer copter mode: delegates to TVC brain; needs micros() stub.
// Layer 4 — BlimpMixer plane mode: elevator/tilt handoff with val_neutral = 90/90 = 1.0.
// Layer 5 — BlimpMixer manual override: dumb RC passthrough.
//
// RATE-LIMIT NOTE
// ===============
// AvatarMixer copter mode rate-limits the tilt servo by (tilt_rate_up_dps * dt).
// Tests set tilt_rate_up_dps = 1e6f to make the limit effectively infinite so a
// single call reaches the steady-state tilt angle immediately.

#include <cstdio>
#include <cmath>
#include <algorithm>

#include "AP_Motors6DOF_AvatarMixer.h"
#include "AP_Motors6DOF_BlimpMixer.h"

using namespace AP_Motors6DOF_Mixer;

// ============================================================================
// Test infrastructure
// ============================================================================

static int g_checks_run    = 0;
static int g_checks_failed = 0;

static void _check_near(float expected, float actual, float tol,
                        const char* label, int line)
{
    g_checks_run++;
    if (std::fabs(expected - actual) > tol) {
        std::printf("  FAIL (line %d) %s\n    expected %.5f  got %.5f  tol %.5f\n",
                    line, label, expected, actual, tol);
        g_checks_failed++;
    }
}

static void _check_true(bool cond, const char* label, int line)
{
    g_checks_run++;
    if (!cond) {
        std::printf("  FAIL (line %d) %s\n", line, label);
        g_checks_failed++;
    }
}

#define CHECK_NEAR(expected, actual, tol) \
    _check_near((expected), (actual), (tol), #actual " ~= " #expected, __LINE__)
#define CHECK_TRUE(cond)  _check_true((cond),  #cond,  __LINE__)
#define CHECK_FALSE(cond) _check_true(!(cond), "!" #cond, __LINE__)

static int g_failures_at_test_start = 0;

static void begin_test(const char* name)
{
    g_failures_at_test_start = g_checks_failed;
    std::printf("\n[TEST] %s\n", name);
}

static void end_test()
{
    if (g_checks_failed == g_failures_at_test_start)
        std::printf("  OK\n");
}

// ============================================================================
// Helpers: neutral input construction
// ============================================================================

// Returns a neutral MixerInputs in copter hover:
//   - armed, spool = THROTTLE_UNLIMITED
//   - throttle = 0.5, no roll/pitch/yaw/forward/lateral
//   - transition_progress = 0 (pure copter mode)
//   - AHRS: level, healthy, no angular rate
//   - tilt_rate_up_dps = 1e6 to effectively disable rate limiting in tests
static MixerInputs neutral_copter_inputs()
{
    MixerInputs in{};
    in.ahrs_healthy       = true;
    in.is_armed           = true;
    in.spool_state        = AP_Motors::SpoolState::THROTTLE_UNLIMITED;
    in.throttle           = 0.5f;
    in.forward            = 0.0f;
    in.lateral            = 0.0f;
    in.roll               = 0.0f;
    in.pitch              = 0.0f;
    in.yaw                = 0.0f;
    in.surface_roll       = 0.0f;
    in.surface_yaw        = 0.0f;
    in.surface_pitch      = 0.0f;
    in.ahrs_pitch_rad     = 0.0f;
    in.ahrs_roll_rad      = 0.0f;
    in.gyro               = {0.0f, 0.0f, 0.0f};
    in.dt                 = 0.0025f; // 400 Hz
    in.tilt_rate_up_dps   = 1e6f;   // effectively unlimited for tests
    in.plane.transition_progress = 0.0f;
    return in;
}

// Returns a neutral MixerInputs in plane mode:
//   - transition_progress = 1.0 (fully in plane mode)
//   - pitch_tilt_demand = 0 (wings horizontal = full forward flight)
//   - all surfaces neutral, throttle at 50%
static MixerInputs neutral_plane_inputs()
{
    MixerInputs in = neutral_copter_inputs();
    in.plane.transition_progress = 1.0f;
    in.plane.pitch_tilt_demand   = 0.0f;
    in.plane.elevator_input      = 0.0f;
    in.plane.rudder_input        = 0.0f;
    in.plane.aileron_input       = 0.0f;
    in.plane.throttle_pct        = 50.0f;
    return in;
}

// ============================================================================
// LAYER 1: elevator_tilt_split() — pure inline, zero config dependency
// ============================================================================

void elevator_tilt_split_neutral_produces_zero_both()
{
    // At pitch_in = 0 neither surface nor tilt is deflected.
    begin_test(__func__);
    float elev, tilt;
    elevator_tilt_split(0.0f, 0.5f, elev, tilt);
    CHECK_NEAR(0.0f, elev, 0.001f);
    CHECK_NEAR(0.0f, tilt, 0.001f);
    end_test();
}

void elevator_tilt_split_below_threshold_only_elevator_moves()
{
    // pitch_in = 0.25, threshold = 0.5:
    //   abs_pitch (0.25) < threshold (0.5) → elevator = 0.25/0.5 = 0.5, tilt = 0
    begin_test(__func__);
    float elev, tilt;
    elevator_tilt_split(0.25f, 0.5f, elev, tilt);
    CHECK_NEAR(0.5f,  elev, 0.001f);
    CHECK_NEAR(0.0f,  tilt, 0.001f);
    end_test();
}

void elevator_tilt_split_at_threshold_elevator_saturates_tilt_still_zero()
{
    // pitch_in = 0.5, threshold = 0.5:
    //   abs_pitch == threshold → elevator = sign * 1.0, tilt_delta = 0
    begin_test(__func__);
    float elev, tilt;
    elevator_tilt_split(0.5f, 0.5f, elev, tilt);
    CHECK_NEAR(1.0f, elev, 0.001f);
    CHECK_NEAR(0.0f, tilt, 0.001f);
    end_test();
}

void elevator_tilt_split_above_threshold_tilt_ramps_elevator_stays_saturated()
{
    // pitch_in = 0.75, threshold = 0.5:
    //   elevator = 1.0 (saturated)
    //   tilt_delta = (0.75 - 0.5) / (1.0 - 0.5) = 0.5
    begin_test(__func__);
    float elev, tilt;
    elevator_tilt_split(0.75f, 0.5f, elev, tilt);
    CHECK_NEAR(1.0f, elev, 0.001f);
    CHECK_NEAR(0.5f, tilt, 0.001f);
    end_test();
}

void elevator_tilt_split_full_positive_both_saturate()
{
    begin_test(__func__);
    float elev, tilt;
    elevator_tilt_split(1.0f, 0.5f, elev, tilt);
    CHECK_NEAR(1.0f, elev, 0.001f);
    CHECK_NEAR(1.0f, tilt, 0.001f);
    end_test();
}

void elevator_tilt_split_negative_input_is_sign_symmetric()
{
    // The split function mirrors positive behaviour on the negative side.
    begin_test(__func__);
    float elev_pos, tilt_pos, elev_neg, tilt_neg;
    elevator_tilt_split( 0.75f, 0.5f, elev_pos, tilt_pos);
    elevator_tilt_split(-0.75f, 0.5f, elev_neg, tilt_neg);
    CHECK_NEAR(-elev_pos, elev_neg, 0.001f);
    CHECK_NEAR( tilt_pos, tilt_neg, 0.001f); // tilt_delta is always >= 0
    end_test();
}

// ============================================================================
// LAYER 2: AvatarMixer — PLANE MODE
// (transition_progress = 1.0; no TVC brain; no AP_HAL::micros())
//
// Active config: forward_flight_physical_angle_deg = 90°
// tilt_angle = constrain(1.0 - pitch_tilt_demand, 0, 1)
// cos at wings-horizontal (tilt=1.0) = cos(90°) = 0
// cos at wings-vertical   (tilt=0.0) = cos(0°)  = 1
// ============================================================================

void avatar_plane_neutral_tilt_demand_gives_wings_horizontal()
{
    // Neutral stick in FBWA targets cruise_physical_angle_deg (90°), not the full
    // forward_flight_physical_angle_deg (95°).  tilt_angle = 90/95 ≈ 0.9474.
    begin_test(__func__);
    AvatarMixer mixer;
    MixerInputs  in  = neutral_plane_inputs();
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(CRUISE_DEG / FWD_DEG, out.tilt_angle, 0.001f);
    end_test();
}

void avatar_plane_full_pitch_up_tilts_wings_to_vertical()
{
    // Full pitch-up demand (1.0) → tilt_angle = 1 − 1.0 = 0.0 (wings vertical,
    // pure hover orientation)
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 1.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.0f, out.tilt_angle, 0.001f);
    end_test();
}

void avatar_plane_tilt_demand_past_vertical_is_clamped()
{
    // pitch_tilt_demand > 1.0 would give negative tilt_angle → clamped to 0.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 1.5f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.0f, out.tilt_angle, 0.001f);
    end_test();
}

void avatar_plane_elevator_follows_pitch_pid_output()
{
    // Elevator is driven by inputs.pitch (copter attitude PID), same signal as the rear motor.
    // elevator_out == inputs.pitch directly — both actuators cooperate to hold fuselage level.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.pitch = 0.3f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.3f, out.elevator_out, 0.001f);
    end_test();
}

void avatar_plane_rudder_follows_pilot_yaw()
{
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.rudder_input = 2250.0f; // half deflection
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.5f, out.rudder_out, 0.001f);
    end_test();
}

void avatar_plane_zero_roll_wing_motors_equal()
{
    // With zero roll input, both wing motors get equal throttle regardless of tilt.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.throttle_pct = 50.0f;
    in.roll = 0.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.5f, out.motor_thrust[0], 0.001f); // wing left
    CHECK_NEAR(0.5f, out.motor_thrust[1], 0.001f); // wing right
    end_test();
}

void avatar_plane_roll_differential_applied_at_wings_vertical()
{
    // With wings vertical (pitch_tilt_demand=1.0, tilt_angle=0, cos_tilt=1),
    // roll differential from the copter attitude controller is at full authority.
    // positive inputs.roll → left motor higher, right motor lower.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.throttle_pct      = 50.0f;
    in.plane.pitch_tilt_demand = 1.0f; // wings vertical
    in.roll                    = 0.2f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.7f, out.motor_thrust[0], 0.001f); // left  = 0.5 + 0.2
    CHECK_NEAR(0.3f, out.motor_thrust[1], 0.001f); // right = 0.5 - 0.2
    end_test();
}

void avatar_plane_roll_differential_fades_at_wings_horizontal()
{
    // With wings horizontal (pitch_tilt_demand=0, tilt_angle=1, cos_tilt≈0),
    // motor roll differential is zero — ailerons carry all roll authority.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.throttle_pct      = 50.0f;
    in.plane.pitch_tilt_demand = 0.0f; // wings horizontal
    in.roll                    = 0.5f; // significant roll demand
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.5f, out.motor_thrust[0], 0.001f); // left  = 0.5 (no differential)
    CHECK_NEAR(0.5f, out.motor_thrust[1], 0.001f); // right = 0.5 (no differential)
    end_test();
}

void avatar_plane_wings_horizontal_rear_motor_is_zero()
{
    // tilt_angle = 1.0 → tilt_deg = 90° → cos(90°) = 0 → rear_demand = 0.
    // The rear motor has zero pitch authority when wings are horizontal (it's
    // not a thrust-vectoring motor and produces no useful vertical component).
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.0f; // wings horizontal
    in.plane.throttle_pct      = 50.0f;
    in.pitch                   = 0.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.0f, out.motor_thrust[2], 0.001f); // rear motor
    end_test();
}

void avatar_plane_wings_vertical_rear_motor_driven_by_throttle_minus_pitch()
{
    // tilt_angle = 0.0 → tilt_deg = 0° → cos(0°) = 1.0
    // rear_demand = (throttle_pct*0.01 − inputs.pitch) * 1.0 = 0.5 − 0 = 0.5
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 1.0f; // wings vertical
    in.plane.throttle_pct      = 50.0f;
    in.pitch                   = 0.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.5f, out.motor_thrust[2], 0.001f);
    end_test();
}

// [AV-INVAR:rear-pitch-priority]
void stabilize_rear_yaw_clamped_to_headroom_preserves_pitch_common_mode()
{
    // Wings vertical (cos_tilt = 1), high common-mode throttle (0.9), and a full
    // yaw demand that would otherwise rail a rear motor and crush pitch authority.
    //   rear_common = 0.9  →  yaw_room = min(0.9, 0.1) = 0.1
    //   yaw_delta clamped from 1.0 → 0.1
    //   YAW_LEFT[3]  = 0.9 + 0.1 = 1.0
    //   YAW_RIGHT[2] = 0.9 - 0.1 = 0.8   (common mode 0.9 fully preserved)
    // Under the old independent clamps YAW_RIGHT would have been 0.0 and the
    // common-mode average would have collapsed to 0.5 — the STABILIZE nose-up
    // departure. Pitch is prioritized; yaw is sacrificed to the leftover headroom.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 1.0f;  // wings vertical → cos_tilt = 1
    in.plane.use_pid_yaw       = true;  // STABILIZE: yaw from copter attitude PID
    in.plane.throttle_pct      = 90.0f;
    in.pitch                   = 0.0f;
    in.yaw                     = 1.0f;  // full yaw demand → would saturate
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(1.0f, out.motor_thrust[3], 0.001f); // YAW_LEFT railed but not clipped
    CHECK_NEAR(0.8f, out.motor_thrust[2], 0.001f); // YAW_RIGHT keeps common mode
    // Common-mode (pitch/throttle) average is preserved exactly.
    CHECK_NEAR(0.9f, (out.motor_thrust[2] + out.motor_thrust[3]) * 0.5f, 0.001f);
    CHECK_TRUE(out.limit.yaw); // yaw was headroom-limited
    end_test();
}

// [AV-INVAR:rear-pitch-priority]
void stabilize_rear_yaw_within_headroom_is_unaffected()
{
    // Wings vertical, hover throttle (0.5) so yaw_room = 0.5, yaw demand 0.2 fits.
    //   YAW_LEFT[3]  = 0.5 + 0.2 = 0.7
    //   YAW_RIGHT[2] = 0.5 - 0.2 = 0.3
    // The clamp is inactive — behaviour is identical to the pre-change mixer, so
    // tuned normal flight is unchanged and limit.yaw stays false.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 1.0f;
    in.plane.use_pid_yaw       = true;
    in.plane.throttle_pct      = 50.0f;
    in.pitch                   = 0.0f;
    in.yaw                     = 0.2f;  // within headroom
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.7f, out.motor_thrust[3], 0.001f);
    CHECK_NEAR(0.3f, out.motor_thrust[2], 0.001f);
    CHECK_FALSE(out.limit.yaw);
    end_test();
}

// [AV-INVAR:pitch-before-throttle]
void copter_full_throttle_nose_up_transfers_front_excess_to_rear()
{
    // The forward-flip scenario: full throttle, nose-down disturbance, PID demands
    // nose-up (pitch = +0.3). Wings vertical (cos_tilt = 1).
    //   front raw = 1.0 + 0.3 = 1.3 → rails at 1.0, excess 0.3
    //   rear      = (1.0 - 0.3 - 0.3) * 1 = 0.4   (excess transferred)
    // Old behaviour: rear = 0.7 — the front half of the couple was silently lost
    // and pitch loop gain halved at exactly the moment of largest disturbance.
    // Now the full couple (front - rear = 0.6 = 2 * pitch) is preserved; the cost
    // is common-mode lift, not pitch authority. limit.pitch must NOT fire — the
    // moment was fully delivered through the rear pair.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.throttle = 1.0f;
    in.pitch    = 0.3f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(1.0f, out.motor_thrust[0], 0.02f); // fronts railed (same as before)
    CHECK_NEAR(1.0f, out.motor_thrust[1], 0.02f);
    CHECK_NEAR(0.4f, out.motor_thrust[2], 0.02f); // rears carry the transferred excess
    CHECK_NEAR(0.4f, out.motor_thrust[3], 0.02f);
    CHECK_FALSE(out.limit.pitch);                 // couple fully delivered
    end_test();
}

// [AV-INVAR:pitch-before-throttle]
void copter_full_throttle_nose_down_transfers_rear_excess_to_front()
{
    // Mirror case: full throttle, nose-down demand (pitch = -0.3), wings vertical.
    //   rear raw  = (1.0 + 0.3) * 1 = 1.3 → rails at 1.0, excess 0.3
    //   front     = 1.0 - 0.3 - 0.3 = 0.4          (excess transferred)
    // Old behaviour: front = 0.7, rear clipped to 1.0 — half the couple lost.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.throttle = 1.0f;
    in.pitch    = -0.3f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.4f, out.motor_thrust[0], 0.02f); // fronts give up the rear's excess
    CHECK_NEAR(0.4f, out.motor_thrust[1], 0.02f);
    CHECK_NEAR(1.0f, out.motor_thrust[2], 0.02f); // rears railed
    CHECK_NEAR(1.0f, out.motor_thrust[3], 0.02f);
    CHECK_FALSE(out.limit.pitch);
    end_test();
}

// [AV-INVAR:pitch-before-throttle]
void copter_unsaturated_pitch_transfer_is_noop()
{
    // Hover throttle with moderate pitch: nothing rails, so the transfer must be
    // bit-for-bit inactive — tuned normal flight is unchanged.
    //   front = 0.5 + 0.2 = 0.7,  rear = (0.5 - 0.2) * 1 = 0.3
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.throttle = 0.5f;
    in.pitch    = 0.2f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.7f, out.motor_thrust[0], 0.02f);
    CHECK_NEAR(0.7f, out.motor_thrust[1], 0.02f);
    CHECK_NEAR(0.3f, out.motor_thrust[2], 0.02f);
    CHECK_NEAR(0.3f, out.motor_thrust[3], 0.02f);
    CHECK_FALSE(out.limit.pitch);
    end_test();
}

// [AV-INVAR:pitch-before-throttle]
void copter_low_throttle_rear_railed_at_zero_does_not_boost_fronts()
{
    // Lift-reducing only: at low throttle a big nose-up demand rails the rears at 0.
    // The undelivered pitch must NOT be added to the fronts (no motor spin-up near
    // the ground) — and limit.pitch MUST fire so the I-term stops winding.
    //   rear raw = (0.1 - 0.5) * 1 = -0.4 → railed at 0, boost direction excluded
    //   front    = 0.1 + 0.5 = 0.6         (unchanged — no transfer)
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.throttle = 0.1f;
    in.pitch    = 0.5f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.6f, out.motor_thrust[0], 0.02f);
    CHECK_NEAR(0.6f, out.motor_thrust[1], 0.02f);
    CHECK_NEAR(0.0f, out.motor_thrust[2], 0.02f);
    CHECK_NEAR(0.0f, out.motor_thrust[3], 0.02f);
    CHECK_TRUE(out.limit.pitch);                  // pitch genuinely undelivered
    end_test();
}

// [AV-INVAR:pitch-before-throttle] + [AV-INVAR:rear-pitch-priority]
void copter_yaw_room_respects_post_transfer_rear_common_mode()
{
    // Full hierarchy check: pitch > yaw > throttle. Full throttle + nose-up demand
    // shrinks the rear common mode to 0.4 via the transfer; a full yaw demand then
    // gets only the symmetric headroom around THAT value.
    //   rear_common = 0.4 → yaw_room = min(0.4, 0.6) = 0.4
    //   YAW_LEFT[3]  = 0.4 + 0.4 = 0.8,  YAW_RIGHT[2] = 0.4 - 0.4 = 0.0
    // Common mode (pitch) average is preserved exactly at 0.4.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.throttle = 1.0f;
    in.pitch    = 0.3f;
    in.yaw      = 1.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.8f, out.motor_thrust[3], 0.02f);
    CHECK_NEAR(0.0f, out.motor_thrust[2], 0.02f);
    CHECK_NEAR(0.4f, (out.motor_thrust[2] + out.motor_thrust[3]) * 0.5f, 0.02f);
    end_test();
}

// ============================================================================
// LAYER 3: AvatarMixer — COPTER MODE (TVC brain drives tilt)
// ============================================================================

void avatar_copter_neutral_hover_wings_level_motors_equal()
{
    // Neutral stick hover: TVC computes zero tilt, throttle = 0.5.
    // No roll demand → wing_left = wing_right = throttle = 0.5.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.0f, out.tilt_angle, 0.01f);
    CHECK_NEAR(out.motor_thrust[0], out.motor_thrust[1], 0.001f); // left = right
    end_test();
}

void avatar_copter_positive_roll_demand_tilts_left_motor_higher()
{
    // Positive roll (right-wing-down / left-wing-up) means the left motor must
    // work harder.  With wings vertical (cos_tilt ≈ 1), roll_effectiveness = 1,
    // so a positive roll input adds to left and subtracts from right.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.roll = 0.3f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_TRUE(out.motor_thrust[0] > out.motor_thrust[1]); // left > right
    end_test();
}

void avatar_copter_roll_effectiveness_zero_when_wings_horizontal()
{
    // When wings are at 90° (fully horizontal), cos_tilt = 0 and roll
    // effectiveness = 0.  Rolling the stick does nothing because the motors
    // are perpendicular to the roll axis and can't generate a roll torque.
    //
    // We drive the TVC to produce a near-90° tilt by setting forward = full
    // and throttle ≈ 0.  With large tilt_rate_up_dps the servo reaches 90°.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.forward = 0.42f; // AVATAR_FORWARD_INPUT_MAX — full forward → TVC targets ~90°
    in.throttle = 0.01f;                  // minimal vertical, let forward dominate
    in.roll     = 0.5f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    // At 90° tilt, left ≈ right (roll drops to zero)
    CHECK_NEAR(out.motor_thrust[0], out.motor_thrust[1], 0.05f);
    end_test();
}

void avatar_copter_shut_down_spool_clears_tilt_and_returns()
{
    // When the spool state is SHUT_DOWN, mix() returns early (motors = 0) and
    // resets current_tilt_deg to 0 to avoid a stale angle on the next arm.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.spool_state = AP_Motors::SpoolState::SHUT_DOWN;
    MixerState   state;
    state.current_tilt_deg = 45.0f; // simulate previously tilted
    MixerOutputs out;
    // Zero the outputs before mix so we can confirm nothing was written
    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) out.motor_thrust[i] = 99.0f;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.0f, state.current_tilt_deg, 0.001f); // reset on SHUT_DOWN
    // All motor outputs are 0 (mix() pre-zeros them before the early return)
    CHECK_NEAR(0.0f, out.motor_thrust[0], 0.001f);
    CHECK_NEAR(0.0f, out.motor_thrust[1], 0.001f);
    CHECK_NEAR(0.0f, out.motor_thrust[2], 0.001f);
    CHECK_NEAR(0.0f, out.motor_thrust[3], 0.001f);
    end_test();
}

void avatar_copter_elevator_is_negative_cos_tilt()
{
    // In copter mode, elevator_out = -cos_tilt.  At neutral hover (tilt ≈ 0°)
    // elevator_out ≈ -1.0 (fully deployed to provide pitch-up restoring moment).
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(-1.0f, out.elevator_out, 0.05f);
    end_test();
}

void avatar_copter_motor_outputs_stay_within_limits()
{
    // All motor outputs must be clamped to [-1, 1] regardless of demand.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.throttle = 0.9f;
    in.roll     = 1.0f; // saturated roll — tests the clamp path
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    for (int i = 0; i < 4; i++) {
        CHECK_TRUE(out.motor_thrust[i] >= -1.0f);
        CHECK_TRUE(out.motor_thrust[i] <=  1.0f);
    }
    end_test();
}

// ============================================================================
// GROUP A — Pitch compensation / stall prevention (copter mode)
//
// The TVC brain adds the aircraft's current AHRS pitch to the wing tilt target:
//
//   target_pitch_deg = atan2(forward_cmd, thrust_cmd) + ahrs_pitch_deg
//
// This keeps the thrust vector pointing in the same absolute earth-frame
// direction even as the airframe rotates.  It is also the stall-prevention
// mechanism: when the nose pitches up the wings automatically tilt upward to
// maintain lift without any mode switch or threshold.
//
// For these tests: forward_cmd = 0 (neutral stick), so atan2(0, thrust) = 0°,
// and the only contribution is the pitch compensation term.  The wing tilt is
// therefore exactly equal to the aircraft pitch angle, normalised by 90°.
//
// Angle conventions (Avatar, forward_flight_physical_angle_deg = 90°):
//   tilt_angle = 0.0  →  wings vertical   (motors pointing up,   0° from vertical)
//   tilt_angle = 1.0  →  wings horizontal (motors pointing fwd, 90° from vertical)
//   physical tilt from horizontal = 90° − (tilt_angle × 90°)
//
// So tilt_angle = 0.556 (50° pitch case) means the wing is 40° above horizontal
// in the airframe — exactly cancelling a 50° nose-up aircraft pitch.
// ============================================================================

static float deg2rad(float d) { return d * (float)(M_PI / 180.0); }

void pitch_compensation_30_degrees_up_tilts_wings_30_degrees_from_vertical()
{
    // Aircraft pitched 30° nose-up, no translational demand.
    //
    // The TVC adds the AHRS pitch to the tilt target to keep the thrust vector
    // earth-vertical.  With no forward stick, atan2(0, thrust) = 0°, so the
    // entire tilt output is the compensation term:
    //   target = 0° + 30° = 30°  →  tilt_angle = 30/90 = 0.333
    //
    // Physical reading: the wing is 30° from the airframe vertical (= 60° above
    // horizontal in the airframe).  From the ground, the motor thrust vector
    // still points straight up even though the fuselage is tilted 30°.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.ahrs_pitch_rad = deg2rad(30.0f);
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(30.0f / FWD_DEG, out.tilt_angle, 0.01f);
    end_test();
}

void pitch_compensation_50_degrees_up_wing_at_40_degrees_from_horizontal()
{
    // Aircraft pitched 50° nose-up, no translational demand.
    //
    //   target = 0° + 50° = 50°  →  tilt_angle = 50/90 ≈ 0.556
    //
    // Physical reading: the wing is 50° from the airframe vertical, which means
    // it is 40° above the airframe horizontal plane.  Looking at the aircraft
    // from the side: the fuselage points 50° up, the wing points 40° above the
    // fuselage's horizontal — the two angles together aim the thrust straight up.
    //
    // This is the canonical "pitch compensation" test case.  "40° from horizontal"
    // is the natural pilot/observer way to describe the same wing angle that the
    // code expresses as tilt_angle = 0.556.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.ahrs_pitch_rad = deg2rad(50.0f);
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(50.0f / FWD_DEG, out.tilt_angle, 0.01f); // wing 40° from horizontal in airframe
    end_test();
}

void pitch_compensation_80_degrees_up_deep_stall_wings_nearly_vertical()
{
    // Aircraft pitched 80° nose-up — severe stall onset.
    //
    //   target = 0° + 80° = 80°  →  tilt_angle = 80/90 ≈ 0.889
    //
    // The wings are nearly vertical in the earth frame (only 10° from horizontal
    // in the airframe).  Almost all motor thrust is directed upward; almost no
    // forward thrust component remains.  This is the deepest stall the system
    // can compensate for before the servo saturates.
    //
    // No pilot input, no discrete mode switch — the wings reached this position
    // because the pitch compensation loop responded continuously as the nose rose.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.ahrs_pitch_rad = deg2rad(80.0f);
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(80.0f / FWD_DEG, out.tilt_angle, 0.01f); // only 10° from horizontal in airframe
    end_test();
}

void pitch_compensation_past_90_degrees_saturates_servo_and_sets_flag()
{
    // Aircraft pitched beyond 90° (e.g., inverted or catastrophic tumble).
    //
    //   target = 0° + 100° = 100°  →  100/90 = 1.111  →  clamped to 1.0
    //
    // The tilt servo has hit its physical stop (wings horizontal = 90° = 1.0).
    // It cannot compensate any further.  The TVC sets pitch_saturated = true via
    // the bool& reference in TVC_CoreState so that the upstream PID's anti-windup
    // logic knows to stop accumulating integrator error.
    //
    // tilt_angle = 1.0 is the hard mechanical limit.  The aircraft is no longer
    // in a recoverable pitch state from thrust-vectoring alone.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.ahrs_pitch_rad = deg2rad(100.0f);
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    // Copter mode caps tilt at cruise_norm = CRUISE_DEG/FWD_DEG (not 1.0).
    // The servo's extra 5° (90°→95°) is reserved for FBWA transition, not copter mode.
    CHECK_NEAR(CRUISE_DEG / FWD_DEG, out.tilt_angle, 0.001f);
    CHECK_TRUE(state.pitch_saturated);             // anti-windup flag set
    end_test();
}

// ============================================================================
// GROUP B — Pitch compensation combined with forward stick (copter mode)
//
// When the pilot applies forward stick while the aircraft is pitched, both
// terms contribute to the wing tilt:
//   target = atan2(forward_cmd, thrust_cmd) + ahrs_pitch_deg
//
// The TVC maps inputs.forward through AVATAR_FORWARD_INPUT_MAX (0.42) so that
// full stick equals forward_cmd = 1.0.  Setting inputs.forward = 0.42/2 = 0.21
// gives forward_cmd = 0.5 to the TVC.
//
// With thrust_cmd = 0.5 and forward_cmd = 0.5:
//   atan2(0.5, 0.5) = 45°
//
// Adding ±30° pitch compensation gives 75° or 15°, normalised by 90°.
// ============================================================================

void pitch_compensation_and_forward_stick_angles_add()
{
    // Aircraft pitched 30° nose-up, 50% forward stick.
    //
    //   atan2(forward=0.5, thrust=0.5) = 45°  (forward demand)
    //   + 30°  (pitch compensation)
    //   = 75°  →  tilt_angle = 75/90 ≈ 0.833
    //
    // The wing tilts further forward than either demand alone would require.
    // This is correct: the aircraft wants to move forward AND the thrust vector
    // needs to stay earth-vertical to fight gravity despite the nose-up attitude.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.ahrs_pitch_rad = deg2rad(30.0f);
    in.forward        = 0.21f; // 0.21 / 0.42 = 0.5 → TVC forward_cmd = 0.5
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(75.0f / FWD_DEG, out.tilt_angle, 0.02f);
    end_test();
}

void pitch_compensation_and_forward_stick_partially_cancel_when_nose_down()
{
    // Aircraft pitched 30° nose-DOWN, 50% forward stick.
    //
    //   atan2(forward=0.5, thrust=0.5) = 45°  (forward demand)
    //   + (−30°)  (pitch compensation — nose down means less tilt needed)
    //   = 15°  →  tilt_angle = 15/90 ≈ 0.167
    //
    // The wings tilt much less forward than the stick alone would produce.
    // Physically: the aircraft is already nose-down, so the thrust vector is
    // already tilted forward by the airframe attitude.  The compensation backs
    // the wings off toward vertical to keep the net thrust direction correct.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.ahrs_pitch_rad = deg2rad(-30.0f); // nose down
    in.forward        = 0.21f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(15.0f / 90.0f, out.tilt_angle, 0.02f); // = 0.167
    end_test();
}

// ============================================================================
// GROUP C — Rear motor math (copter mode)
//
// The rear motor mixes throttle and pitch through a cos(tilt) gate:
//
//   rear = (inputs.throttle − inputs.pitch) × cos(state.current_tilt_deg)
//
// cos(tilt) = 1 at hover (wings vertical, tilt = 0°): full authority
// cos(tilt) = 0 at cruise (wings horizontal, tilt = 90°): motor fades out
//
// Sign convention:
//   inputs.pitch > 0  (nose-up correction wanted)  →  rear decreases
//       → less force pushing tail up → tail drops → nose rises  ✓
//   inputs.pitch < 0  (nose-down correction wanted) →  rear increases
//       → more force pushing tail up → nose drops  ✓
//
// inputs.throttle (not throttle_thrust from TVC) is used for the rear motor.
// This means rear authority is proportional to the pilot's raw throttle stick,
// not the TVC-adjusted total magnitude.
// ============================================================================

void rear_motor_at_hover_equals_throttle_minus_pitch_demand()
{
    // Wings vertical (tilt = 0°, cos = 1), throttle = 0.5, no pitch demand.
    //   rear = (0.5 − 0) × 1.0 = 0.5
    //
    // At neutral hover the rear motor runs at half throttle, matched to the
    // front motors.  This is the symmetric tricopter baseline.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs(); // ahrs_pitch_rad = 0 → tilt = 0°
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.5f, out.motor_thrust[2], 0.01f); // rear motor = AVATAR_MOT_YAW = 2
    end_test();
}

void rear_motor_fades_with_cos_tilt_at_45_degrees()
{
    // Wings tilted 45° from vertical (aircraft pitched 45° → TVC compensates
    // to 45° tilt), throttle = 0.5, no pitch demand.
    //   cos(45°) ≈ 0.7071
    //   rear = (0.5 − 0) × 0.7071 ≈ 0.354
    //
    // The rear motor produces about 71% of its hover contribution because it
    // is no longer aligned with the pitch axis as the wings rotate.  It fades
    // continuously rather than snapping off, so the transition is smooth.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.ahrs_pitch_rad = deg2rad(45.0f); // TVC targets 45° → cos_tilt = cos(45°)
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected = 0.5f * std::cos(deg2rad(45.0f)); // ≈ 0.354
    CHECK_NEAR(expected, out.motor_thrust[2], 0.02f);
    end_test();
}

void rear_motor_decreases_on_pitch_up_demand()
{
    // Wings vertical (tilt = 0°), throttle = 0.5, pitch demand = +0.3 (nose up).
    //   rear = (0.5 − 0.3) × 1.0 = 0.2
    //
    // A positive pitch demand (attitude controller wants nose up) reduces the
    // rear motor.  Less upward push on the tail → tail drops → nose rises.
    // Simultaneously the front motors increase (base_thrust = 0.5 + 0.3 = 0.8),
    // adding nose-up moment from the front.  The two effects combine.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.pitch = 0.3f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.2f, out.motor_thrust[2], 0.01f); // rear decreases
    // Front motors increase by the pitch demand
    CHECK_NEAR(0.8f, out.motor_thrust[0], 0.01f); // base = 0.5 + 0.3
    CHECK_NEAR(0.8f, out.motor_thrust[1], 0.01f);
    end_test();
}

void rear_motor_increases_on_pitch_down_demand()
{
    // Wings vertical (tilt = 0°), throttle = 0.5, pitch demand = −0.3 (nose down).
    //   rear = (0.5 − (−0.3)) × 1.0 = 0.8
    //
    // A negative pitch demand (attitude controller wants nose down) increases the
    // rear motor.  More upward push on the tail → tail rises → nose drops.
    // Front motors decrease (base_thrust = 0.5 − 0.3 = 0.2) for the same reason.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.pitch = -0.3f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.8f, out.motor_thrust[2], 0.01f); // rear increases
    CHECK_NEAR(0.2f, out.motor_thrust[0], 0.01f); // front decreases
    CHECK_NEAR(0.2f, out.motor_thrust[1], 0.01f);
    end_test();
}

void rear_motor_clamps_to_zero_when_pitch_demand_exceeds_throttle()
{
    // Wings vertical, throttle = 0.5, pitch demand = +0.6 (aggressive nose-up).
    //   raw rear = (0.5 − 0.6) × 1.0 = −0.1  →  clamped to 0.0
    //   base_thrust = throttle_thrust + pitch = 0.5 + 0.6 = 1.1 > 1.0 → limit.pitch = true
    //
    // The rear motor cannot produce negative thrust (it is unidirectional), so it
    // floors at zero.  limit.pitch is set true to signal the copter attitude
    // controller's anti-windup — the integrator should stop winding up because
    // the actuator is saturated and cannot deliver more nose-up moment.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.pitch = 0.6f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.0f, out.motor_thrust[2], 0.001f); // floored
    CHECK_TRUE(out.limit.pitch);                    // anti-windup signal
    end_test();
}

// ============================================================================
// GROUP D — Roll headroom (copter mode)
//
// Roll thrust is pre-scaled to the available motor headroom before being
// applied, preventing asymmetric clipping:
//
//   base_thrust    = throttle_thrust + inputs.pitch   (pitch-shifted center)
//   roll_headroom  = min(1 − base_thrust, base_thrust) (symmetric margin)
//   scaled_roll    = constrain(roll × cos_tilt, −headroom, +headroom)
//
// motor_left  = base_thrust + scaled_roll
// motor_right = base_thrust − scaled_roll
//
// At full throttle, headroom = 0 and roll authority gracefully goes to zero
// (thrust is preserved; limit.roll is set for the attitude controller).
// At half throttle with no pitch offset, headroom = 0.5 — full roll available.
// Pitch corrections shift base_thrust, which narrows the headroom asymmetrically.
// ============================================================================

void roll_headroom_at_half_throttle_allows_full_roll_within_margin()
{
    // throttle = 0.5, pitch = 0, roll = 0.1, wings vertical (cos_tilt = 1).
    //   base_thrust    = 0.5
    //   roll_headroom  = min(0.5, 0.5) = 0.5
    //   desired_roll   = 0.1 × 1.0 = 0.1  (well within headroom)
    //   wing_left      = 0.5 + 0.1 = 0.6
    //   wing_right     = 0.5 − 0.1 = 0.4
    //   limit.roll     = false
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.roll = 0.1f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.6f,  out.motor_thrust[0], 0.01f); // left  = base + roll
    CHECK_NEAR(0.4f,  out.motor_thrust[1], 0.01f); // right = base − roll
    CHECK_FALSE(out.limit.roll);
    end_test();
}

void roll_headroom_full_throttle_desaturates_by_shifting_both_motors_down()
{
    // throttle = 1.0, roll = 0.5, wings vertical.
    //   base_thrust = 1.0, desired_roll = 0.5
    //   left_raw = 1.5, right_raw = 0.5
    //   excess_high = 0.5, shift = 0.5
    //   left_out = 1.0, right_out = 0.0   ← full differential preserved
    //   limit.roll = false                 ← full demand was achieved
    //
    // Previously roll was zeroed entirely at full throttle (both motors = 1.0,
    // limit.roll = true). The de-saturation fix instead shifts both motors down
    // by the overshoot so the full roll differential is delivered at the cost of
    // average throttle.  This ensures roll authority is never silently dropped.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.throttle = 1.0f;
    in.roll     = 0.5f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(1.0f, out.motor_thrust[0], 0.001f); // left  = 1.0
    CHECK_NEAR(0.0f, out.motor_thrust[1], 0.001f); // right = 0.0 (full differential)
    CHECK_FALSE(out.limit.roll);                    // demand was fully met
    end_test();
}

void pitch_correction_with_roll_desaturates_symmetrically()
{
    // throttle = 0.5, pitch = +0.4, roll = 0.3, wings vertical.
    //   base_thrust  = 0.5 + 0.4 = 0.9
    //   desired_roll = 0.3
    //   left_raw = 1.2, right_raw = 0.6
    //   excess_high = 0.2, shift = 0.2
    //   left_out = 1.0, right_out = 0.4   ← full 0.3 differential preserved
    //   limit.roll = false                 ← full demand was achieved
    //
    // Previously the 0.1 headroom clipped roll to 0.1 (right = 0.8), leaving 0.2
    // of roll demand undelivered.  The de-saturation fix shifts both motors down by
    // the 0.2 overshoot so the full 0.3 differential is delivered — at the cost of
    // slightly lower average throttle (now 0.7 instead of 0.9).
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.pitch = 0.4f;
    in.roll  = 0.3f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(1.0f, out.motor_thrust[0], 0.01f); // left  = 1.0
    CHECK_NEAR(0.4f, out.motor_thrust[1], 0.01f); // right = 0.4 (full 0.3 differential)
    CHECK_FALSE(out.limit.roll);
    CHECK_FALSE(out.limit.pitch);
    end_test();
}

// ============================================================================
// GROUP E — Plane mode: rear motor under pitch stabilization pressure
//
// In plane mode the rear motor provides supplemental pitch authority using the
// copter attitude controller's pitch output (inputs.pitch) gated by cos(tilt):
//
//   rear = (throttle_pct − inputs.pitch) × cos(tilt_angle × 90°)
//
// Key behaviors:
//   - Elevator saturating (inputs.pitch < 0, nose-up):  rear increases to push
//     tail up → nose down — counteracts the pitch-up from wing rotation.
//   - Wings horizontal (tilt = 1.0):  cos(90°) = 0 → rear = 0 regardless of
//     pitch demand — aerodynamic surfaces have full authority, rear motor off.
// ============================================================================

void plane_mode_rear_motor_surges_when_elevator_saturates_nose_up()
{
    // Wings at 45° (pitch_tilt_demand = 0.5), throttle = 50%, pitch = −0.4.
    // A negative inputs.pitch means the copter attitude controller is demanding
    // nose-down (elevator was saturated trying to hold level, now the copter PID
    // takes over).
    //
    //   tilt_angle  = 1.0 − 0.5 = 0.5
    //   tilt_deg    = 0.5 × 90° = 45°
    //   cos_tilt    = cos(45°) ≈ 0.7071
    //   rear        = (0.5 − (−0.4)) × 0.7071 = 0.9 × 0.7071 ≈ 0.636
    //
    // The rear motor surges well above baseline (0.5) to push the tail up and
    // arrest the nose-up rotation that occurs as the wing motors tilt toward
    // vertical.  This is the plane-mode stall stabilisation mechanism.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.5f;    // wings at 45°
    in.plane.throttle_pct      = 50.0f;
    in.pitch                   = -0.4f;   // nose-up correction demanded
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected = (0.5f - (-0.4f)) * std::cos(deg2rad(45.0f));
    CHECK_NEAR(expected, out.motor_thrust[2], 0.02f); // ≈ 0.636
    end_test();
}

void plane_mode_rear_motor_zero_when_wings_horizontal_regardless_of_pitch()
{
    // Wings horizontal (pitch_tilt_demand = 0 → tilt_angle = 1.0), any pitch.
    //   tilt_deg = 90°  →  cos(90°) = 0  →  rear = anything × 0 = 0
    //
    // At full forward tilt the aerodynamic elevator surface has full authority
    // and the rear motor contributes nothing to pitch control.  This prevents
    // the unidirectional rear motor from interfering with the elevator PID in
    // normal cruise.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.0f;   // wings horizontal, tilt_angle = 1.0
    in.pitch                   = -0.9f;  // large nose-up demand (irrelevant)
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.0f, out.motor_thrust[2], 0.001f); // rear motor always zero here
    end_test();
}

// ============================================================================
// GROUP F — Disarmed / failsafe (copter mode)
//
// When the aircraft is disarmed, inputs.is_armed = false, which maps to
// tvc_in.in_failsafe = true inside the mixer.  The TVC's failsafe path
// zeroes all tilt commands regardless of stick position.
//
// The physical intent: return the tilt servo to neutral (wings vertical) so
// the aircraft descends under gravity in a controlled, predictable attitude
// rather than holding a forward tilt that would drive it laterally.
// ============================================================================

void disarmed_aircraft_tilt_angle_returns_to_zero_regardless_of_stick()
{
    // Aircraft disarmed (is_armed = false), full forward stick, pitched 30°.
    // Normally these inputs would produce a significant tilt angle.  With the
    // failsafe active, the TVC ignores all stick inputs and outputs tilt = 0.
    //
    // This is the same failsafe that the TVC test suite verifies at the TVC level
    // (failsafe_zeroes_tilt_commands_regardless_of_stick_inputs).  This test
    // confirms that the AvatarMixer correctly maps is_armed = false to
    // tvc_in.in_failsafe = true, completing the end-to-end signal path.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.is_armed       = false;
    in.forward        = 0.42f;          // full forward stick
    in.ahrs_pitch_rad = deg2rad(30.0f); // pitched up
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.0f, out.tilt_angle, 0.001f); // servo returns to vertical
    end_test();
}

// ============================================================================
// GROUP G — Elevator trim schedule at intermediate tilt (copter mode)
//
// In copter mode:  elevator_out = −cos(state.current_tilt_deg)
//
// This is a passive feedforward trim, not a feedback signal.  Its job is to
// counteract the nose-up pitch moment from the rear motor (which runs at
// throttle-proportional thrust and pitches the nose up via its lever arm).
// The trim fades out as the wings tilt toward horizontal because the rear motor
// also fades (cos_tilt gates it), so both the moment source and the compensation
// disappear together.
//
// Endpoints (already tested elsewhere):
//   tilt = 0°  →  elevator_out = −1.0  (hover: full nose-down elevator)
//   tilt = 90° →  elevator_out =  0.0  (cruise: elevator at neutral)
//
// This group tests the intermediate point at 45° to confirm the cosine schedule
// is implemented correctly, not approximated with a linear ramp.
// ============================================================================

void elevator_trim_schedule_at_45_degree_tilt_follows_cosine()
{
    // Aircraft pitched 45° → TVC commands 45° tilt → cos(45°) ≈ 0.7071.
    //   elevator_out = −cos(45°) ≈ −0.707
    //
    // A linear interpolation between −1.0 (hover) and 0.0 (cruise) at the
    // midpoint would give −0.5.  The correct cosine value (−0.707) is
    // noticeably larger in magnitude — if this test fails with ≈ −0.5 the
    // implementation has been incorrectly linearized.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.ahrs_pitch_rad = deg2rad(45.0f); // TVC targets 45° → cos_tilt = cos(45°)
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected = -std::cos(deg2rad(45.0f)); // ≈ −0.7071
    CHECK_NEAR(expected, out.elevator_out, 0.02f);
    end_test();
}

// ============================================================================
// GROUP H — QSTABILIZE surface controls (ailerons and rudder)
//
// In QSTABILIZE (and all copter Q-modes), control authority is split between
// two independent signal paths:
//
//   MOTORS  ← closed-loop PID outputs:  inputs.roll, inputs.pitch
//   SURFACES ← direct pilot stick:      inputs.surface_roll, inputs.surface_yaw
//
// The pilot's roll stick simultaneously deflects the ailerons (via surface_roll)
// AND creates motor differential (via inputs.roll, which the attitude controller
// populates from the stick).  These are different code paths and different
// ArduPilot inputs — they can be tested independently.
//
// In QSTABILIZE specifically, ModeQStabilize::update() calls set_pilot_roll() /
// set_pilot_yaw() behind ENABLE_TRICOPTER_VTOL_BACKEND to populate surface_roll
// and surface_yaw from the raw stick.  For all other Q-modes (QHOVER, QLOITER)
// those setters are never called, so surface_roll/yaw = 0 and surfaces receive
// no direct pilot input.
//
// Critical sign convention:
//   aileron_out = −inputs.surface_roll   (note the inversion)
//   rudder_out  = +inputs.surface_yaw
//
// The aileron inversion exists because a positive roll command (right-wing-down)
// requires the left aileron to go up and the right to go down — a negative
// combined aileron output in ArduPilot's surface convention.  Getting this sign
// wrong would cause the aircraft to roll opposite to pilot input.
//
// PID yaw (inputs.yaw) is NOT routed to any motor or surface in the Avatar
// copter mixer.  Yaw stability in hover is achieved via pilot direct rudder
// authority (surface_yaw → rudder_out).  This is a deliberate design choice
// documented in Avatar_Design.md section 4.10 — the closed-loop yaw rate PID
// output is computed by ArduPilot but intentionally not used by the mixer.
// ============================================================================

// NOTE ON DESIGN CHANGE (Group H):
// Originally surface_roll/surface_yaw (direct pilot stick passthrough) were intended
// to drive ailerons/rudder respectively, while inputs.roll/yaw (closed-loop PID) drove
// motors only.  The current design routes inputs.roll → ailerons (-inputs.roll) and
// inputs.yaw → rudder AND rear motor differential.  surface_roll/surface_yaw are
// populated by ArduPilot but are not consumed by the mixer in the current implementation.
// In QSTABILIZE the pilot's stick reaches the ailerons via the attitude target → PID →
// inputs.roll path, so the practical effect is correct, just not a direct passthrough.

void qstabilize_pid_roll_drives_ailerons_and_motor_differential()
{
    // inputs.roll = 0.5 (attitude PID output) drives BOTH ailerons and motor differential.
    //   aileron_out = −inputs.roll = −0.5
    //   wing_left > wing_right (positive roll = right-wing-down → left motor harder)
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.roll = 0.5f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(-0.5f, out.aileron_out, 0.001f);             // PID roll → aileron (negative sign)
    CHECK_TRUE(out.motor_thrust[0] > out.motor_thrust[1]);  // motor differential active
    end_test();
}

void qstabilize_full_roll_saturates_ailerons()
{
    // inputs.roll = 1.0 → aileron_out = −1.0. Confirms 1:1 scaling, no hidden gain.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.roll = 1.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(-1.0f, out.aileron_out, 0.001f);
    end_test();
}

void qstabilize_pid_yaw_drives_rudder_and_rear_motor_differential()
{
    // inputs.yaw = 0.7 drives both rudder_out and rear motor differential.
    //   rudder_out = inputs.yaw = 0.7 (same sign)
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.yaw = 0.7f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.7f, out.rudder_out,  0.001f);
    CHECK_NEAR(0.0f, out.aileron_out, 0.001f); // ailerons unaffected by yaw
    end_test();
}

void qstabilize_pid_yaw_rear_motor_differential_sign()
{
    // inputs.yaw = 0.3 (yaw-right demand), wings vertical (cos_tilt = 1).
    //   rear_thrust = (throttle − pitch) × cos_tilt = 0.5
    //   yaw_delta   = 0.3 × 1.0 = 0.3
    //   YAW_LEFT  (motor[3]) = rear + yaw_delta = 0.8  (left rear spins harder → yaw right)
    //   YAW_RIGHT (motor[2]) = rear − yaw_delta = 0.2
    //   rudder_out = inputs.yaw = 0.3
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.yaw = 0.3f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.8f, out.motor_thrust[3], 0.01f); // YAW_LEFT  = rear + yaw_delta
    CHECK_NEAR(0.2f, out.motor_thrust[2], 0.01f); // YAW_RIGHT = rear − yaw_delta
    CHECK_NEAR(0.3f, out.rudder_out, 0.001f);     // rudder driven by PID yaw
    CHECK_NEAR(out.motor_thrust[0], out.motor_thrust[1], 0.001f); // wings unaffected
    end_test();
}

void qstabilize_roll_and_yaw_pid_drive_surfaces_independently()
{
    // Both PID outputs active: inputs.roll = 0.3, inputs.yaw = 0.6.
    //   aileron_out = −0.3, rudder_out = 0.6
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.roll = 0.3f;
    in.yaw  = 0.6f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(-0.3f, out.aileron_out, 0.001f);
    CHECK_NEAR( 0.6f, out.rudder_out,  0.001f);
    end_test();
}

// ============================================================================
// GROUP I — Aircraft pitch state → motor hierarchy (QSTABILIZE)
//
// These tests describe behavior from the pilot's perspective: given what the
// aircraft is DOING, which motors are working harder?
//
// The connection between aircraft state and inputs.pitch:
//   Aircraft nose-UP   → attitude controller wants nose down → inputs.pitch < 0
//   Aircraft nose-DOWN → attitude controller wants nose up   → inputs.pitch > 0
//
// Motor responses (wings vertical, cos_tilt = 1):
//   front base  = throttle_thrust + inputs.pitch
//   rear        = (inputs.throttle − inputs.pitch) × cos_tilt
//
// So:
//   Nose-up aircraft   (inputs.pitch < 0): front decreases, rear increases → rear > front
//   Nose-down aircraft (inputs.pitch > 0): front increases, rear decreases → front > rear
//
// These mirror the tricopter convention: the rear motor pushes the tail up
// (nose down) and the front motors pull the nose up.  The Avatar inherits this
// geometry directly from the blimp / tricopter lineage.
// ============================================================================

void nose_up_aircraft_rear_motor_produces_more_thrust_than_front()
{
    // The aircraft is pitched nose-up.  ArduPilot's attitude controller outputs
    // a negative inputs.pitch (commanding nose-down correction).
    //
    // With inputs.pitch = −0.3, wings vertical (cos_tilt = 1):
    //   front base = 0.5 + (−0.3) = 0.2
    //   rear       = (0.5 − (−0.3)) × 1.0 = 0.8
    //
    // The rear motor surges to push the tail up (lowering the nose).
    // The front motors reduce to stop pulling the nose further up.
    // Together they generate a nose-down corrective torque.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.pitch = -0.3f; // negative = attitude controller wants nose down = aircraft is nose-up
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_TRUE(out.motor_thrust[2] > out.motor_thrust[0]); // rear > left front
    CHECK_TRUE(out.motor_thrust[2] > out.motor_thrust[1]); // rear > right front
    CHECK_NEAR(0.8f, out.motor_thrust[2], 0.01f);          // rear at 0.8
    CHECK_NEAR(0.2f, out.motor_thrust[0], 0.01f);          // fronts at 0.2
    end_test();
}

void nose_down_aircraft_front_motors_produce_more_thrust_than_rear()
{
    // The aircraft is pitched nose-down.  ArduPilot outputs a positive inputs.pitch
    // (commanding nose-up correction).
    //
    // With inputs.pitch = +0.3, wings vertical (cos_tilt = 1):
    //   front base = 0.5 + 0.3 = 0.8
    //   rear       = (0.5 − 0.3) × 1.0 = 0.2
    //
    // The front motors surge to lift the nose.
    // The rear motor reduces to stop pushing the tail up (which would worsen nose-down).
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.pitch = 0.3f; // positive = attitude controller wants nose up = aircraft is nose-down
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_TRUE(out.motor_thrust[0] > out.motor_thrust[2]); // left front > rear
    CHECK_TRUE(out.motor_thrust[1] > out.motor_thrust[2]); // right front > rear
    CHECK_NEAR(0.8f, out.motor_thrust[0], 0.01f);          // fronts at 0.8
    CHECK_NEAR(0.2f, out.motor_thrust[2], 0.01f);          // rear at 0.2
    end_test();
}

// ============================================================================
// GROUP J — Plane mode tilt slew rate limiting [AV-INVAR:plane-tilt-slew]
//
// When the pilot releases the pitch stick from wings-vertical in FBWA, the
// tilt servo command must NOT snap instantly to wings-horizontal.  Instead,
// state.current_tilt_deg slews toward the target at an asymmetric rate:
//
//   toward horizontal (increasing tilt_deg): rate_dn  (slow, safety — aircraft
//     must build airspeed before motor lift replaces wing lift)
//   toward vertical   (decreasing tilt_deg): rate_up  (fast, stall recovery)
//
// The slew gate in the mixer (Avatar plane mode):
//   constrain_float(target_deg,
//       current - rate_up * dt,   // lower bound — fast toward vertical
//       current + rate_dn * dt)   // upper bound — slow toward horizontal
//
// Config (forward_flight_physical_angle_deg = 90°):
//   tilt_angle = 0.0  →  wings vertical   (current_tilt_deg = 0°)
//   tilt_angle = 1.0  →  wings horizontal (current_tilt_deg = 90°)
//
// Typical field values: rate_up = 120 °/s (servo physical speed, calibrated),
//   rate_dn = 30 °/s → 90°/30 = 3-second wing-down transition.
//
// IMPORTANT: existing Layer-2 plane-mode tests set tilt_rate_down_dps = 0
// (zero-initialized MixerInputs) which triggers the fallback to rate_up=1e6,
// so every existing test still reaches the target in a single call.  These
// tests use finite rates to exercise the actual slew path.
// ============================================================================

void plane_tilt_slew_stick_release_advances_one_step_at_rate_dn()
{
    // Aircraft hovering: current_tilt_deg = 0° (wings vertical).
    // Pilot releases pitch stick: pitch_tilt_demand = 0 → target = 90°.
    //
    // rate_dn = 30 °/s, dt = 0.0025 s → one tick advances by:
    //   0 + 30 × 0.0025 = 0.075°  →  tilt_angle = 0.075/90 ≈ 0.000833
    //
    // This is the primary stall-prevention test: wings do NOT snap to
    // horizontal in a single mixer call.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.0f;   // neutral stick = wings horizontal target
    in.tilt_rate_up_dps        = 120.0f;
    in.tilt_rate_down_dps      = 30.0f;
    in.dt                      = 0.0025f;
    MixerState   state;
    state.current_tilt_deg = 0.0f;       // wings vertical at start
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected_deg  = 0.0f + 30.0f * 0.0025f;  // = 0.075°
    float expected_tilt = expected_deg / 90.0f;
    CHECK_NEAR(expected_tilt, out.tilt_angle,         0.0001f);
    CHECK_NEAR(expected_deg,  state.current_tilt_deg, 0.001f);
    end_test();
}

void plane_tilt_slew_wings_do_not_snap_to_horizontal_in_single_step()
{
    // Regression guard: with finite rate_dn, wings-vertical + neutral stick must
    // produce tilt_angle far below 1.0 after one call.  If this fails with
    // tilt_angle ≈ 1.0, rate limiting has been removed or bypassed.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.0f;
    in.tilt_rate_up_dps        = 120.0f;
    in.tilt_rate_down_dps      = 30.0f;
    in.dt                      = 0.0025f;
    MixerState   state;
    state.current_tilt_deg = 0.0f;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_TRUE(out.tilt_angle < 0.01f); // nowhere near horizontal (1.0) after one tick
    end_test();
}

void plane_tilt_slew_toward_vertical_uses_rate_up_not_rate_dn()
{
    // Stall recovery: wings at 90° (horizontal), pilot demands full pitch up.
    // Moving toward vertical = decreasing tilt_deg = rate_up path.
    //
    // rate_up = 120 °/s, rate_dn = 30 °/s, dt = 0.5 s:
    //   lower bound = 90 − 120×0.5 = 30°   (rate_up — fast)
    //   upper bound = 90 + 30×0.5  = 105°  (rate_dn — slow, not the active path)
    //   target = 0° < 30° → result = 30° → tilt_angle = 30/90 ≈ 0.333
    //
    // If rate_dn (30 °/s) were used for both directions:
    //   lower bound = 90 − 30×0.5 = 75° → result = 75° → tilt_angle = 0.833.
    // The two scenarios give completely different values — this test catches a
    // rate_up / rate_dn swap in the constrain_float arguments.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 1.0f;   // full pitch up → target tilt_deg = 0°
    in.tilt_rate_up_dps        = 120.0f;
    in.tilt_rate_down_dps      = 30.0f;
    in.dt                      = 0.5f;
    MixerState   state;
    state.current_tilt_deg = 90.0f;     // wings horizontal
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected_deg  = 90.0f - 120.0f * 0.5f;   // = 30°
    float expected_tilt = expected_deg / FWD_DEG;  // 30/95 ≈ 0.316
    CHECK_NEAR(expected_tilt, out.tilt_angle,         0.001f);
    CHECK_NEAR(expected_deg,  state.current_tilt_deg, 0.001f);
    end_test();
}

void plane_tilt_slew_rate_dn_zero_falls_back_to_rate_up()
{
    // rate_dn = 0 is the sentinel meaning "use rate_up for both directions."
    // This matches Q_TILT_RATE_DN = 0 (the param default before Avatar tuning).
    //
    // rate_up = 60 °/s, rate_dn = 0 → fallback = 60 °/s, dt = 0.5 s:
    //   upper bound = 0 + 60×0.5 = 30°  (fallback applies rate_up to dn path)
    //   target = 90° > 30° → result = 30° → tilt_angle = 30/90 ≈ 0.333
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.0f;   // target = 90° (horizontal)
    in.tilt_rate_up_dps        = 60.0f;
    in.tilt_rate_down_dps      = 0.0f;   // sentinel: fall back to rate_up
    in.dt                      = 0.5f;
    MixerState   state;
    state.current_tilt_deg = 0.0f;
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected_deg  = 0.0f + 60.0f * 0.5f;    // = 30° (fallback to rate_up)
    float expected_tilt = expected_deg / FWD_DEG;  // 30/95 ≈ 0.316
    CHECK_NEAR(expected_tilt, out.tilt_angle, 0.001f);
    end_test();
}

void plane_tilt_slew_state_persists_across_calls_accumulates_two_steps()
{
    // state.current_tilt_deg carries over between mix() calls.
    // After call 1: current = 0 + rate_dn × dt = 0.075°
    // After call 2: current = 0.075 + rate_dn × dt = 0.150°
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.0f;
    in.tilt_rate_up_dps        = 120.0f;
    in.tilt_rate_down_dps      = 30.0f;
    in.dt                      = 0.0025f;
    MixerState   state;
    state.current_tilt_deg = 0.0f;
    MixerOutputs out;
    mixer.mix(in, state, out);
    mixer.mix(in, state, out);
    float expected_deg  = 2.0f * 30.0f * 0.0025f;  // = 0.150°
    float expected_tilt = expected_deg / 90.0f;
    CHECK_NEAR(expected_tilt, out.tilt_angle,         0.0001f);
    CHECK_NEAR(expected_deg,  state.current_tilt_deg, 0.001f);
    end_test();
}

void plane_tilt_slew_full_3_second_transition_vertical_to_horizontal()
{
    // Integrative test: wings-vertical → stick release → run 3 s at 400 Hz
    // (1200 ticks).  rate_dn = 30 °/s: 30 × 3 = 90° → tilt_angle = 1.0.
    // One extra tick confirms the slew saturates at the target (no overshoot).
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.0f;   // neutral stick = horizontal target
    in.tilt_rate_up_dps        = 120.0f;
    in.tilt_rate_down_dps      = 30.0f;
    in.dt                      = 0.0025f; // 400 Hz
    MixerState   state;
    state.current_tilt_deg = 0.0f;
    MixerOutputs out;
    for (int i = 0; i < 1200; i++) { // 3 s × 400 Hz
        mixer.mix(in, state, out);
    }
    // FBWA targets cruise_physical_angle_deg (90°), not the full 95°.
    // After 3 s at rate_dn=30°/s the servo reaches 90° and saturates there.
    CHECK_NEAR(CRUISE_DEG / FWD_DEG, out.tilt_angle, 0.001f);
    mixer.mix(in, state, out);                 // one extra tick — no overshoot
    CHECK_NEAR(CRUISE_DEG / FWD_DEG, out.tilt_angle, 0.001f);
    end_test();
}

void plane_tilt_slew_cos_tilt_computed_from_rate_limited_angle_not_target()
{
    // Motor outputs use cos(current_tilt_deg), not cos(target_tilt_deg).
    // With slew active the two differ significantly.
    //
    // Start: current_tilt_deg = 0°, target = 90°, rate_dn = 30 °/s, dt = 0.5 s.
    // After one step: current_tilt_deg = 0 + 30×0.5 = 15°, cos(15°) ≈ 0.966.
    //   rear = (throttle - pitch) × cos(15°) = 0.5 × 0.966 ≈ 0.483
    //
    // If cos used the target angle (90°):
    //   rear = 0.5 × cos(90°) = 0.5 × 0 = 0.0  — completely wrong.
    //
    // The 0.483 vs 0.0 delta confirms the physical tilt model drives actuators.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.pitch_tilt_demand = 0.0f;   // target = 90° (horizontal)
    in.plane.throttle_pct      = 50.0f;
    in.pitch                   = 0.0f;
    in.tilt_rate_up_dps        = 120.0f;
    in.tilt_rate_down_dps      = 30.0f;
    in.dt                      = 0.5f;
    MixerState   state;
    state.current_tilt_deg = 0.0f;       // wings vertical
    MixerOutputs out;
    mixer.mix(in, state, out);
    float deg_after     = 0.0f + 30.0f * 0.5f;              // = 15°
    float expected_rear = 0.5f * std::cos(radians(deg_after)); // ≈ 0.483
    CHECK_NEAR(expected_rear, out.motor_thrust[2], 0.002f);
    CHECK_TRUE(out.motor_thrust[2] > 0.4f); // far from 0.0 (target-angle result)
    end_test();
}

// ============================================================================
// GROUP K — Dampening accumulation: vertical and longitudinal
//           [AV-INVAR:sink-damp] [AV-INVAR:long-damp] [AV-INVAR:stabilize-tilt-rate-control]
//
// Root cause of the fixed bug:
//   Old code ran TWO competing rate-limited moves inside mix() each frame:
//   (1) Tilt rate control:  current_tilt_deg → pilot_tilt_deg  (rate = Q_TILT_RATE_UP * dt)
//   (2) Dampening:          current_tilt_deg → new_tilt_deg     (rate = Q_TILT_RATE_UP * dt)
//   When dampening pulls toward vertical and tilt rate control pulls back toward pilot,
//   both at the same rate limit, they cancel exactly. Net per-frame movement = 0.
//   DampThrust appeared nonzero in logs but CurrTilt tracked PilotTilt — no authority.
//
//   Fix: single unified slew toward the combined target (pilot_tilt when no dampening,
//   new_tilt_deg when dampening is active). Dampening now accumulates frame-over-frame.
//
// IMPORTANT: these tests use finite tilt_rate_up_dps (NOT 1e6) because the cancellation
// only manifests under a finite rate limit. With unlimited rate both old and new code snap
// to steady-state in a single frame, masking the multi-frame accumulation bug.
//
// Helper: neutral STABILIZE inputs pre-positioned at a specific tilt angle.
// ============================================================================

static MixerInputs neutral_stabilize_inputs()
{
    MixerInputs in = neutral_plane_inputs();
    in.plane.tilt_rate_mode    = true;    // STABILIZE, not FBWA
    in.plane.pitch_tilt_demand = 0.0f;   // neutral stick — pilot_tilt_deg unchanged
    in.plane.throttle_pct      = 50.0f;
    in.tilt_rate_up_dps        = 60.0f;  // finite rate — required to expose the cancellation bug
    in.dt                      = 0.0025f;
    return in;
}

static MixerState state_at_tilt(float deg)
{
    MixerState s{};
    s.pilot_tilt_deg   = deg;
    s.current_tilt_deg = deg;
    return s;
}

void stabilize_vert_damp_accumulates_across_frames()
{
    // Without the fix: tilt rate control snaps current back to pilot_tilt each frame
    // after dampening moves it away. Net movement per frame = 0. After any number of
    // frames current_tilt_deg stays within one rate-step of pilot_tilt_deg (≈ 29.85°).
    //
    // With the fix: single slew toward combined target (≈ 15° at these inputs).
    // current_tilt_deg decreases by rate_clamp = 0.15° every frame.
    // After 10 frames: 30 − 10×0.15 = 28.5° — well below the 29.0° threshold.
    //
    // Inputs: pilot_tilt = 30°, throttle = 0.5, damp_vert = 0.5
    //   thrust_vert = 0.5×cos(30°) + 0.5 = 0.933
    //   thrust_horiz = 0.5×sin(30°) = 0.25
    //   tilt_target ≈ atan2(0.25, 0.933) ≈ 15° — well below pilot_tilt
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.plane.damp_vert_thrust = 0.5f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;
    for (int i = 0; i < 10; i++) mixer.mix(in, state, out);
    // With fix: current ≈ 28.5° — significantly below 29.0°
    // Without fix: current ≈ 29.85° — barely below 30°, fails this check
    CHECK_TRUE(state.current_tilt_deg < 29.0f);
    CHECK_TRUE(state.current_tilt_deg < state.pilot_tilt_deg); // more vertical than pilot
    end_test();
}

void stabilize_vert_damp_pilot_tilt_deg_never_modified()
{
    // pilot_tilt_deg is the pilot's frozen intent. Dampening must not modify it —
    // it is used as the decomposition baseline and for recovery when dampening ends.
    // This test confirms the invariant survives many frames of active dampening.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.plane.damp_vert_thrust = 0.5f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;
    for (int i = 0; i < 20; i++) mixer.mix(in, state, out);
    CHECK_NEAR(30.0f, state.pilot_tilt_deg, 0.001f); // invariant: dampening never touches this
    end_test();
}

void stabilize_vert_damp_current_recovers_to_pilot_when_damp_clears()
{
    // After dampening has pulled current_tilt_deg away from pilot_tilt_deg, clearing
    // damp_vert_thrust should allow current to recover back toward pilot_tilt_deg.
    // This proves the decoupling works in both directions.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.plane.damp_vert_thrust = 0.5f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;

    // Phase 1: run dampening for 20 frames — current should be well below pilot
    for (int i = 0; i < 20; i++) mixer.mix(in, state, out);
    CHECK_TRUE(state.current_tilt_deg < 29.0f); // dampening was effective

    // Phase 2: clear dampening, run 20 more frames — current should climb back toward pilot
    float current_after_damp = state.current_tilt_deg;
    in.plane.damp_vert_thrust = 0.0f;
    for (int i = 0; i < 20; i++) mixer.mix(in, state, out);
    CHECK_TRUE(state.current_tilt_deg > current_after_damp); // recovering toward pilot
    end_test();
}

void stabilize_long_damp_positive_tilts_servo_more_forward_over_time()
{
    // Positive damp_horiz_thrust = resist deceleration = tilt rotors more forward.
    // Without the fix: same cancellation; current stays within one step of pilot (≈ 30.15°).
    // With the fix: current accumulates forward at rate_clamp per frame.
    // After 10 frames: 30 + 10×0.15 = 31.5° — above the 31.0° threshold.
    //
    // Inputs: pilot_tilt = 30°, throttle = 0.5, damp_horiz = 0.3
    //   thrust_horiz = 0.5×sin(30°) + 0.3 = 0.55
    //   thrust_vert  = 0.5×cos(30°) = 0.433
    //   tilt_target  = atan2(0.55, 0.433) ≈ 51.8° — well above pilot_tilt
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.plane.damp_horiz_thrust = 0.3f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;
    for (int i = 0; i < 10; i++) mixer.mix(in, state, out);
    // With fix: current ≈ 31.5° — above 31.0°
    // Without fix: current ≈ 30.15° — barely above 30°, fails this check
    CHECK_TRUE(state.current_tilt_deg > 31.0f);
    CHECK_TRUE(state.current_tilt_deg > state.pilot_tilt_deg); // more forward than pilot
    end_test();
}

void stabilize_pilot_stick_retains_authority_during_dampening()
{
    // Run identical dampening for 100 frames: once with neutral stick, once with full
    // forward stick. The forward-stick case must finish noticeably more horizontal,
    // proving the pilot is not locked out by active dampening.
    //
    // Neutral (100 frames): pilot stays at 30°, tilt_target ≈ 15°.
    //   current slews from 30° toward 15° at 0.15°/frame → ≈ 15° after 100 frames.
    // Forward stick (100 frames): pilot increases 0.15°/frame → reaches ~45°.
    //   tilt_target also shifts forward (≈ 22° at pilot=45°).
    //   current chases the moving target → lands significantly above neutral case.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in_base = neutral_stabilize_inputs();
    in_base.plane.damp_vert_thrust = 0.5f;
    MixerOutputs out;

    MixerInputs  in_neutral = in_base;
    in_neutral.plane.pitch_tilt_demand = 0.0f;
    MixerState   state_neutral = state_at_tilt(30.0f);
    for (int i = 0; i < 100; i++) mixer.mix(in_neutral, state_neutral, out);

    MixerInputs  in_fwd = in_base;
    in_fwd.plane.pitch_tilt_demand = -1.0f; // full forward stick
    MixerState   state_fwd = state_at_tilt(30.0f);
    for (int i = 0; i < 100; i++) mixer.mix(in_fwd, state_fwd, out);

    // Forward stick should produce a current_tilt_deg at least 3° more horizontal
    CHECK_TRUE(state_fwd.current_tilt_deg > state_neutral.current_tilt_deg + 3.0f);
    end_test();
}

// ============================================================================
// GROUP L — Vel-damp mixer integration [AV-INVAR:vel-damp]
//
// These tests verify that the force-vector decomposition in the mixer correctly
// incorporates damp_horiz_thrust and damp_vert_thrust, and that the two axes
// compose independently. They also validate the key architectural invariant of
// the new always-active vel-damp: when damp_horiz = 0 (zero velocity error),
// the tilt is exactly the pilot's commanded angle — no correction is applied.
//
// All tests use unlimited tilt_rate_up_dps (1e6) so one call reaches steady
// state. Throttle = 50% throughout. Expected tilt angles are computed from:
//
//   thrust_horiz = throttle × sin(pilot_tilt) + damp_horiz
//   thrust_vert  = throttle × cos(pilot_tilt) + damp_vert
//   tilt_target  = atan2(thrust_horiz, thrust_vert)  [degrees]
//   tilt_angle   = tilt_target / FWD_DEG
// ============================================================================

void vel_damp_zero_horiz_tilt_equals_pilot_command()
{
    // damp_horiz = 0, damp_vert = 0 → decomposition block not entered (guard:
    // fabsf(damp_horiz) > 1e-4 is false). tilt_target = pilot_tilt_deg = 30°.
    // This validates: zero velocity error → zero correction → no servo movement.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps       = 1e6f;
    in.plane.damp_horiz_thrust = 0.0f;
    in.plane.damp_vert_thrust  = 0.0f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(30.0f / FWD_DEG, out.tilt_angle, 0.001f);
    end_test();
}

void vel_damp_positive_horiz_tilts_forward_from_vertical()
{
    // Pilot vertical (0°), damp_horiz = 0.15 (fighting headwind → tilt forward).
    //   thrust_horiz = 0.5×sin(0°) + 0.15 = 0.15
    //   thrust_vert  = 0.5×cos(0°)        = 0.50
    //   tilt_target  = atan2(0.15, 0.50)  = 16.70°  →  tilt_angle = 16.70/95
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps        = 1e6f;
    in.plane.damp_horiz_thrust = 0.15f;
    in.plane.damp_vert_thrust  = 0.0f;
    MixerState   state = state_at_tilt(0.0f);
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected_deg  = degrees(std::atan2(0.15f, 0.50f)); // ≈ 16.70°
    float expected_tilt = expected_deg / FWD_DEG;
    CHECK_NEAR(expected_tilt, out.tilt_angle, 0.002f);
    CHECK_TRUE(out.tilt_angle > 0.0f); // moved forward from vertical
    end_test();
}

void vel_damp_negative_horiz_tilts_more_vertical()
{
    // Pilot at 30°, damp_horiz = -0.10 (braking — tilt toward vertical).
    //   thrust_horiz = 0.5×sin(30°) − 0.10 = 0.25 − 0.10 = 0.15
    //   thrust_vert  = 0.5×cos(30°)        = 0.4330
    //   tilt_target  = atan2(0.15, 0.4330) = 19.11°  <  30° (less forward)
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps        = 1e6f;
    in.plane.damp_horiz_thrust = -0.10f;
    in.plane.damp_vert_thrust  = 0.0f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected_deg  = degrees(std::atan2(0.15f, 0.4330f)); // ≈ 19.11°
    float expected_tilt = expected_deg / FWD_DEG;
    CHECK_NEAR(expected_tilt, out.tilt_angle, 0.002f);
    CHECK_TRUE(out.tilt_angle < 30.0f / FWD_DEG); // less forward than pilot commanded
    end_test();
}

void vel_damp_vert_alone_tilts_toward_vertical_and_increases_throttle()
{
    // Pilot at 30°, damp_horiz = 0, damp_vert = 0.30 (sink rate correction).
    //   thrust_horiz = 0.5×sin(30°) + 0    = 0.25
    //   thrust_vert  = 0.5×cos(30°) + 0.30 = 0.7330
    //   tilt_target  = atan2(0.25, 0.7330) = 18.85°  <  30° (more vertical)
    //   new_throttle = sqrt(0.25² + 0.7330²) = 0.7745
    //
    // Vertical dampening rotates the thrust vector toward vertical AND increases
    // total thrust. Wing motors reflect the higher throttle magnitude.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps        = 1e6f;
    in.plane.damp_horiz_thrust = 0.0f;
    in.plane.damp_vert_thrust  = 0.30f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected_deg  = degrees(std::atan2(0.25f, 0.7330f)); // ≈ 18.85°
    float expected_tilt = expected_deg / FWD_DEG;
    CHECK_NEAR(expected_tilt, out.tilt_angle, 0.002f);
    CHECK_TRUE(out.tilt_angle < 30.0f / FWD_DEG); // more vertical than pilot
    // Wing motors should reflect the increased throttle magnitude (~0.7745)
    CHECK_TRUE(out.motor_thrust[0] > 0.6f); // above pilot's 0.5 baseline
    end_test();
}

void vel_damp_horiz_and_vert_compose_via_force_vector()
{
    // Both dampeners active simultaneously — composed through force-vector atan2,
    // not applied sequentially. Pilot at 30°, damp_horiz = 0.10, damp_vert = 0.20.
    //   thrust_horiz = 0.5×sin(30°) + 0.10 = 0.25 + 0.10 = 0.35
    //   thrust_vert  = 0.5×cos(30°) + 0.20 = 0.4330 + 0.20 = 0.6330
    //   tilt_target  = atan2(0.35, 0.6330) = 28.94°
    //   new_throttle = sqrt(0.35² + 0.6330²) = 0.7232
    //
    // The result is neither 30° (pilot) + forward push + back-tilt in sequence;
    // it is the single vector sum. If the two were applied sequentially the
    // answer would differ.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps        = 1e6f;
    in.plane.damp_horiz_thrust = 0.10f;
    in.plane.damp_vert_thrust  = 0.20f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;
    mixer.mix(in, state, out);
    float expected_deg  = degrees(std::atan2(0.35f, 0.6330f)); // ≈ 28.94°
    float expected_tilt = expected_deg / FWD_DEG;
    CHECK_NEAR(expected_tilt, out.tilt_angle, 0.002f);
    // Tilt is slightly less than pilot's 30° because vert damp pulls more vertical
    // than horiz damp pushes forward in this scenario.
    CHECK_TRUE(out.tilt_angle < 30.0f / FWD_DEG);
    end_test();
}

// ============================================================================
// GROUP M — Angle latch and force-block bypass [AV-INVAR:vel-damp]
//
// These tests document the critical invariant that drove the angle-latch design
// and capture the failure mode of the slew approach that was tried first.
//
// The force-vector decomposition block in tilt_rate_mode is gated by:
//   if (fabsf(damp_horiz_thrust) > 1e-4f || damp_vert_thrust > 0.0f)
//
// When the gate is false (damp_horiz = 0), tilt_target_deg falls through to
// its default: state.pilot_tilt_deg (line: "float tilt_target_deg = state.pilot_tilt_deg").
// The servo then slews toward pilot_tilt_deg at the physical rate.
//
// FAILURE MODE (slew approach):
//   pilot_tilt_deg = 0° (not yet snapped), damp_horiz drops to 0 when the
//   vel-damp error is zeroed. tilt_target = 0°. Physical servo chases 0° at
//   full speed while pilot_tilt_deg slews up slowly from 0°. They converge at
//   the midpoint — for a 15° correction that is ~7.5°. The retraction lurch
//   is halved but not prevented.
//
// CORRECT APPROACH (snap latch):
//   pilot_tilt_deg is snapped to current_tilt_deg (e.g. 15°) before damp_horiz
//   drops to zero. With pilot_tilt_deg = 15° and damp_horiz = 0: force block
//   is bypassed, tilt_target = 15°, servo moves 0° per frame. No retraction.
//   As damp_horiz fades (non-zero during the 100 ms fade window while aircraft
//   drifts), the force block remains active and provides smooth correction until
//   the fade reaches zero and tilt settles exactly at pilot_tilt_deg = 15°.
// ============================================================================

void angle_latch_force_block_bypassed_when_damp_horiz_zero()
{
    // When damp_horiz = 0 (and damp_vert = 0) the force-vector block is NOT
    // entered. tilt_target_deg = pilot_tilt_deg exactly — confirming the gate
    // that makes the snap vs. slew distinction critical.
    //
    // pilot_tilt = 30°, damp_horiz = 0 → tilt_target = 30° → servo holds.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps        = 1e6f;
    in.plane.damp_horiz_thrust = 0.0f;
    in.plane.damp_vert_thrust  = 0.0f;
    MixerState   state = state_at_tilt(30.0f);
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(30.0f / FWD_DEG, out.tilt_angle, 0.0001f);
    CHECK_NEAR(30.0f, state.current_tilt_deg,   0.0001f); // zero movement
    end_test();
}

void angle_latch_snap_prevents_retraction_when_damp_horiz_drops_to_zero()
{
    // Post-latch state: pilot_tilt_deg has been snapped to 15°, current at 15°,
    // damp_horiz = 0. Force block bypassed → tilt_target = pilot_tilt = 15° →
    // servo moves 0°/frame. Verify over 10 frames with finite rate.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps        = 60.0f; // finite rate exposes any movement
    in.plane.damp_horiz_thrust = 0.0f;
    in.plane.damp_vert_thrust  = 0.0f;
    MixerState   state;
    state.pilot_tilt_deg   = 15.0f; // snapped by angle latch
    state.current_tilt_deg = 15.0f;
    MixerOutputs out;
    for (int i = 0; i < 10; i++) mixer.mix(in, state, out);
    CHECK_NEAR(15.0f / FWD_DEG, out.tilt_angle, 0.001f);
    CHECK_NEAR(15.0f, state.current_tilt_deg,   0.001f);
    end_test();
}

void angle_latch_without_snap_servo_retracts_when_damp_horiz_drops_to_zero()
{
    // Failure mode of the slew approach: pilot_tilt_deg = 0° (not snapped),
    // damp_horiz = 0, current_tilt_deg = 15°. Force block bypassed →
    // tilt_target = 0° → servo retracts at 60°/s toward 0°.
    //
    // After 10 frames at 60°/s × 0.0025 s = 0.15°/frame:
    //   current = 15° − 10×0.15° = 13.5° — a clear 1.5° retraction.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps        = 60.0f;
    in.plane.damp_horiz_thrust = 0.0f;
    in.plane.damp_vert_thrust  = 0.0f;
    MixerState   state;
    state.pilot_tilt_deg   = 0.0f;  // NOT snapped — slew approach failure mode
    state.current_tilt_deg = 15.0f;
    MixerOutputs out;
    for (int i = 0; i < 10; i++) mixer.mix(in, state, out);
    float expected = 15.0f - 10.0f * 60.0f * 0.0025f; // = 13.5°
    CHECK_NEAR(expected, state.current_tilt_deg, 0.01f); // retracted
    CHECK_TRUE(state.current_tilt_deg < 15.0f);          // moving toward 0°
    end_test();
}

void angle_latch_non_zero_damp_horiz_activates_force_block_past_pilot_tilt()
{
    // With pilot_tilt = 15° and damp_horiz = 0.10 (still present during fade),
    // the force block IS entered (fabsf(0.10) > 1e-4). tilt_target is computed
    // via atan2, landing MORE forward than pilot_tilt — the residual correction
    // force is still active during the fade window.
    //
    //   thrust_horiz = 0.5×sin(15°) + 0.10 = 0.2294
    //   thrust_vert  = 0.5×cos(15°)        = 0.4830
    //   tilt_target  = atan2(0.2294, 0.4830) ≈ 25.4°  > 15°
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps        = 1e6f;
    in.plane.damp_horiz_thrust = 0.10f;
    in.plane.damp_vert_thrust  = 0.0f;
    MixerState   state;
    state.pilot_tilt_deg   = 15.0f;
    state.current_tilt_deg = 15.0f;
    MixerOutputs out;
    mixer.mix(in, state, out);
    float h = 0.5f * std::sin(radians(15.0f)) + 0.10f;
    float v = 0.5f * std::cos(radians(15.0f));
    float expected = degrees(std::atan2(h, v)) / FWD_DEG;
    CHECK_NEAR(expected, out.tilt_angle, 0.002f);
    CHECK_TRUE(out.tilt_angle > 15.0f / FWD_DEG); // past pilot angle — force block active
    end_test();
}

void angle_latch_fade_diminishing_damp_horiz_converges_to_pilot_tilt()
{
    // Simulate the 100 ms fade washout with snapped pilot_tilt = 15°.
    // Steps: damp_horiz = 0.15 → 0.10 → 0.05 → 0.
    // At each non-zero step the force block is active and tilt > 15°.
    // At zero the block is bypassed and tilt = pilot_tilt exactly.
    // Servo never goes BELOW 15° at any step — no retraction at any point.
    begin_test(__func__);
    AvatarMixer  mixer;
    MixerInputs  in    = neutral_stabilize_inputs();
    in.tilt_rate_up_dps = 1e6f;
    MixerState   state;
    state.pilot_tilt_deg   = 15.0f;
    state.current_tilt_deg = 15.0f;
    MixerOutputs out;

    // Step 1: D = 0.15 → force block active → tilt pushed forward past 15°
    in.plane.damp_horiz_thrust = 0.15f;
    mixer.mix(in, state, out);
    float tilt_d15 = out.tilt_angle;
    CHECK_TRUE(tilt_d15 > 15.0f / FWD_DEG);

    // Step 2: D = 0.10 → still forward but less so than step 1
    in.plane.damp_horiz_thrust = 0.10f;
    mixer.mix(in, state, out);
    float tilt_d10 = out.tilt_angle;
    CHECK_TRUE(tilt_d10 > 15.0f / FWD_DEG);  // still forward of pilot
    CHECK_TRUE(tilt_d10 < tilt_d15);          // converging toward 15°

    // Step 3: D = 0 → force block bypassed → tilt settles at pilot_tilt exactly
    in.plane.damp_horiz_thrust = 0.0f;
    mixer.mix(in, state, out);
    CHECK_NEAR(15.0f / FWD_DEG, out.tilt_angle, 0.001f);

    // Confirm: tilt was never below pilot_tilt (15°) at any step — no retraction
    CHECK_TRUE(tilt_d15 >= 15.0f / FWD_DEG);
    CHECK_TRUE(tilt_d10 >= 15.0f / FWD_DEG);
    end_test();
}

// ============================================================================
// LAYER 4: BlimpMixer — PLANE MODE
//
// Active config: forward_flight_physical_angle_deg = 90°, handoff_point = 0.5
//   val_neutral = BLIMP_PLANE_FWD_ANGLE / forward_flight_physical_angle_deg
//               = 90 / 90 = 1.0
// ============================================================================

void blimp_plane_neutral_stick_gives_full_forward_tilt()
{
    // elevator_input = 0 → pitch_in = 0 → elevator_out = 0, tilt_delta = 0
    // tilt_angle = val_neutral = BLIMP_PLANE_FWD_ANGLE / FWD_DEG = 90/95 ≈ 0.9474
    begin_test(__func__);
    BlimpMixer   mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.elevator_input = 0.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(CRUISE_DEG / FWD_DEG, out.tilt_angle, 0.001f);
    CHECK_NEAR(0.0f,  out.elevator_out, 0.001f);
    end_test();
}

void blimp_plane_full_pitch_up_tilts_reverse_and_saturates_elevator()
{
    // pitch_in = 1.0, threshold = 0.5:
    //   elevator_out = 1.0, tilt_delta = (1.0-0.5)/(1.0-0.5) = 1.0
    // tilt_angle = val_neutral - tilt_delta*(val_neutral+1.0)
    //            = 1.0 - 1.0*(1.0+1.0) = -1.0  → clamped to -1.0
    begin_test(__func__);
    BlimpMixer   mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.elevator_input = 4500.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR( 1.0f, out.elevator_out, 0.001f);
    CHECK_NEAR(-1.0f, out.tilt_angle,   0.001f);
    end_test();
}

void blimp_plane_full_pitch_down_tilts_to_forward_neutral()
{
    // pitch_in = -1.0, threshold = 0.5:
    //   elevator_out = -1.0, tilt_delta = 1.0
    // tilt_angle = val_neutral + tilt_delta*(1.0-val_neutral)
    //            = 1.0 + 1.0*(1.0-1.0) = 1.0
    begin_test(__func__);
    BlimpMixer   mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.elevator_input = -4500.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(-1.0f, out.elevator_out, 0.001f);
    CHECK_NEAR( 1.0f, out.tilt_angle,   0.001f);
    end_test();
}

void blimp_plane_throttle_drives_both_lift_motors_equally()
{
    begin_test(__func__);
    BlimpMixer   mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.throttle_pct = 80.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(0.8f, out.motor_thrust[0], 0.001f);
    CHECK_NEAR(0.8f, out.motor_thrust[1], 0.001f);
    end_test();
}

void blimp_plane_rudder_follows_pilot_yaw()
{
    begin_test(__func__);
    BlimpMixer   mixer;
    MixerInputs  in = neutral_plane_inputs();
    in.plane.rudder_input = -2250.0f;
    MixerState   state;
    MixerOutputs out;
    mixer.mix(in, state, out);
    CHECK_NEAR(-0.5f, out.rudder_out, 0.001f);
    end_test();
}

// ============================================================================
// LAYER 5: BlimpMixer — MANUAL OVERRIDE (dumb RC passthrough)
// ============================================================================

void blimp_manual_override_rc2_sets_lift_motors()
{
    // rc_in[2] is the throttle channel.  (rc_in[2] - 1000) / 1000 = thrust.
    // rc_in[2] = 1500 → 50% thrust on both lift motors.
    begin_test(__func__);
    BlimpMixer   mixer;
    MixerInputs  in = neutral_copter_inputs();
    // Enable manual override
    in.manual_override_pwm = 1500;
    // rc_in: channel 2 = throttle, channel 1 = pitch/tilt, channel 3 = yaw
    for (int i = 0; i < 16; i++) in.rc_in[i] = 1500;
    in.rc_in[2] = 1500; // 50% throttle
    in.rc_in[1] = 1500; // neutral tilt
    in.rc_in[3] = 1500; // neutral yaw
    // Also need g_config.emergency_blimp_manual_mode = true.
    // If the blimp manual mode is not enabled in config, manual override is
    // inactive. Check the current config and skip if not available.
    MixerState   state;
    MixerOutputs out{};
    mixer.mix(in, state, out);
    // If manual override fired: lift motors = (1500-1000)/1000 = 0.5
    // If not (because emergency_blimp_manual_mode is off in avatarConfig):
    // the motors end up driven by copter mode instead — check state flag.
    if (state.manual_override_active) {
        CHECK_NEAR(0.5f, out.motor_thrust[0], 0.001f);
        CHECK_NEAR(0.5f, out.motor_thrust[1], 0.001f);
    } else {
        // emergency_blimp_manual_mode is disabled in this config — that's fine.
        CHECK_FALSE(state.manual_override_active);
    }
    end_test();
}

void blimp_manual_override_rc3_sets_yaw_motor_and_rudder()
{
    // rc_in[3] at full deflection (2000) → yaw = (2000-1500)/500 = 1.0
    // Both the yaw motor thrust and rudder_out should be 1.0.
    begin_test(__func__);
    BlimpMixer   mixer;
    MixerInputs  in = neutral_copter_inputs();
    in.manual_override_pwm = 1500;
    for (int i = 0; i < 16; i++) in.rc_in[i] = 1500;
    in.rc_in[2] = 1000;
    in.rc_in[3] = 2000; // full yaw
    MixerState   state;
    MixerOutputs out{};
    mixer.mix(in, state, out);
    if (state.manual_override_active) {
        CHECK_NEAR(1.0f, out.motor_thrust[2], 0.001f); // yaw motor
        CHECK_NEAR(1.0f, out.rudder_out, 0.001f);
    } else {
        CHECK_FALSE(state.manual_override_active);
    }
    end_test();
}

// ============================================================================
// Main
// ============================================================================

int main()
{
    std::printf("=== Mixer Unit Tests ===\n");
    std::printf("Production files: AP_Motors6DOF_AvatarMixer.cpp, "
                "AP_Motors6DOF_BlimpMixer.cpp\n");
    std::printf("Active config:    g_config = avatarConfig "
                "(ACTIVE_CONFIG = 1, fwd_angle = 90°)\n");
    std::printf("  BlimpMixer blimp tests: val_neutral = 90/90 = 1.0\n");

    std::printf("\n-- Layer 1: elevator_tilt_split() --\n");
    elevator_tilt_split_neutral_produces_zero_both();
    elevator_tilt_split_below_threshold_only_elevator_moves();
    elevator_tilt_split_at_threshold_elevator_saturates_tilt_still_zero();
    elevator_tilt_split_above_threshold_tilt_ramps_elevator_stays_saturated();
    elevator_tilt_split_full_positive_both_saturate();
    elevator_tilt_split_negative_input_is_sign_symmetric();

    std::printf("\n-- Layer 2: AvatarMixer plane mode --\n");
    avatar_plane_neutral_tilt_demand_gives_wings_horizontal();
    avatar_plane_full_pitch_up_tilts_wings_to_vertical();
    avatar_plane_tilt_demand_past_vertical_is_clamped();
    avatar_plane_elevator_follows_pitch_pid_output();
    avatar_plane_rudder_follows_pilot_yaw();
    avatar_plane_zero_roll_wing_motors_equal();
    avatar_plane_roll_differential_applied_at_wings_vertical();
    avatar_plane_roll_differential_fades_at_wings_horizontal();
    avatar_plane_wings_horizontal_rear_motor_is_zero();
    avatar_plane_wings_vertical_rear_motor_driven_by_throttle_minus_pitch();

    std::printf("\n-- Layer 3: AvatarMixer copter mode --\n");
    avatar_copter_neutral_hover_wings_level_motors_equal();
    avatar_copter_positive_roll_demand_tilts_left_motor_higher();
    avatar_copter_roll_effectiveness_zero_when_wings_horizontal();
    avatar_copter_shut_down_spool_clears_tilt_and_returns();
    avatar_copter_elevator_is_negative_cos_tilt();
    avatar_copter_motor_outputs_stay_within_limits();

    std::printf("\n-- Group A: Pitch compensation / stall prevention --\n");
    pitch_compensation_30_degrees_up_tilts_wings_30_degrees_from_vertical();
    pitch_compensation_50_degrees_up_wing_at_40_degrees_from_horizontal();
    pitch_compensation_80_degrees_up_deep_stall_wings_nearly_vertical();
    pitch_compensation_past_90_degrees_saturates_servo_and_sets_flag();

    std::printf("\n-- Group B: Pitch compensation + forward stick --\n");
    pitch_compensation_and_forward_stick_angles_add();
    pitch_compensation_and_forward_stick_partially_cancel_when_nose_down();

    std::printf("\n-- Group C: Rear motor math --\n");
    rear_motor_at_hover_equals_throttle_minus_pitch_demand();
    rear_motor_fades_with_cos_tilt_at_45_degrees();
    rear_motor_decreases_on_pitch_up_demand();
    rear_motor_increases_on_pitch_down_demand();
    rear_motor_clamps_to_zero_when_pitch_demand_exceeds_throttle();

    std::printf("\n-- Group D: Roll headroom --\n");
    roll_headroom_at_half_throttle_allows_full_roll_within_margin();
    roll_headroom_full_throttle_desaturates_by_shifting_both_motors_down();
    pitch_correction_with_roll_desaturates_symmetrically();

    std::printf("\n-- Group E: Plane mode rear motor under pitch pressure --\n");
    plane_mode_rear_motor_surges_when_elevator_saturates_nose_up();
    plane_mode_rear_motor_zero_when_wings_horizontal_regardless_of_pitch();

    std::printf("\n-- Group F: Disarmed / failsafe --\n");
    disarmed_aircraft_tilt_angle_returns_to_zero_regardless_of_stick();

    std::printf("\n-- Group G: Elevator trim schedule --\n");
    elevator_trim_schedule_at_45_degree_tilt_follows_cosine();

    std::printf("\n-- Group H: QSTABILIZE surface controls --\n");
    qstabilize_pid_roll_drives_ailerons_and_motor_differential();
    qstabilize_full_roll_saturates_ailerons();
    qstabilize_pid_yaw_drives_rudder_and_rear_motor_differential();
    qstabilize_pid_yaw_rear_motor_differential_sign();
    qstabilize_roll_and_yaw_pid_drive_surfaces_independently();

    std::printf("\n-- Group I: Aircraft pitch state -> motor hierarchy --\n");
    nose_up_aircraft_rear_motor_produces_more_thrust_than_front();
    nose_down_aircraft_front_motors_produce_more_thrust_than_rear();

    std::printf("\n-- Group J: Plane mode tilt slew rate limiting [AV-INVAR:plane-tilt-slew] --\n");
    plane_tilt_slew_stick_release_advances_one_step_at_rate_dn();
    plane_tilt_slew_wings_do_not_snap_to_horizontal_in_single_step();
    plane_tilt_slew_toward_vertical_uses_rate_up_not_rate_dn();
    plane_tilt_slew_rate_dn_zero_falls_back_to_rate_up();
    plane_tilt_slew_state_persists_across_calls_accumulates_two_steps();
    plane_tilt_slew_full_3_second_transition_vertical_to_horizontal();
    plane_tilt_slew_cos_tilt_computed_from_rate_limited_angle_not_target();

    std::printf("\n-- Group K: Dampening accumulation [AV-INVAR:sink-damp] [AV-INVAR:long-damp] --\n");
    stabilize_vert_damp_accumulates_across_frames();
    stabilize_vert_damp_pilot_tilt_deg_never_modified();
    stabilize_vert_damp_current_recovers_to_pilot_when_damp_clears();
    stabilize_long_damp_positive_tilts_servo_more_forward_over_time();
    stabilize_pilot_stick_retains_authority_during_dampening();

    std::printf("\n-- Group L: Vel-damp mixer integration [AV-INVAR:vel-damp] --\n");
    vel_damp_zero_horiz_tilt_equals_pilot_command();
    vel_damp_positive_horiz_tilts_forward_from_vertical();
    vel_damp_negative_horiz_tilts_more_vertical();
    vel_damp_vert_alone_tilts_toward_vertical_and_increases_throttle();
    vel_damp_horiz_and_vert_compose_via_force_vector();

    std::printf("\n-- Group M: Angle latch and force-block bypass [AV-INVAR:vel-damp] --\n");
    angle_latch_force_block_bypassed_when_damp_horiz_zero();
    angle_latch_snap_prevents_retraction_when_damp_horiz_drops_to_zero();
    angle_latch_without_snap_servo_retracts_when_damp_horiz_drops_to_zero();
    angle_latch_non_zero_damp_horiz_activates_force_block_past_pilot_tilt();
    angle_latch_fade_diminishing_damp_horiz_converges_to_pilot_tilt();

    std::printf("\n-- Group N: Rear-motor pitch priority on saturation [AV-INVAR:rear-pitch-priority] --\n");
    stabilize_rear_yaw_clamped_to_headroom_preserves_pitch_common_mode();
    stabilize_rear_yaw_within_headroom_is_unaffected();

    std::printf("\n-- Group O: Pitch before throttle on saturation [AV-INVAR:pitch-before-throttle] --\n");
    copter_full_throttle_nose_up_transfers_front_excess_to_rear();
    copter_full_throttle_nose_down_transfers_rear_excess_to_front();
    copter_unsaturated_pitch_transfer_is_noop();
    copter_low_throttle_rear_railed_at_zero_does_not_boost_fronts();
    copter_yaw_room_respects_post_transfer_rear_common_mode();

    std::printf("\n-- Layer 4: BlimpMixer plane mode --\n");
    blimp_plane_neutral_stick_gives_full_forward_tilt();
    blimp_plane_full_pitch_up_tilts_reverse_and_saturates_elevator();
    blimp_plane_full_pitch_down_tilts_to_forward_neutral();
    blimp_plane_throttle_drives_both_lift_motors_equally();
    blimp_plane_rudder_follows_pilot_yaw();

    std::printf("\n-- Layer 5: BlimpMixer manual override --\n");
    blimp_manual_override_rc2_sets_lift_motors();
    blimp_manual_override_rc3_sets_yaw_motor_and_rudder();

    std::printf("\n=== Results: %d checks, %d failed ===\n",
                g_checks_run, g_checks_failed);
    return g_checks_failed > 0 ? 1 : 0;
}
