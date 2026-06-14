// Unit tests for tvc_run_main_logic() — the HAL-free TVC brain.
//
// WHAT THIS CODE CONTROLS
// =======================
// The TVC (Thrust Vectoring Controller) controls a single tilt servo that
// physically rotates a motor assembly. On the Blimp, two motors sit on a
// gondola that tilts. On the Avatar VTOL, both wings tilt together via a
// single servo. In both cases:
//
//   pitch_angle_norm = -1.0  →  max reverse tilt (blimp: downward thrust)
//   pitch_angle_norm =  0.0  →  vertical (pure hover, zero horizontal thrust)
//   pitch_angle_norm =  1.0  →  max forward tilt (full horizontal thrust)
//
// The physical angle this corresponds to is vehicle-dependent:
//   Blimp config:   forward_flight_physical_angle_deg = 180°, so 1.0 = 180° from vertical
//   Avatar config:  forward_flight_physical_angle_deg =  90°, so 1.0 =  90° from vertical (wings horizontal)
//
// THE 6DOF CONTROL PHILOSOPHY (critical to understanding these tests)
// ====================================================================
// This is NOT a conventional fixed-wing controller. "Forward" on the stick does
// NOT pitch the nose down. Instead, it tilts the thrust vector forward, creating
// horizontal thrust directly. ArduPilot's attitude controller maintains level
// flight by adjusting throttle. The three independent pilot commands are:
//
//   THRUST_CHANNEL  → vertical force component (0.0 = none, 1.0 = full up)
//   FORWARD_CHANNEL → forward tilt of thrust vector (-1.0 to 1.0)
//   LATERAL_CHANNEL → lateral tilt of thrust vector (-1.0 to 1.0)
//
// The TVC computes:  tilt_angle = atan2(forward_cmd, thrust_cmd)
// This is the angle of the resultant 3D thrust vector from vertical.
//
// ACTIVE PRODUCTION FLAGS (defined in TVC_Core.h / TVC_Core.cpp)
// ===============================================================
//   VTOL_MODE            = true   (output is a normalised servo angle, not motor delta)
//   OPEN_LOOP_SERVO_MODE = true   (stick position maps directly to servo angle; no PIDs)
//   PID_TUNING_MODE      = true   (gain scheduling bypassed; rate PIDs are unused)
//
// CONFIG DEPENDENCY
// =================
// Tests that check specific numeric values assume ACTIVE_CONFIG = CONFIG_TYPE_BLIMP,
// which sets forward_flight_physical_angle_deg = 180°. If the config is changed to
// Avatar (90°), expected values in those tests will change proportionally (e.g., a
// 90° target → 0.5 for blimp, but → 1.0 for Avatar). Tests marked with
// "config-independent" hold true for any vehicle.
//
// These tests compile the production source files directly (see Makefile), so
// they always reflect the real algorithm with no stale-copy risk.

#include <cstdio>
#include <cmath>
#include <algorithm>

#include "TVC_Core.h"
#include "TVC_PID.h"
#include "TVC_Filters.h"

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
// Helpers: persistent TVC state and input construction
// ============================================================================

// TVCTestState owns the objects that TVC_CoreState holds by reference.
// Construct one per test; the TVC updates it in place across calls.
struct TVCTestState {
    LinearPIDController pitch_rate_pid  {0, 0, 0, 0};
    LinearPIDController roll_rate_pid   {0, 0, 0, 0};
    LinearPIDController pitch_angle_pid {0, 0, 0, 0};
    LinearPIDController roll_angle_pid  {0, 0, 0, 0};
    CustomFilter pitch_filter {20.0f, 1.0f/400.0f, IIR::ORDER::OD2, IIR::TYPE::LOWPASS};
    CustomFilter roll_filter  {20.0f, 1.0f/400.0f, IIR::ORDER::OD2, IIR::TYPE::LOWPASS};
    bool pitch_saturated {false};
    bool roll_saturated  {false};

    TVC_CoreState core() {
        return {pitch_rate_pid, roll_rate_pid,
                pitch_angle_pid, roll_angle_pid,
                pitch_filter, roll_filter,
                pitch_saturated, roll_saturated};
    }
};

// Encode a normalized value as a SBUS PWM integer.
// SBUS uses 1000–2000 µs. The TVC decodes channels back to floats, so every
// float we want to test must be round-tripped through this encoding.
//   pwm(0.5f)           → 1750  (maps to thrust_cmd = 0.5 via range -1..1)
//   pwm(0.5f, 0, 1)     → 1500  (maps to transition_progress = 0.5 via range 0..1)
static int pwm(float value, float min_val = -1.0f, float max_val = 1.0f)
{
    float clamped = std::max(min_val, std::min(max_val, value));
    return 1000 + (int)((clamped - min_val) / (max_val - min_val) * 1000.0f);
}

// Returns a baseline TVC_Inputs representing a steady, level hover:
//   - AHRS healthy, not in failsafe
//   - Thrust at 50%  (thrust_cmd decodes to 0.5 after SBUS round-trip)
//   - Forward/lateral sticks at neutral (no horizontal translation commanded)
//   - Transition progress = 0  (pure hover mode, plane-mode blending inactive)
//   - Aircraft perfectly level, no angular rate
//
// Note on channels 0–5: the TVC checks whether all six "motor channels" are
// below 1063 µs to detect a disarmed/motors-off state. Setting them to 1500
// keeps that guard inactive, as the Avatar/Blimp mixer always sets these to
// 1500 when routing inputs through tvc_run_main_logic.
static TVC_Inputs neutral_hover_inputs()
{
    TVC_Inputs in {};
    in.ahrs_healthy = true;
    in.in_failsafe  = false;
    in.now_us       = 1000000; // 1 s — avoids zero-timestamp edge cases in PIDs

    for (int i = 0; i < 16; i++) in.rc_in[i] = 1500;

    in.rc_in[THRUST_CHANNEL]              = pwm(0.5f);        // thrust_cmd = 0.5
    in.rc_in[FORWARD_CHANNEL]             = 1500;              // forward_cmd = 0.0
    in.rc_in[LATERAL_CHANNEL]             = 1500;              // lateral_cmd = 0.0
    in.rc_in[TRANSITION_PROGRESS_CHANNEL] = 1000;              // 0.0 = pure hover

    in.pitch_rad = 0.0f;
    in.roll_rad  = 0.0f;
    in.gyro      = {0.0f, 0.0f, 0.0f};
    return in;
}

// ============================================================================
// Tests
// ============================================================================

// --- Hover / neutral state ---------------------------------------------------

void neutral_sticks_in_hover_produce_zero_tilt_and_half_throttle()
{
    // When the pilot holds a steady hover with no translational command, the
    // tilt servo should be at neutral (wings/gondola pointing straight up,
    // pitch_angle_norm = 0). Total throttle equals the thrust input because
    // no tilt means no thrust compensation is needed.
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    CHECK_NEAR(0.0f, out.pitch_angle_norm, 0.001f); // servo at neutral
    CHECK_NEAR(0.0f, out.roll_angle_norm,  0.001f); // no lateral tilt
    CHECK_NEAR(0.5f, out.total_throttle,   0.001f); // motors at 50% — matches thrust input

    end_test();
}

// --- Forward translation (the 6DOF key behavior) ----------------------------

void forward_stick_tilts_thrust_vector_forward_not_the_nose()
{
    // This is the defining characteristic of the 6DOF control philosophy.
    // Pushing forward on the stick does NOT pitch the aircraft nose-down.
    // Instead it tilts the tilt servo toward horizontal, rotating the thrust
    // vector forward. ArduPilot's altitude controller then increases throttle
    // to maintain vertical lift. The aircraft translates forward while staying
    // level.
    //
    // A positive pitch_angle_norm means the servo has moved toward the
    // full-forward position (wings horizontal for Avatar, gondola forward
    // for the Blimp).
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[FORWARD_CHANNEL] = pwm(0.5f); // 50% forward

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    CHECK_TRUE(out.pitch_angle_norm > 0.0f); // servo moved toward forward-tilt
    CHECK_NEAR(0.0f, out.roll_angle_norm, 0.001f); // lateral servo unchanged

    end_test();
}

void zero_thrust_with_full_forward_stick_tilts_to_exactly_horizontal()
{
    // With zero vertical thrust and full forward stick, the desired thrust
    // vector is perfectly horizontal: atan2(forward=1.0, thrust=0.0) = 90°.
    //
    // The servo command is the physical angle normalised by the vehicle's
    // maximum forward angle:
    //   Blimp config: 90° / 180° = 0.5  (halfway to maximum tilt)
    //   Avatar config: 90° / 90° = 1.0  (wings fully horizontal)
    //
    // This test uses blimp config (ACTIVE_CONFIG = 0), so expects 0.5.
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[THRUST_CHANNEL]  = 1500;       // thrust_cmd = 0.0 (no vertical component)
    in.rc_in[FORWARD_CHANNEL] = pwm(1.0f);  // forward_cmd = 1.0 (full horizontal)

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    // atan2(1.0, 0.0) = 90° → 90° / 90° (avatar) = 1.0
    CHECK_NEAR(1.0f, out.pitch_angle_norm, 0.01f);
    end_test();
}

void full_throttle_leaves_no_budget_for_forward_motion()
{
    // The TVC enforces altitude priority using a Pythagorean thrust budget:
    // the 3D vector magnitude of (thrust, forward, lateral) cannot exceed 1.0.
    // At maximum vertical thrust (1.0), the remaining budget for horizontal
    // motion is sqrt(1 - 1²) = 0, so the forward command is scaled to zero.
    // The wings/gondola stay at neutral while the aircraft climbs vertically.
    //
    // This prevents the aircraft from tilting its motors while also demanding
    // maximum climb, which would require more thrust than the motors can produce.
    // (config-independent)
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[THRUST_CHANNEL]  = pwm(1.0f); // thrust_cmd = 1.0 (full vertical)
    in.rc_in[FORWARD_CHANNEL] = pwm(1.0f); // forward_cmd = 1.0 (but will be zeroed)

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    // forward_cmd is scaled to 0 → atan2(0, 1) = 0° → no tilt
    CHECK_NEAR(0.0f, out.pitch_angle_norm, 0.01f);
    end_test();
}

// --- Lateral translation -----------------------------------------------------

void lateral_stick_tilts_thrust_vector_sideways_independently_of_forward()
{
    // The lateral command works symmetrically to the forward command but on
    // the roll axis. Pushing right tilts the thrust vector right (positive
    // roll_angle_norm). The pitch axis is unaffected.
    //
    // For the Blimp/Avatar with a single pitch-only tilt servo, roll_angle_norm
    // is computed by the TVC but the mixer does not connect it to any hardware
    // (there is no roll tilt servo). It is tracked here to confirm the TVC
    // core produces the correct value — a future vehicle with a roll servo
    // could use it directly.
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[LATERAL_CHANNEL] = pwm(0.5f); // 50% lateral (right)

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    CHECK_TRUE(out.roll_angle_norm > 0.0f);  // thrust tilted to the right
    CHECK_NEAR(0.0f, out.pitch_angle_norm, 0.001f); // forward axis unaffected

    end_test();
}

// --- Pitch compensation (stall prevention) -----------------------------------

void aircraft_pitching_up_shifts_wing_tilt_to_maintain_absolute_thrust_direction()
{
    // This is the stall-prevention mechanism. The TVC adds the aircraft's
    // current pitch angle to the target tilt angle so the thrust vector stays
    // pointed in the same absolute world direction even as the airframe rotates.
    //
    // Physical example: the aircraft pitches nose-up 20° (e.g., due to a gust
    // or stall onset). Without compensation the motors would also point 20°
    // backward relative to the ground, reducing forward thrust. The TVC adds
    // 20° to the servo command, rotating the motors back to the originally
    // intended direction.
    //
    // This is also how the wings naturally tilt upward at stall: elevator
    // saturates, the aircraft pitches up, and pitch compensation continuously
    // tilts the wings toward vertical to restore lift — no discrete mode switch.
    //
    // At forward=0.5, thrust=0.5, level aircraft:
    //   target = atan2(0.5, 0.5) = 45°  →  normalised = 45/90 = 0.5
    // Same stick inputs, aircraft pitched up 20°:
    //   target = 45° + 20° = 65°  →  normalised = 65/90 ≈ 0.722
    begin_test(__func__);

    TVCTestState state_level;
    TVC_CoreState core_level = state_level.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[FORWARD_CHANNEL] = pwm(0.5f);

    TVC_Outputs out_level = tvc_run_main_logic(in, core_level, tvc_config);

    TVCTestState state_pitched;
    TVC_CoreState core_pitched = state_pitched.core();
    in.pitch_rad = 20.0f * (float)M_PI / 180.0f; // 20° nose-up

    TVC_Outputs out_pitched = tvc_run_main_logic(in, core_pitched, tvc_config);

    CHECK_TRUE(out_pitched.pitch_angle_norm > out_level.pitch_angle_norm);
    CHECK_NEAR(0.722f, out_pitched.pitch_angle_norm, 0.01f); // 65° / 90°

    end_test();
}

// --- Safety: deadband prevents 180° servo flip at near-zero thrust ----------

void tiny_negative_thrust_is_clamped_to_zero_to_prevent_servo_flip()
{
    // atan2(y, x) with x < 0 and y ≈ 0 returns ≈ ±180°. Without protection,
    // a thrust command of -ε (e.g., from sensor noise or a tiny stick
    // misalignment) with zero forward input would produce atan2(0, -ε) ≈ 180°,
    // flipping the servo to full deflection — pointing the motors straight down
    // for the Blimp or locking the Avatar wings horizontal instantaneously.
    //
    // The deadband (VERTICAL_THROTTLE_DEADBAND = 0.05) clamps any thrust in
    // (-0.05, 0) to exactly 0.0 before the atan2 calculation, keeping the servo
    // at neutral when the pilot is near zero throttle.
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[THRUST_CHANNEL]  = pwm(-0.03f); // -0.03 is inside the ±0.05 deadband
    in.rc_in[FORWARD_CHANNEL] = 1500;         // neutral — no intentional forward

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    // Deadband forces thrust_cmd to 0.0 → atan2(0, 0) = 0° → servo stays neutral
    CHECK_NEAR(0.0f, out.pitch_angle_norm, 0.01f);
    end_test();
}

// --- VTOL mode: servo saturation clamp ---------------------------------------

void wing_tilt_is_always_clamped_to_minus_one_plus_one()
{
    // In VTOL mode, pitch_angle_norm is a normalised servo command sent to the
    // physical tilt servo. The servo has hard mechanical stops, so the software
    // must never command outside [-1, 1]. The TVC clamps the output and sets
    // the pitch_saturated flag so the PID's anti-windup can respond.
    //
    // This test drives the system past its limit: negative thrust produces
    // atan2(0, -0.5) = 180°, and a 10° aircraft pitch-up adds another 10°
    // via compensation, giving 190° → normalised 190/180 = 1.056 → clamped to 1.0.
    // (config-independent: any config value produces clamping at ±1)
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[THRUST_CHANNEL]  = pwm(-0.5f);
    in.rc_in[FORWARD_CHANNEL] = 1500;
    in.pitch_rad = 10.0f * (float)M_PI / 180.0f; // 10° nose-up

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    CHECK_TRUE(out.pitch_angle_norm <= 1.0f);  // hard upper limit
    CHECK_TRUE(out.pitch_angle_norm >= -1.0f); // hard lower limit
    CHECK_TRUE(state.pitch_saturated);         // flag set for anti-windup

    end_test();
}

// --- VTOL mode: transition blending ------------------------------------------
//
// ArduPilot's QuadPlane state machine sets TRANSITION_PROGRESS_CHANNEL:
//   0.0 (1000 µs) = pure hover / copter mode
//   1.0 (2000 µs) = fully in forward-flight / plane mode
//
// The TVC blends between two models:
//   Hover model:  computed from stick inputs via atan2 (adapts to pilot commands)
//   Forward-flight model: hardcoded to 1.0 (wings/gondola locked fully forward for cruise)
//
// output = (1 - transition) * hover_angle + transition * 1.0

void full_transition_progress_commands_full_forward_tilt_regardless_of_hover_stick()
{
    // At transition = 1.0 (cruise), the forward-flight model completely takes
    // over. The wings/gondola lock to their full-forward position so the vehicle
    // flies as a conventional fixed-wing. The hover TVC calculation is ignored.
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[TRANSITION_PROGRESS_CHANNEL] = 2000; // 1.0 = fully in plane mode

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    CHECK_NEAR(1.0f, out.pitch_angle_norm, 0.001f);
    end_test();
}

void zero_transition_progress_uses_pure_hover_tvc_calculation()
{
    // At transition = 0.0 (hover), the forward-flight model has zero weight.
    // The output is purely what the atan2 calculation produces from the sticks.
    // At forward=0.5, thrust=0.5, level: atan2(0.5, 0.5) = 45° → 45/90 = 0.5.
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[FORWARD_CHANNEL]             = pwm(0.5f);
    in.rc_in[TRANSITION_PROGRESS_CHANNEL] = 1000; // 0.0 = pure hover

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    CHECK_NEAR(0.5f, out.pitch_angle_norm, 0.01f); // 45° / 90° (avatar config)
    end_test();
}

void partial_transition_interpolates_between_hover_and_forward_flight_angle()
{
    // At 50% transition the output is the weighted average of the hover model
    // (0.5) and the forward-flight model (1.0):
    //   0.5 * 0.5  +  0.5 * 1.0  =  0.75
    // This provides a smooth mechanical transition with no discontinuities.
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.rc_in[FORWARD_CHANNEL]             = pwm(0.5f);
    in.rc_in[TRANSITION_PROGRESS_CHANNEL] = pwm(0.5f, 0.0f, 1.0f); // 1500 µs = 50%

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    CHECK_NEAR(0.75f, out.pitch_angle_norm, 0.01f);
    end_test();
}

// --- Safety: failsafe --------------------------------------------------------

void failsafe_zeroes_tilt_commands_regardless_of_stick_inputs()
{
    // On RC link loss (in_failsafe = true), all tilt commands go to zero.
    // This returns the servo to neutral (motors pointing straight up), which
    // is the safest state — the aircraft descends under gravity rather than
    // holding a tilt that would drive it laterally into an obstacle.
    // (config-independent)
    begin_test(__func__);

    TVCTestState state;
    TVC_CoreState core = state.core();
    TVC_Inputs in = neutral_hover_inputs();
    in.in_failsafe            = true;
    in.rc_in[FORWARD_CHANNEL] = pwm(1.0f); // full forward commanded, but ignored
    in.rc_in[LATERAL_CHANNEL] = pwm(1.0f);

    TVC_Outputs out = tvc_run_main_logic(in, core, tvc_config);

    CHECK_NEAR(0.0f, out.pitch_angle_norm, 0.001f);
    CHECK_NEAR(0.0f, out.roll_angle_norm,  0.001f);
    end_test();
}

// --- Total throttle ----------------------------------------------------------

void total_throttle_increases_with_tilt_because_motors_must_work_harder_to_maintain_lift()
{
    // total_throttle is the Euclidean magnitude of the 3D pilot command:
    //   sqrt(thrust_cmd² + forward_cmd² + lateral_cmd²)
    //
    // The mixer uses this to scale the motor output. When the servo tilts the
    // motors forward, their vertical thrust component decreases (cos(angle) < 1),
    // so the motors must spin faster to maintain the same vertical force. The
    // magnitude of the 3D vector captures this: tilting forward while keeping
    // thrust constant requires more total motor output.
    //
    // Concrete example:
    //   Pure hover, thrust=0.5:  magnitude = sqrt(0.5²) = 0.5
    //   Add forward=0.5:         magnitude = sqrt(0.5² + 0.5²) ≈ 0.707
    // The motors now need to produce ~41% more total thrust to maintain the
    // same vertical component they had in pure hover.
    begin_test(__func__);

    TVCTestState state_hover;
    TVC_CoreState core_hover = state_hover.core();
    TVC_Inputs in = neutral_hover_inputs(); // thrust=0.5, forward=0
    TVC_Outputs out_hover = tvc_run_main_logic(in, core_hover, tvc_config);
    CHECK_NEAR(0.5f, out_hover.total_throttle, 0.001f);

    TVCTestState state_tilted;
    TVC_CoreState core_tilted = state_tilted.core();
    in.rc_in[FORWARD_CHANNEL] = pwm(0.5f); // same thrust + forward command added
    TVC_Outputs out_tilted = tvc_run_main_logic(in, core_tilted, tvc_config);

    CHECK_TRUE(out_tilted.total_throttle > out_hover.total_throttle);
    CHECK_NEAR(0.707f, out_tilted.total_throttle, 0.01f); // sqrt(0.5² + 0.5²)

    end_test();
}

// ============================================================================
// Main
// ============================================================================

int main()
{
    std::printf("=== TVC Core Unit Tests ===\n");
    std::printf("Production files: TVC_Core.cpp, TVC_PID.cpp, TVC_Filters.cpp\n");
    std::printf("Active config:    g_config = avatarConfig (ACTIVE_CONFIG = 1)\n");
    std::printf("  forward_flight_physical_angle_deg = 90 (avatar)\n");
    std::printf("  Blimp would use 180 — numeric expectations scale proportionally\n");
    std::printf("Active modes:     VTOL_MODE=true  OPEN_LOOP_SERVO_MODE=true\n");

    neutral_sticks_in_hover_produce_zero_tilt_and_half_throttle();
    forward_stick_tilts_thrust_vector_forward_not_the_nose();
    zero_thrust_with_full_forward_stick_tilts_to_exactly_horizontal();
    full_throttle_leaves_no_budget_for_forward_motion();
    lateral_stick_tilts_thrust_vector_sideways_independently_of_forward();
    aircraft_pitching_up_shifts_wing_tilt_to_maintain_absolute_thrust_direction();
    tiny_negative_thrust_is_clamped_to_zero_to_prevent_servo_flip();
    wing_tilt_is_always_clamped_to_minus_one_plus_one();
    full_transition_progress_commands_full_forward_tilt_regardless_of_hover_stick();
    zero_transition_progress_uses_pure_hover_tvc_calculation();
    partial_transition_interpolates_between_hover_and_forward_flight_angle();
    failsafe_zeroes_tilt_commands_regardless_of_stick_inputs();
    total_throttle_increases_with_tilt_because_motors_must_work_harder_to_maintain_lift();

    std::printf("\n=== Results: %d checks, %d failed ===\n",
                g_checks_run, g_checks_failed);
    return g_checks_failed > 0 ? 1 : 0;
}
