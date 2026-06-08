#include "AP_Motors6DOF.h"
#include "AP_Motors6DOF_AvatarMixer.h"
#include <AP_HAL/AP_HAL.h>

// Set to 1 to enable periodic debug logging via MAVLink text messages.
// Logs once every 3 seconds. Disable before production flights.
#define AVATAR_DEBUG_LOG 1

#if AVATAR_DEBUG_LOG
#include <GCS_MAVLink/GCS.h>
#endif

namespace AP_Motors6DOF_Mixer {

#define AVATAR_MOT_WING_LEFT  0
#define AVATAR_MOT_WING_RIGHT 1
#define AVATAR_MOT_YAW        2

const float AVATAR_MANUAL_YAW_DEADBAND = 0.05f;

// Maximum forward/lateral input observed from the radio at full stick deflection.
// ArduPlane's Q_ANGLE_MAX (currently 30 deg) caps the pitch demand fed into the
// 6DOF attitude controller, so set_forward never reaches 1.0 even at full stick.
// Dividing by this constant re-normalises full-stick to 1.0 so the TVC sees the
// full -1..1 range. Adjust if Q_ANGLE_MAX or the radio calibration changes.
const float AVATAR_FORWARD_INPUT_MAX = 0.42f;

void AvatarMixer::setup_motors(::AP_Motors6DOF* backend)
{
    const float yawFactor = 1.0f;
    const float noInput   = 0.0f;
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_1, noInput, noInput, noInput, 1.0f, noInput, noInput, 1);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_2, noInput, noInput, noInput, 1.0f, noInput, noInput, 2);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_3, noInput, noInput, yawFactor, 0.0f, noInput, noInput, 3);
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
        // Wings horizontal for forward flight; elevator handles pitch.
        // =====================================================================
        state.manual_override_active = false;
        float pitch_in = inputs.plane.elevator_input / 4500.0f;
        float tilt_delta;
        elevator_tilt_split(pitch_in, g_config.elevator_tilt_handoff_point,
                            outputs.elevator_out, tilt_delta);

        // Wings horizontal until elevator saturates, then tilt toward vertical on pitch-up only
        outputs.tilt_angle = 1.0f - ((pitch_in >= 0.0f) ? tilt_delta : 0.0f);
        float throttle_pct = inputs.plane.throttle_pct * 0.01f;
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT] = outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = throttle_pct;
        outputs.rudder_out   = inputs.plane.rudder_input / 4500.0f;
        outputs.aileron_out  = -inputs.plane.aileron_input / 4500.0f;
        // Rear motor: closed-loop pitch from copter attitude controller, scaled by cos(tilt).
        // cos(tilt) = 1 at hover (full authority), 0 at wings-horizontal (no authority).
        // inputs.pitch is live in plane mode because hold_stabilize() runs before motors_output().
        // cos factor also prevents PID windup from firing when wings are horizontal.
        float tilt_deg_b = outputs.tilt_angle * g_config.forward_flight_physical_angle_deg;
        float cos_tilt_b = fmaxf(0.0f, cosf(radians(tilt_deg_b)));
        outputs.motor_thrust[AVATAR_MOT_YAW] = constrain_float((throttle_pct - inputs.pitch) * cos_tilt_b, 0.0f, 1.0f);

#if AVATAR_DEBUG_LOG
        {
            static uint32_t last_b_log_ms = 0;
            uint32_t now_ms = AP_HAL::millis();
            if (now_ms - last_b_log_ms >= 1000) {
                last_b_log_ms = now_ms;
                gcs().send_text(MAV_SEVERITY_INFO,
                    "AVB elev=%.2f pin=%.2f td=%.2f thr=%.2f ipitch=%.2f",
                    (double)(inputs.plane.elevator_input / 4500.0f),
                    (double)pitch_in,
                    (double)tilt_delta,
                    (double)throttle_pct,
                    (double)inputs.pitch);
                gcs().send_text(MAV_SEVERITY_INFO,
                    "AVB tilt=%.2f cos=%.2f rear=%.2f ahrs_pitch_deg=%.1f",
                    (double)outputs.tilt_angle,
                    (double)cos_tilt_b,
                    (double)outputs.motor_thrust[AVATAR_MOT_YAW],
                    (double)degrees(inputs.ahrs_pitch_rad));
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

        outputs.tilt_angle = tvc_out.pitch_angle_norm;
        float throttle_thrust = tvc_out.total_throttle;
        outputs.debug_data = tvc_out.debug_data;

        // Rate-limit tilt and scale back thrust proportionally during transient
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
        float roll_headroom = fminf(1.0f - base_thrust, base_thrust);
        float scaled_roll = constrain_float(inputs.roll * roll_effectiveness, -roll_headroom, roll_headroom);
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = base_thrust + scaled_roll;
        outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = base_thrust - scaled_roll;
        // Rear motor fades to zero at 90° and stays off beyond — it has no thrust
        // vectoring so it loses relevance (and would invert without the floor) past 90°.
        float rear_thrust = (inputs.throttle - inputs.pitch) * cos_tilt;
        outputs.motor_thrust[AVATAR_MOT_YAW] = constrain_float(rear_thrust, 0.0f, 1.0f);
        // Surfaces use FF-only pilot stick input for direct authority.
        // Motors use PID-derived inputs.roll/yaw for closed-loop stability.
        outputs.rudder_out   = inputs.surface_yaw;
        outputs.aileron_out  = -inputs.surface_roll;
        outputs.elevator_out = cos_tilt;

#if AVATAR_DEBUG_LOG
        {
            static uint32_t last_log_ms = 0;
            uint32_t now_ms = AP_HAL::millis();
            if (now_ms - last_log_ms >= 3000) {
                last_log_ms = now_ms;
                gcs().send_text(MAV_SEVERITY_INFO,
                    "AV fwd=%.2f thr=%.2f tilt=%.1f roll=%.2f yaw=%.2f ail=%.2f",
                    (double)inputs.forward,
                    (double)throttle_thrust,
                    (double)state.current_tilt_deg,
                    (double)inputs.roll,
                    (double)inputs.yaw,
                    (double)outputs.aileron_out);
                gcs().send_text(MAV_SEVERITY_INFO,
                    "AV elev=%.2f rud=%.2f vtL=%.2f vtR=%.2f evL=%.2f evR=%.2f",
                    (double)outputs.elevator_out,
                    (double)outputs.rudder_out,
                    (double)(outputs.elevator_out + outputs.rudder_out),
                    (double)(outputs.elevator_out - outputs.rudder_out),
                    (double)(outputs.elevator_out + outputs.aileron_out),
                    (double)(outputs.elevator_out - outputs.aileron_out));
            }
        }
#endif
    }

    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) outputs.motor_thrust[i] = constrain_float(outputs.motor_thrust[i], -1.0f, 1.0f);
    outputs.tilt_angle = constrain_float(outputs.tilt_angle, -1.0f, 1.0f);
}

} // namespace AP_Motors6DOF_Mixer
