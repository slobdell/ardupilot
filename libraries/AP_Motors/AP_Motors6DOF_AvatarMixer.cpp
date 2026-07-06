#ifndef MIXER_STANDALONE_BUILD
#include "AP_Motors6DOF.h"
#endif
#include "AP_Motors6DOF_AvatarMixer.h"
#include <AP_HAL/AP_HAL.h>

// Set to 1 to enable periodic debug logging via MAVLink text messages.
// Logs once every 3 seconds. Disable before production flights.
// Override with -DAVATAR_DEBUG_LOG=0 on the compiler command line to suppress.
#ifndef AVATAR_DEBUG_LOG
#define AVATAR_DEBUG_LOG 1
#endif

#if AVATAR_DEBUG_LOG
#include <GCS_MAVLink/GCS.h>
#include <AP_Logger/AP_Logger.h>
#endif

namespace AP_Motors6DOF_Mixer {

#define AVATAR_MOT_WING_LEFT  0
#define AVATAR_MOT_WING_RIGHT 1
#define AVATAR_MOT_YAW_RIGHT  2
#define AVATAR_MOT_YAW_LEFT   3

const float AVATAR_MANUAL_YAW_DEADBAND = 0.05f;

// [AV-INVAR:mode-transition-blend] — sentinel meaning "no previous mode seen":
// blending is impossible until one full frame in a mode has been recorded.
static const uint8_t AVATAR_MODE_ID_NONE = 255;

// [AV-INVAR:fs-ground-disarm] — commanded trim thrust below this magnitude counts as
// "quiet" for the ground-disarm clock. Any airborne regime commands well above it
// (STABILIZE hover: pilot stick; CRUISE: TECS holds >= ~TRIM even with stick at bottom).
static const float AVATAR_THRUST_QUIET_THRESH = 0.05f;
// Cap so the clock cannot grow unbounded across a long parked-armed session.
static const float AVATAR_THRUST_QUIET_CAP_S = 600.0f;

// [AV-INVAR:mode-transition-blend] — see Avatar_Design.md § 9
// Blend the branch's live commanded trim vector with the snapshot frozen at the
// last flight-mode edge. Interpolation is done in FORCE SPACE (horizontal,
// vertical thrust components), never on tilt/throttle independently — the
// midpoint of two (tilt, throttle) pairs is not the midpoint of their net
// forces. Recompose uses the same saturation rule as the dampening block:
// preserve vertical lift, give horizontal the remaining headroom.
// Stabilisation terms (roll/pitch/yaw deltas, rear mixing) are NEVER blended —
// they are applied by the caller around the blended trim and stay live.
static void apply_mode_transition_blend(MixerState& state,
                                        float live_tilt_deg, float live_throttle,
                                        float& out_tilt_deg, float& out_throttle,
                                        MixerOutputs& outputs)
{
    const float b = state.mode_blend;   // 0 = all snapshot, 1 = all live
    const float fh_live = live_throttle * sinf(radians(live_tilt_deg));
    const float fv_live = live_throttle * cosf(radians(live_tilt_deg));
    const float fh = state.snap_thrust_horiz * (1.0f - b) + fh_live * b;
    const float fv = state.snap_thrust_vert  * (1.0f - b) + fv_live * b;
    const float mag = sqrtf(fh * fh + fv * fv);
    if (mag > 1.0f) {
        const float vc = constrain_float(fv, 0.0f, 1.0f);
        const float hr = sqrtf(fmaxf(0.0f, 1.0f - vc * vc));
        out_tilt_deg = degrees(atan2f(copysignf(hr, fh), vc));
        out_throttle = 1.0f;
    } else {
        out_tilt_deg = degrees(atan2f(fh, fv));
        out_throttle = mag;
    }
    out_tilt_deg = constrain_float(out_tilt_deg,
        g_config.reverse_flight_physical_angle_deg,
        g_config.forward_flight_physical_angle_deg);
    // Anti-windup: while the blend suppresses the live vertical demand, assert the
    // throttle limit flags so upstream closed-loop controllers (AC_PosControl Z)
    // freeze their integrators instead of winding against thrust they are not
    // getting — otherwise the wound-up I discharges as a surge when the blend ends.
    if (fv < fv_live - 0.01f) { outputs.limit.throttle_upper = true; }
    if (fv > fv_live + 0.01f) { outputs.limit.throttle_lower = true; }
}

// Maximum forward/lateral input observed from the radio at full stick deflection.
// ArduPlane's Q_ANGLE_MAX (currently 30 deg) caps the pitch demand fed into the
// 6DOF attitude controller, so set_forward never reaches 1.0 even at full stick.
// Dividing by this constant re-normalises full-stick to 1.0 so the TVC sees the
// full -1..1 range. Adjust if Q_ANGLE_MAX or the radio calibration changes.
const float AVATAR_FORWARD_INPUT_MAX = 0.42f;

void AvatarMixer::setup_motors(::AP_Motors6DOF* backend)
{
#ifndef MIXER_STANDALONE_BUILD
    const float yawFactor = 1.0f;
    const float noInput   = 0.0f;
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_1, noInput, noInput, noInput, 1.0f, noInput, noInput, 1);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_2, noInput, noInput, noInput, 1.0f, noInput, noInput, 2);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_3, noInput, noInput, yawFactor, 0.0f, noInput, noInput, 3);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_4, noInput, noInput, yawFactor, 0.0f, noInput, noInput, 4);
#endif
}

void AvatarMixer::mix(const MixerInputs& inputs, MixerState& state, MixerOutputs& outputs)
{
    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) outputs.motor_thrust[i] = 0.0f;
    outputs.limit.roll = outputs.limit.pitch = outputs.limit.yaw = false;
    outputs.limit.throttle_lower = outputs.limit.throttle_upper = false;
    outputs.tilt_angle = 0.0f;
    outputs.rudder_out = 0.0f;
    outputs.elevator_out = 0.0f;
    outputs.aileron_out = 0.0f;

    bool in_plane_mode = (inputs.plane.transition_progress > 0.5f);

    // [AV-INVAR:mode-transition-blend] — flight-mode edge detection & blend clock.
    // Only in-flight (THROTTLE_UNLIMITED) mode changes start a blend: while on the
    // ground / spooling, mode tracking is reset so arming or ground mode churn can
    // never blend from a stale or zero snapshot.
    if (inputs.spool_state != AP_Motors::SpoolState::THROTTLE_UNLIMITED) {
        state.last_mode_id = AVATAR_MODE_ID_NONE;
        state.mode_blend = 1.0f;
    } else {
        if (state.last_mode_id != AVATAR_MODE_ID_NONE &&
            inputs.plane.control_mode_id != state.last_mode_id) {
            // Mode changed in flight: freeze last frame's trim vector as the snapshot.
            state.snap_thrust_horiz = state.last_thrust_horiz;
            state.snap_thrust_vert  = state.last_thrust_vert;
            state.mode_blend = 0.0f;
        }
        state.last_mode_id = inputs.plane.control_mode_id;
        if (state.mode_blend < 1.0f) {
            const float blend_s = (inputs.plane.transition_blend_s > 0.01f)
                                  ? inputs.plane.transition_blend_s : 1.5f;
            state.mode_blend = fminf(1.0f, state.mode_blend + inputs.dt / blend_s);
        }
    }

    // [AV-INVAR:fs-ground-disarm] — commanded-thrust quiet clock. Uses the previous
    // frame's recorded trim vector (one-frame lag is irrelevant against a multi-second
    // window). Not spooled up counts as quiet: commanded thrust is zero by definition.
    {
        const float cmd_mag = sqrtf(state.last_thrust_horiz * state.last_thrust_horiz +
                                    state.last_thrust_vert  * state.last_thrust_vert);
        if (inputs.spool_state != AP_Motors::SpoolState::THROTTLE_UNLIMITED ||
            cmd_mag < AVATAR_THRUST_QUIET_THRESH) {
            state.thrust_quiet_s = fminf(state.thrust_quiet_s + inputs.dt,
                                         AVATAR_THRUST_QUIET_CAP_S);
        } else {
            state.thrust_quiet_s = 0.0f;
        }
    }

    if (in_plane_mode) {
        // =====================================================================
        // --- STATE B: PLANE MODE ---
        // Tilt is either rate-controlled (STABILIZE) or position-controlled (FBWA/auto).
        // Elevator holds level via the copter attitude PID in both sub-modes.
        // =====================================================================
        state.manual_override_active = false;

        float throttle_pct = inputs.plane.throttle_pct * 0.01f;

        // [AV-INVAR:mode-transition-blend] — supersedes the old 0.5 s copter→plane
        // throttle-only blend. Tilt continuity in plane mode is owned by the slew
        // machinery ([AV-INVAR:plane-tilt-slew] / rate mode), so the snapshot
        // direction ≈ the live direction here and the vector blend reduces to a
        // throttle-magnitude handoff; the blended tilt angle is intentionally not
        // written back (it would fight the slew's bookkeeping).
        if (state.mode_blend < 1.0f) {
            float blended_tilt_deg, blended_throttle;
            apply_mode_transition_blend(state, state.current_tilt_deg, throttle_pct,
                                        blended_tilt_deg, blended_throttle, outputs);
            throttle_pct = blended_throttle;
            (void)blended_tilt_deg;
        }

        {
            if (inputs.plane.tilt_rate_mode) {
                // [AV-INVAR:stabilize-tilt-rate-control] — see Avatar_Design.md § 9
                // Stick updates pilot_tilt_deg (intent). Dampening computes a combined tilt
                // target from the force-vector decomposition. current_tilt_deg slews toward
                // that combined target in ONE rate-limited step.
                //
                // Previously: tilt rate control slewed toward pilot_tilt_deg, then dampening
                // slewed toward new_tilt_deg — both using the same rate limit in opposite
                // directions, cancelling each other every frame. The unified slew fixes this.
                // pilot_tilt_deg is still preserved so current_tilt_deg recovers to pilot
                // intent when dampening ends.
                //
                // Throttle: new_throttle is the additive, geometrically correct magnitude for
                // the full demanded force vector at the target tilt. It is not corrected for the
                // current servo position during the slew — doing so would increase both vertical
                // AND forward thrust proportionally, worsening a sink caused by excess forward
                // tilt. The correct lever for faster dampening authority is Q_TILT_RATE_UP.
                float rate = std::max(1.0f, inputs.tilt_rate_up_dps) * inputs.plane.pitch_tilt_demand;
                state.pilot_tilt_deg -= rate * inputs.dt;
                state.pilot_tilt_deg = constrain_float(state.pilot_tilt_deg,
                    g_config.reverse_flight_physical_angle_deg,
                    g_config.forward_flight_physical_angle_deg);

                // Default: track pilot intent. Dampening overrides with the combined target.
                float tilt_target_deg = state.pilot_tilt_deg;

                // [AV-INVAR:sink-damp] and [AV-INVAR:long-damp] — see Avatar_Design.md § 9
                const bool has_vert_damp  = (inputs.plane.damp_vert_thrust  > 0.0f);
                const bool has_horiz_damp = (fabsf(inputs.plane.damp_horiz_thrust) > 1e-4f);
                if (has_vert_damp || has_horiz_damp) {
                    // Decompose from pilot intent — dampening is additive on top of pilot's
                    // commanded thrust vector, not compounded off the already-dampened position.
                    float sin_t = sinf(radians(state.pilot_tilt_deg));
                    float cos_t = cosf(radians(state.pilot_tilt_deg));
                    float thrust_horiz = throttle_pct * sin_t + inputs.plane.damp_horiz_thrust;
                    float thrust_vert  = throttle_pct * cos_t + inputs.plane.damp_vert_thrust;
                    float new_throttle = sqrtf(thrust_horiz * thrust_horiz + thrust_vert * thrust_vert);
                    if (new_throttle > 1.0f) {
                        // Saturated: preserve vertical lift, allocate remaining headroom to horizontal.
                        // copysignf preserves the direction of the horizontal demand.
                        float thrust_vert_clamped = constrain_float(thrust_vert, 0.0f, 1.0f);
                        float horiz_remaining     = sqrtf(fmaxf(0.0f, 1.0f - thrust_vert_clamped * thrust_vert_clamped));
                        tilt_target_deg = degrees(atan2f(copysignf(horiz_remaining, thrust_horiz), thrust_vert_clamped));
                        throttle_pct = 1.0f;
                    } else {
                        tilt_target_deg = degrees(atan2f(thrust_horiz, thrust_vert));
                        throttle_pct = new_throttle;
                    }
                    tilt_target_deg = constrain_float(tilt_target_deg,
                        g_config.reverse_flight_physical_angle_deg,
                        g_config.forward_flight_physical_angle_deg);
                }

                // Single rate-limited slew toward combined target (bidirectional: dampening
                // can tilt forward or back depending on longitudinal demand).
                const float rate_clamp = std::max(1.0f, inputs.tilt_rate_up_dps) * inputs.dt;
                state.current_tilt_deg += constrain_float(
                    tilt_target_deg - state.current_tilt_deg, -rate_clamp, rate_clamp);
            } else {
                // [AV-INVAR:plane-tilt-slew] — see Avatar_Design.md § 9
                // Position control: nav_pitch_cd (pilot + TECS) sets the target; state.current_tilt_deg
                // slews toward it — fast toward vertical (stall recovery), slow toward horizontal
                // (airspeed must build before wing lift is needed).
                // cruise_norm separates servo physical max from cruise equilibrium angle (§ 4.4.3).
                // Neutral stick → cruise_physical_angle_deg. Full pitch-down → forward_flight_physical_angle_deg.
                float cruise_norm = g_config.cruise_physical_angle_deg / fmaxf(g_config.forward_flight_physical_angle_deg, 0.1f);
                float target_tilt_angle = constrain_float(cruise_norm * (1.0f - inputs.plane.pitch_tilt_demand), 0.0f, 1.0f);
                float target_tilt_deg   = target_tilt_angle * g_config.forward_flight_physical_angle_deg;
                float rate_up = std::max(1.0f, inputs.tilt_rate_up_dps);
                float rate_dn = std::max(1.0f, inputs.tilt_rate_down_dps > 0.0f
                                              ? inputs.tilt_rate_down_dps
                                              : inputs.tilt_rate_up_dps);
                state.current_tilt_deg = constrain_float(target_tilt_deg,
                    state.current_tilt_deg - (rate_up * inputs.dt),   // toward vertical: fast
                    state.current_tilt_deg + (rate_dn * inputs.dt));  // toward horizontal: slow
                // [AV-INVAR:stabilize-tilt-rate-control] — mirror of the copter-branch
                // sync: keep pilot intent pinned to the physical tilt so a switch into
                // STABILIZE rate mode starts from the current position. Without this,
                // CRUISE/AUTO→STABILIZE slews toward a stale pilot_tilt_deg (typically
                // ~vertical from the last Q-mode session) at Q_TILT_RATE_UP — the fast
                // direction — slamming the rotors vertical at cruise speed.
                state.pilot_tilt_deg = state.current_tilt_deg;
            }
            outputs.tilt_angle = state.current_tilt_deg >= 0.0f
                ? state.current_tilt_deg / g_config.forward_flight_physical_angle_deg
                : state.current_tilt_deg / fabsf(g_config.reverse_flight_physical_angle_deg);
        }

        // Elevator: copter attitude PID output — same signal and same sign as the rear motor.
        // Both actuators cooperate to hold the fuselage level; gain may need flight tuning.
        // [AV-INVAR:elevator-follows-pitch-pid] — see Avatar_Design.md § 9
        outputs.elevator_out = inputs.pitch;

        // cos(tilt): 1 at wings-vertical (hover), 0 at wings-horizontal (cruise). Scales the
        // roll differential, the yaw differential, and — via the wing motor's own tilt
        // projecting its thrust onto the vertical axis — the pitch couple below. All fade as
        // the aerodynamic surfaces (ailerons, elevator) take over through the transition.
        float cos_tilt_b = fmaxf(0.0f, cosf(radians(state.current_tilt_deg)));

        // --- Pitch couple: front (wing) pair vs rear pair ------------------------------
        // [AV-INVAR:plane-pitch-couple] — see Avatar_Design.md § 4.4.1 / § 9.
        // Give the plane branch a real pitch actuator: the front pair carries +inputs.pitch
        // and the rear pair carries −inputs.pitch, forming a couple (front-down + rear-up =
        // a pure nose-down moment, and vice versa) at the pilot/dampener-set tilt — the servo
        // is NOT touched. Before this, only the rear pair carried pitch; at high throttle the
        // rear (which pushes the nose down by ADDING thrust) railed with no headroom left and
        // the nose departed uncontrollably (log 00000093.BIN). The front pair supplies the
        // missing half using its own magnitude range (it had ample downward room in that log).
        //
        // Both pitch terms are gated by cos_tilt_b = fmaxf(0, cos_tilt), and this gate is
        // MANDATORY on the front, not cosmetic. A wing motor's vertical component is
        // T·cos_tilt, which is zero at horizontal (90°) and NEGATIVE past it — the servo
        // travels to forward_flight_physical_angle_deg = 95° on full pitch-down (§ 4.4.3
        // descent). An ungated front term (throttle + inputs.pitch) would add pure forward
        // thrust at 90° (an airspeed kick, no pitch) and INVERT past 90° (adding thrust when
        // the motor points forward-and-down pushes the nose the WRONG way — positive feedback).
        // Gating by fmaxf(0, cos_tilt) fades the front pitch contribution smoothly to zero by
        // horizontal and holds it at zero past it, handing pitch to the elevator exactly where
        // § 4.4.3 intends.
        //
        // Consequence (Option A, chosen): the front's VERTICAL pitch authority is
        // inputs.pitch·cos²_tilt (gate × projection) while the rear's is inputs.pitch·cos_tilt,
        // so the couple is not perfectly balanced — a pitch demand leaks ≤ ~0.25·pitch of net
        // vertical force into altitude in mid-transition (peaks ~60°, absorbed by the sink
        // dampener). Negligible near hover, where cos² ≈ cos — and near hover is the regime that
        // departed in log 00000093.BIN, so the fix that matters is unaffected. The whole couple's
        // plant gain becomes inputs.pitch·cos_tilt·(1+cos_tilt): a smooth monotonic fade from 2
        // (both actuators, hover) to 0 (cruise), never negative, matched to the I-handoff
        // (`[AV-INVAR:cos-tilt-i-zero]`). NEVER divide by cos_tilt to "rebalance" the couple —
        // that restores balance but blows up at horizontal, which is the fade we actually want.
        float front_common = throttle_pct + inputs.pitch * cos_tilt_b;
        float rear_common  = (throttle_pct - inputs.pitch) * cos_tilt_b;

        // [AV-INVAR:pitch-before-throttle] — cross-pair transfer (mirror of the copter branch).
        // When one pair rails at 1.0 it cannot deliver the pitch demanded of it; take the
        // undeliverable part out of the OTHER pair's common mode instead of truncating it. This
        // spends common-mode lift (recoverable) to preserve pitch authority (a departure is not),
        // and is the piece that makes the rear-railed log-00000093 case survivable — the front
        // gives up its excess so the nose-down moment is still produced. Division-free and
        // lift-reducing only: low-side clips (a pair railed at 0) are truncated, never boosted
        // onto the other pair, so a wound-up PID can never spin motors up near the ground.
        // No-op when unsaturated — tuned normal flight is bit-for-bit unchanged.
        const float front_excess = fmaxf(0.0f, front_common - 1.0f);
        rear_common -= front_excess * cos_tilt_b;
        const float rear_excess = fmaxf(0.0f, rear_common - 1.0f);
        front_common -= rear_excess;
        // Anti-windup: pitch is undelivered only if the receiving pair also ran out of headroom.
        outputs.limit.pitch = (front_common < 0.0f) || (rear_common < 0.0f);
        front_common = constrain_float(front_common, 0.0f, 1.0f);
        rear_common  = constrain_float(rear_common,  0.0f, 1.0f);

        // Front (wing) pair: pitch common mode ± roll differential. Roll fades to zero at
        // wings-horizontal where aileron authority is full; p_shift preserves the roll
        // differential by sacrificing front common mode symmetrically when a wing would clip.
        float roll_delta  = inputs.roll * cos_tilt_b;
        float p_left_raw  = front_common + roll_delta;
        float p_right_raw = front_common - roll_delta;
        float p_excess_high = fmaxf(0.0f, fmaxf(p_left_raw, p_right_raw) - 1.0f);
        float p_excess_low  = fmaxf(0.0f, -fminf(p_left_raw, p_right_raw));
        float p_shift = p_excess_high - p_excess_low;
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = constrain_float(p_left_raw  - p_shift, 0.0f, 1.0f);
        outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = constrain_float(p_right_raw - p_shift, 0.0f, 1.0f);
        outputs.aileron_out  = -inputs.plane.aileron_input / 4500.0f;

        // Yaw: all nav plane modes (STABILIZE, CRUISE, AUTO, ...) use the copter attitude
        // PID (inputs.yaw); manual-family modes (MANUAL/ACRO/TRAINING) use raw rudder stick.
        // [AV-INVAR:stabilize-yaw-pid] and [AV-INVAR:yaw-handoff-cos-tilt] — see Avatar_Design.md § 9
        const float yaw_norm = inputs.plane.use_pid_yaw
            ? inputs.yaw
            : (inputs.plane.rudder_input / 4500.0f);
        outputs.rudder_out = yaw_norm;
        // [AV-INVAR:rear-pitch-priority] — the rear pair carries the pitch/throttle common mode
        // (rear_common, computed above with the cross-pair transfer already applied) AND the yaw
        // differential on two shared actuators. Prioritize the common mode: it keeps the aircraft
        // stable (pitch); yaw only holds heading. Give yaw only the symmetric headroom that
        // remains around rear_common, so a large yaw demand can never rail a rear motor and
        // starve pitch. A leftover full yaw split did exactly that → STABILIZE nose-up departure
        // (log 00000072.BIN). No-op in the unsaturated case.
        float yaw_room    = fminf(rear_common, 1.0f - rear_common);
        float yaw_demand  = yaw_norm * cos_tilt_b;
        float yaw_delta_b = constrain_float(yaw_demand, -yaw_room, yaw_room);
        outputs.limit.yaw = (fabsf(yaw_demand) > yaw_room + 1e-4f);
        outputs.motor_thrust[AVATAR_MOT_YAW_LEFT]  = rear_common + yaw_delta_b;
        outputs.motor_thrust[AVATAR_MOT_YAW_RIGHT] = rear_common - yaw_delta_b;

        // [AV-INVAR:mode-transition-blend] — record this frame's final commanded trim
        // vector (throttle_pct is post-dampeners and post-blend, so the snapshot taken
        // at a future mode edge includes everything the dampeners were contributing).
        state.last_thrust_horiz = throttle_pct * sinf(radians(state.current_tilt_deg));
        state.last_thrust_vert  = throttle_pct * cosf(radians(state.current_tilt_deg));

#if AVATAR_DEBUG_LOG
        {
            static uint32_t last_avb_ms = 0;
            uint32_t now_ms = AP_HAL::millis();
            if (now_ms - last_avb_ms >= 1000) {
                last_avb_ms = now_ms;
                gcs().send_text(MAV_SEVERITY_INFO,
                    "AVB tilt_demand=%.2f tilt_out=%.2f elev=%.2f",
                    (double)inputs.plane.pitch_tilt_demand,
                    (double)outputs.tilt_angle,
                    (double)outputs.elevator_out);
            }
        }
#endif

    } else {
        // =====================================================================
        // --- STATE C: COPTER MODE (TVC Brain) ---
        // =====================================================================
        state.manual_override_active = false;
        if (inputs.spool_state == AP_Motors::SpoolState::SHUT_DOWN) {
            state.current_tilt_deg = 0.0f;
            state.pilot_tilt_deg   = 0.0f;
            return;
        }
        if (inputs.spool_state == AP_Motors::SpoolState::GROUND_IDLE) {
            // Guarantee DShot 0 to all motors during ground idle so ESCs can
            // complete their arming timer. The full mixer must not run here —
            // a negative pitch PID value produces rear_thrust > 0, which resets
            // the ESC arming timer and leaves the rear motors permanently unarmed.
            return;
        }

        TVC_Inputs tvc_in;
        tvc_in.now_us = AP_HAL::micros();
        tvc_in.ahrs_healthy = inputs.ahrs_healthy;
        tvc_in.in_failsafe = !inputs.is_armed;
        tvc_in.roll_rad = inputs.ahrs_roll_rad;
        tvc_in.pitch_rad = inputs.ahrs_pitch_rad;
        tvc_in.gyro.x = inputs.gyro.x;
        tvc_in.gyro.y = inputs.gyro.y;
        tvc_in.gyro.z = inputs.gyro.z;

        auto f2pwm = [](float v, float min, float max) -> int {
            return 1000 + (int)((constrain_float(v, min, max) - min) / (max - min) * 1000);
        };

        for (int k = 0; k < 16; k++) tvc_in.rc_in[k] = 1500;
        // inputs.throttle is 0..1 from get_throttle() (non-reversible motors)
        // TVC brain interprets THRUST_CHANNEL as -1..1 centered on 1500 (1500=idle, 2000=full).
        // Avatar has no negative thrust, so map 0..1 → 1500..2000 (positive half only).
        // Using the full 1000..2000 range would make stick-down look like full reverse thrust
        // to the TVC (sqrtf magnitude), producing thr=1.0 at both extremes.
        tvc_in.rc_in[THRUST_CHANNEL]              = 1500 + (int)(inputs.throttle * 500.0f);
        tvc_in.rc_in[FORWARD_CHANNEL]             = f2pwm(inputs.forward  / AVATAR_FORWARD_INPUT_MAX, -1.0f, 1.0f);
        tvc_in.rc_in[LATERAL_CHANNEL]             = f2pwm(inputs.lateral  / AVATAR_FORWARD_INPUT_MAX, -1.0f, 1.0f);
        tvc_in.rc_in[TRANSITION_PROGRESS_CHANNEL] = f2pwm(inputs.plane.transition_progress, 0.0f, 1.0f);

        TVC_CoreState tvc_s = state.get_tvc_state();
        TVC_Outputs tvc_out = tvc_run_main_logic(tvc_in, tvc_s, tvc_config);

        // Cap at cruise_norm so copter mode never commands past horizontal (§ 4.4.3).
        float cruise_norm_c = g_config.cruise_physical_angle_deg / fmaxf(g_config.forward_flight_physical_angle_deg, 0.1f);
        outputs.tilt_angle = constrain_float(tvc_out.pitch_angle_norm, -1.0f, cruise_norm_c);
        float throttle_thrust = tvc_out.total_throttle;
        outputs.debug_data = tvc_out.debug_data;

        // [AV-INVAR:mode-transition-blend] — on plane→copter entry the TVC would
        // command its target (typically near-vertical) to the servo INSTANTLY
        // ([AV-INVAR:tilt-servo-tracking] sends the full target immediately), which
        // is the abrupt motor tilt observed at STABILIZE→QSTABILIZE. During the
        // blend window the servo command, the tracking-model target, and the
        // throttle all follow the blended force vector instead. The blend moves the
        // command far slower than the servo's physical rate, so the tracking-model
        // error stays small and the cos(error) compensation below naturally stays ≈1.
        // The cruise_norm cap is intentionally bypassed while blending: a plane-mode
        // snapshot may sit past 90° (descent trim); clamping it would reintroduce a
        // step at entry. The blend itself walks the angle below 90° within the window.
        float tvc_target_deg = tvc_out.debug_data.target_pitch_deg;
        if (state.mode_blend < 1.0f) {
            const float live_target_deg = constrain_float(tvc_target_deg,
                g_config.reverse_flight_physical_angle_deg,
                g_config.forward_flight_physical_angle_deg);
            float blended_deg, blended_throttle;
            apply_mode_transition_blend(state, live_target_deg, throttle_thrust,
                                        blended_deg, blended_throttle, outputs);
            tvc_target_deg  = blended_deg;
            throttle_thrust = blended_throttle;
            outputs.tilt_angle = blended_deg >= 0.0f
                ? blended_deg / g_config.forward_flight_physical_angle_deg
                : blended_deg / fmaxf(fabsf(g_config.reverse_flight_physical_angle_deg), 0.1f);
        }

        // [AV-INVAR:tilt-servo-tracking] — see Avatar_Design.md § 9
        // outputs.tilt_angle (servo command) is already set to the TVC target above.
        // state.current_tilt_deg is a rate-limited model of where the servo physically is.
        // Motor mixing (cos_tilt, roll authority, rear motor) and throttle scaling all use
        // the physical position so they remain correct while the servo is still travelling.
        float tilt_rate = std::max(1.0f, inputs.tilt_rate_up_dps);
        // NOTE: outputs.tilt_angle (servo command) is capped at cruise_norm_c (90°) above, but
        // target_deg here is the raw TVC target and can exceed cruise_physical_angle_deg if the
        // TVC saturates (extreme forward stick + nose-up). If that happens, state.current_tilt_deg
        // drifts past 90° while the servo stays at 90°. On a copter→plane mode switch, plane mode
        // derives its servo command from state.current_tilt_deg, so it would command slightly past
        // horizontal — a small forward jerk. Fix if it matters: cap target_deg at
        // g_config.cruise_physical_angle_deg before the constrain below.
        // During a mode-transition blend, target_deg is the blended command instead
        // so the tracking model follows the servo. [AV-INVAR:mode-transition-blend]
        float target_deg = tvc_target_deg;
        state.current_tilt_deg = constrain_float(target_deg,
            state.current_tilt_deg - (tilt_rate * inputs.dt),
            state.current_tilt_deg + (tilt_rate * inputs.dt));
        // [AV-INVAR:stabilize-tilt-rate-control] — keep pilot intent in sync with where
        // the TVC actually leaves the servo. Without this, switching back to STABILIZE
        // slews toward a stale pilot_tilt_deg from a previous STABILIZE session, causing
        // the servo to jump. With this, the STABILIZE path starts from the current position.
        state.pilot_tilt_deg = state.current_tilt_deg;
        float error_deg = fabsf(state.current_tilt_deg - target_deg);
        throttle_thrust *= constrain_float(cosf(radians(error_deg)), 0.0f, 1.0f);
        // TODO: this cos(error) scaling reduces throttle symmetrically regardless of which
        // direction the servo is traveling. When the servo is heading toward vertical (braking/
        // deceleration), the servo is more horizontal than the target and vertical thrust is
        // under-produced — scaling down makes it worse. The correct fix mirrors the plane-mode
        // dampening approach: throttle = desired_vert / cos(state.current_tilt_deg). Tolerable
        // here because the altitude controller closes the loop; plane mode has no such fallback.

        // cos_tilt is floored at zero so that roll effectiveness and rear motor
        // fade to zero at 90° and stay there if servo range extends past 90°.
        float cos_tilt = fmaxf(0.0f, cosf(radians(state.current_tilt_deg)));

        // Roll scales with how vertical the motors are; zero at 90° and beyond.
        float roll_effectiveness = cos_tilt;
        // Pitch is added directly to front motors without tilt scaling — the TVC brain adapts
        // the tilt angle in response to attitude changes, so the two loops don't fight each other.
        // Headroom is computed around the pitch-shifted base to keep roll clipping symmetric.
        float base_thrust = throttle_thrust + inputs.pitch;
        float rear_thrust = (inputs.throttle - inputs.pitch) * cos_tilt;
        // [AV-INVAR:pitch-before-throttle] — cross-pair transfer of undeliverable pitch.
        // When one pair rails at 1.0, the pitch it could not deliver is taken out of the
        // other pair's common mode instead of being truncated. Without this, throttle
        // saturation halves the pitch loop gain exactly when the disturbance is largest
        // (full-throttle spool transient → flip risk). Costs lift, which is recoverable;
        // a pitch departure is not. Lift-reducing only: low-side clips (motor railed at 0)
        // are NOT boosted on the other pair, so a wound-up PID can never spin motors up
        // near the ground. No-op in the unsaturated case.
        const float front_excess = fmaxf(0.0f, base_thrust - 1.0f);
        rear_thrust -= front_excess * cos_tilt;
        const float rear_excess = fmaxf(0.0f, rear_thrust - 1.0f);
        base_thrust -= rear_excess;
        // Anti-windup fires only if pitch remains undelivered after the transfer —
        // i.e. the receiving pair also ran out of downward headroom.
        outputs.limit.pitch = (base_thrust < 0.0f) || (rear_thrust < 0.0f);
        base_thrust = constrain_float(base_thrust, 0.0f, 1.0f);
        // [AV-INVAR:mode-transition-blend] — record this frame's final commanded trim
        // vector (collective only: the inputs.pitch stabilisation delta is deliberately
        // excluded — stabilisation is never blended, only the trim point).
        state.last_thrust_horiz = throttle_thrust * sinf(radians(state.current_tilt_deg));
        state.last_thrust_vert  = throttle_thrust * cosf(radians(state.current_tilt_deg));
        float desired_roll = inputs.roll * roll_effectiveness;
        // De-saturate by shifting both motors equally so the roll differential is
        // preserved even when throttle has pushed base_thrust to 1.0. Sacrifices
        // total thrust headroom rather than silencing roll authority entirely.
        float left_raw    = base_thrust + desired_roll;
        float right_raw   = base_thrust - desired_roll;
        float excess_high = fmaxf(0.0f, fmaxf(left_raw, right_raw) - 1.0f);
        float excess_low  = fmaxf(0.0f, -fminf(left_raw, right_raw));
        float shift = excess_high - excess_low;
        float left_out  = constrain_float(left_raw  - shift, 0.0f, 1.0f);
        float right_out = constrain_float(right_raw - shift, 0.0f, 1.0f);
        outputs.limit.roll = (fabsf(desired_roll) > fabsf(left_out - right_out) / 2.0f + 1e-4f);
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = left_out;
        outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = right_out;
        // Rear motors fade to zero at 90° and stay off beyond — fixed-direction thrust
        // loses pitch relevance (and would invert without the floor) past 90°.
        // rear_thrust computed above (with [AV-INVAR:pitch-before-throttle] transfer applied).
        // Yaw: attitude PID output drives differential between the two rear motors, fading
        // with cos_tilt. [AV-INVAR:yaw-handoff-cos-tilt] — see Avatar_Design.md § 9
        // [AV-INVAR:rear-pitch-priority] — same shared-actuator priority as the plane branch:
        // preserve the pitch/throttle common mode, give yaw only the leftover symmetric
        // headroom so it can never rail a rear motor and starve pitch. No-op unsaturated.
        float rear_common = constrain_float(rear_thrust, 0.0f, 1.0f);
        float yaw_room    = fminf(rear_common, 1.0f - rear_common);
        float yaw_delta   = constrain_float(inputs.yaw * cos_tilt, -yaw_room, yaw_room);
        outputs.motor_thrust[AVATAR_MOT_YAW_LEFT]  = rear_common + yaw_delta;
        outputs.motor_thrust[AVATAR_MOT_YAW_RIGHT] = rear_common - yaw_delta;
        outputs.rudder_out   = inputs.yaw;
        outputs.aileron_out  = -inputs.roll;
        outputs.elevator_out = -cos_tilt;

#if AVATAR_DEBUG_LOG
        {
            static uint32_t last_log_ms = 0;
            static uint32_t last_alert_ms = 0;
            uint32_t now_ms = AP_HAL::millis();
            if (now_ms - last_log_ms >= 1000) {
                last_log_ms = now_ms;
                gcs().send_text(MAV_SEVERITY_INFO,
                    "AVC fwd=%.2f tilt=%.1f ptch=%.2f roll=%.2f thr=%.2f",
                    (double)inputs.forward,
                    (double)outputs.tilt_angle,
                    (double)inputs.pitch,
                    (double)inputs.roll,
                    (double)inputs.throttle);
            }
            if (outputs.tilt_angle > 0.8f && now_ms - last_alert_ms >= 200) {
                last_alert_ms = now_ms;
                gcs().send_text(MAV_SEVERITY_WARNING,
                    "AVC! tilt=%.2f fwd=%.2f tp=%.2f ptch=%.2f",
                    (double)outputs.tilt_angle,
                    (double)inputs.forward,
                    (double)inputs.plane.transition_progress,
                    (double)inputs.pitch);
            }
            // Dataflash log of the copter-mode tilt chain at 20 Hz, to isolate
            // what caps forward tilt in QLOITER. Fwd is the forward demand into
            // the mixer (= -sin(lean), saturates the TVC input at AVATAR_FORWARD_INPUT_MAX);
            // FCmd is what the TVC received; TPit is the raw (pre-cap) TVC target angle;
            // PNrm is the TVC pitch output before the cruise cap; Tilt is the capped
            // servo command actually sent (= RCOU.C5 normalised). If TPit/PNrm plateau
            // below the cap, the limit is upstream (forward demand); if they hit the
            // cap and Tilt clamps, the cruise cap is the limit.
            static uint32_t last_tvc_log_ms = 0;
            if (now_ms - last_tvc_log_ms >= 50) {
                last_tvc_log_ms = now_ms;
                AP::logger().WriteStreaming("AVTL",
                    "TimeUS,Fwd,FCmd,VMag,TPit,PNrm,Tilt,Thr",
                    "Qfffffff",
                    AP_HAL::micros64(),
                    (double)inputs.forward,
                    (double)outputs.debug_data.forward_cmd,
                    (double)outputs.debug_data.vector_magnitude,
                    (double)outputs.debug_data.target_pitch_deg,
                    (double)tvc_out.pitch_angle_norm,
                    (double)outputs.tilt_angle,
                    (double)outputs.debug_data.total_throttle);
            }
        }
#endif
    }

    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) outputs.motor_thrust[i] = constrain_float(outputs.motor_thrust[i], -1.0f, 1.0f);
    outputs.tilt_angle = constrain_float(outputs.tilt_angle, -1.0f, 1.0f);
}

} // namespace AP_Motors6DOF_Mixer
