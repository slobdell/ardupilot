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

        {
            if (inputs.plane.tilt_rate_mode) {
                // [AV-INVAR:stabilize-tilt-rate-control] — see Avatar_Design.md § 9
                // Rate control: pitch_tilt_demand [-1..1] is a rate command.
                // Full stick = tilt_rate_up_dps. Neutral stick = hold position.
                // Positive demand = toward vertical = decrease current_tilt_deg.
                float rate = std::max(1.0f, inputs.tilt_rate_up_dps) * inputs.plane.pitch_tilt_demand;
                state.current_tilt_deg -= rate * inputs.dt;
                state.current_tilt_deg = constrain_float(state.current_tilt_deg, 0.0f, g_config.forward_flight_physical_angle_deg);
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
            outputs.tilt_angle = state.current_tilt_deg / g_config.forward_flight_physical_angle_deg;
        }

        // Elevator: copter attitude PID output — same signal and same sign as the rear motor.
        // Both actuators cooperate to hold the fuselage level; gain may need flight tuning.
        // [AV-INVAR:elevator-follows-pitch-pid] — see Avatar_Design.md § 9
        outputs.elevator_out = inputs.pitch;

        float throttle_pct = inputs.plane.throttle_pct * 0.01f;
        // cos(tilt): 1 at wings-vertical (hover), 0 at wings-horizontal (cruise).
        // Scales both motor roll differential and rear motor — authority fades as
        // aerodynamic surfaces (ailerons, elevator) take over through the transition.
        float tilt_deg_b = outputs.tilt_angle * g_config.forward_flight_physical_angle_deg;
        float cos_tilt_b = fmaxf(0.0f, cosf(radians(tilt_deg_b)));
        // Roll: copter attitude controller differential, same input and tuning as copter mode.
        // Fades to zero at wings-horizontal where aileron authority is full.
        float roll_delta = inputs.roll * cos_tilt_b;
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = throttle_pct + roll_delta;
        outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = throttle_pct - roll_delta;
        outputs.aileron_out  = -inputs.plane.aileron_input / 4500.0f;
        float rear_demand = (throttle_pct - inputs.pitch) * cos_tilt_b;
        outputs.limit.pitch = (rear_demand > 1.0f || rear_demand < 0.0f);
        // Yaw: pilot rudder input drives rear motor differential, fading from full authority
        // in hover to zero in cruise (same cos_tilt_b handoff as roll).
        // [AV-INVAR:yaw-handoff-cos-tilt] — see Avatar_Design.md § 9
        float yaw_delta_b = (inputs.plane.rudder_input / 4500.0f) * cos_tilt_b;
        outputs.rudder_out = inputs.plane.rudder_input / 4500.0f;
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
        float target_deg = tvc_out.debug_data.target_pitch_deg;
        state.current_tilt_deg = constrain_float(target_deg,
            state.current_tilt_deg - (tilt_rate * inputs.dt),
            state.current_tilt_deg + (tilt_rate * inputs.dt));
        float error_deg = fabsf(state.current_tilt_deg - target_deg);
        throttle_thrust *= constrain_float(cosf(radians(error_deg)), 0.0f, 1.0f);

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
        float roll_headroom = fminf(1.0f - base_thrust, base_thrust);
        float desired_roll = inputs.roll * roll_effectiveness;
        float scaled_roll = constrain_float(desired_roll, -roll_headroom, roll_headroom);
        outputs.limit.roll = (fabsf(desired_roll) > roll_headroom);
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = base_thrust + scaled_roll;
        outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = base_thrust - scaled_roll;
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
