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
#endif

namespace AP_Motors6DOF_Mixer {

#define AVATAR_MOT_WING_LEFT  0
#define AVATAR_MOT_WING_RIGHT 1
#define AVATAR_MOT_YAW_RIGHT  2
#define AVATAR_MOT_YAW_LEFT   3

const float AVATAR_MANUAL_YAW_DEADBAND = 0.05f;

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

    if (in_plane_mode) {
        // =====================================================================
        // --- STATE B: PLANE MODE ---
        // Tilt is either rate-controlled (STABILIZE) or position-controlled (FBWA/auto).
        // Elevator holds level via the copter attitude PID in both sub-modes.
        // =====================================================================
        state.manual_override_active = false;

        float throttle_pct = inputs.plane.throttle_pct * 0.01f;

        // Copter→plane throttle blend: ramp from the last copter-mode wing-motor throttle
        // to the plane throttle over 0.5 s so the pilot experiences a smooth handoff rather
        // than a step change. copter_to_plane_blend is reset to 0 each frame in copter mode.
        if (state.copter_to_plane_blend < 1.0f) {
            state.copter_to_plane_blend = fminf(1.0f, state.copter_to_plane_blend + inputs.dt / 0.5f);
            throttle_pct = state.last_copter_throttle * (1.0f - state.copter_to_plane_blend)
                         + throttle_pct              *  state.copter_to_plane_blend;
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
            }
            outputs.tilt_angle = state.current_tilt_deg >= 0.0f
                ? state.current_tilt_deg / g_config.forward_flight_physical_angle_deg
                : state.current_tilt_deg / fabsf(g_config.reverse_flight_physical_angle_deg);
        }

        // Elevator: copter attitude PID output — same signal and same sign as the rear motor.
        // Both actuators cooperate to hold the fuselage level; gain may need flight tuning.
        // [AV-INVAR:elevator-follows-pitch-pid] — see Avatar_Design.md § 9
        outputs.elevator_out = inputs.pitch;

        // cos(tilt): 1 at wings-vertical (hover), 0 at wings-horizontal (cruise).
        // Scales both motor roll differential and rear motor — authority fades as
        // aerodynamic surfaces (ailerons, elevator) take over through the transition.
        float cos_tilt_b = fmaxf(0.0f, cosf(radians(state.current_tilt_deg)));
        // Roll: copter attitude controller differential, same input and tuning as copter mode.
        // Fades to zero at wings-horizontal where aileron authority is full.
        float roll_delta  = inputs.roll * cos_tilt_b;
        float p_left_raw  = throttle_pct + roll_delta;
        float p_right_raw = throttle_pct - roll_delta;
        float p_excess_high = fmaxf(0.0f, fmaxf(p_left_raw, p_right_raw) - 1.0f);
        float p_excess_low  = fmaxf(0.0f, -fminf(p_left_raw, p_right_raw));
        float p_shift = p_excess_high - p_excess_low;
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = constrain_float(p_left_raw  - p_shift, 0.0f, 1.0f);
        outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = constrain_float(p_right_raw - p_shift, 0.0f, 1.0f);
        outputs.aileron_out  = -inputs.plane.aileron_input / 4500.0f;
        float rear_demand = (throttle_pct - inputs.pitch) * cos_tilt_b;
        outputs.limit.pitch = (rear_demand > 1.0f || rear_demand < 0.0f);
        // Yaw: STABILIZE uses copter attitude PID (inputs.yaw); all other plane modes use raw rudder stick.
        // [AV-INVAR:stabilize-yaw-pid] and [AV-INVAR:yaw-handoff-cos-tilt] — see Avatar_Design.md § 9
        const float yaw_norm = inputs.plane.use_pid_yaw
            ? inputs.yaw
            : (inputs.plane.rudder_input / 4500.0f);
        float yaw_delta_b = yaw_norm * cos_tilt_b;
        outputs.rudder_out = yaw_norm;
        outputs.motor_thrust[AVATAR_MOT_YAW_LEFT]  = constrain_float(rear_demand + yaw_delta_b, 0.0f, 1.0f);
        outputs.motor_thrust[AVATAR_MOT_YAW_RIGHT] = constrain_float(rear_demand - yaw_delta_b, 0.0f, 1.0f);

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
        float target_deg = tvc_out.debug_data.target_pitch_deg;
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
        outputs.limit.pitch = (base_thrust > 1.0f || base_thrust < 0.0f);
        base_thrust = constrain_float(base_thrust, 0.0f, 1.0f);
        // Track effective wing-motor throttle for smooth copter→plane handoff.
        // Reset blend to 0 each frame so the first plane-mode frame starts the ramp.
        state.last_copter_throttle = base_thrust;
        state.copter_to_plane_blend = 0.0f;
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
        // Yaw: attitude PID output drives differential between the two rear motors, fading
        // with cos_tilt. [AV-INVAR:yaw-handoff-cos-tilt] — see Avatar_Design.md § 9
        float rear_thrust = (inputs.throttle - inputs.pitch) * cos_tilt;
        float yaw_delta = inputs.yaw * cos_tilt;
        outputs.motor_thrust[AVATAR_MOT_YAW_LEFT]  = constrain_float(rear_thrust + yaw_delta, 0.0f, 1.0f);
        outputs.motor_thrust[AVATAR_MOT_YAW_RIGHT] = constrain_float(rear_thrust - yaw_delta, 0.0f, 1.0f);
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
        }
#endif
    }

    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) outputs.motor_thrust[i] = constrain_float(outputs.motor_thrust[i], -1.0f, 1.0f);
    outputs.tilt_angle = constrain_float(outputs.tilt_angle, -1.0f, 1.0f);
}

} // namespace AP_Motors6DOF_Mixer
