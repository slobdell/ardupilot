#include "AP_Motors6DOF.h"
#include "AP_Motors6DOF_AvatarMixer.h"
#include <AP_HAL/AP_HAL.h>

namespace AP_Motors6DOF_Mixer {

#define AVATAR_MOT_WING_LEFT  0
#define AVATAR_MOT_WING_RIGHT 1
#define AVATAR_MOT_YAW        2

const float AVATAR_MANUAL_YAW_DEADBAND = 0.05f;

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

    bool in_plane_mode = (inputs.plane.transition_progress > 0.5f);

    if (in_plane_mode) {
        // =====================================================================
        // --- STATE B: PLANE MODE ---
        // Wings horizontal for forward flight; elevator handles pitch.
        // =====================================================================
        state.manual_override_active = false;
        outputs.tilt_angle = 1.0f;  // Wings horizontal
        float pitch_in = inputs.plane.elevator_input / 4500.0f;
        outputs.elevator_out = pitch_in;
        float throttle_pct = inputs.plane.throttle_pct * 0.01f;
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT] = outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = throttle_pct;
        outputs.rudder_out = inputs.plane.rudder_input / 4500.0f;
        outputs.motor_thrust[AVATAR_MOT_YAW] = outputs.rudder_out;

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
        tvc_in.rc_in[THRUST_CHANNEL]              = f2pwm(inputs.throttle, 0.0f, 1.0f);
        tvc_in.rc_in[FORWARD_CHANNEL]             = f2pwm(inputs.forward * 2.0f, -1.0f, 1.0f);
        tvc_in.rc_in[LATERAL_CHANNEL]             = f2pwm(inputs.lateral * 2.0f, -1.0f, 1.0f);
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

        // Roll scales with how vertical the motors are:
        // cos(0°)=1 at hover (wings vertical), cos(90°)=0 in forward flight (wings horizontal)
        float roll_effectiveness = cosf(radians(state.current_tilt_deg));
        outputs.motor_thrust[AVATAR_MOT_WING_LEFT]  = throttle_thrust + inputs.roll * roll_effectiveness;
        outputs.motor_thrust[AVATAR_MOT_WING_RIGHT] = throttle_thrust - inputs.roll * roll_effectiveness;
        // Rear yaw motor (absent on T1 Ranger; no-op when motor channel not wired)
        outputs.motor_thrust[AVATAR_MOT_YAW] = outputs.rudder_out = inputs.yaw;
    }

    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) outputs.motor_thrust[i] = constrain_float(outputs.motor_thrust[i], -1.0f, 1.0f);
    outputs.tilt_angle = constrain_float(outputs.tilt_angle, -1.0f, 1.0f);
}

} // namespace AP_Motors6DOF_Mixer
