#ifndef MIXER_STANDALONE_BUILD
#include "AP_Motors6DOF.h"
#include <SRV_Channel/SRV_Channel.h>
#include <AP_AHRS/AP_AHRS.h>
#endif
#include "AP_Motors6DOF_BlimpMixer.h"
#include <AP_HAL/AP_HAL.h>

#if ENABLE_TRICOPTER_VTOL_BACKEND && !defined(MIXER_STANDALONE_BUILD)
#include <../ArduPlane/quadplane.h>
#endif

namespace AP_Motors6DOF_Mixer {

// --- Blimp Motor Index Definitions (0-indexed) ---
#define BLIMP_MOT_LIFT_RIGHT 0 // Motor 1
#define BLIMP_MOT_LIFT_LEFT  1 // Motor 2
#define BLIMP_MOT_YAW        2 // Motor 3 (Tail Motor)

// --- Blimp Output Function Mappings ---
#define BLIMP_TILT_SERVO_FUNC   SRV_Channel::k_scripting2 // Function 95
#define BLIMP_RUDDER_SERVO_FUNC SRV_Channel::k_scripting3 // Function 96
#define BLIMP_ELEV_SERVO_FUNC   SRV_Channel::k_scripting4 // Function 97

// --- Blimp Control Parameters ---
const float BLIMP_PLANE_FWD_ANGLE = 90.0f;
const float MANUAL_YAW_DEADBAND = 0.05f;

void BlimpMixer::setup_motors(::AP_Motors6DOF* backend)
{
#ifndef MIXER_STANDALONE_BUILD
    const float yawFactor       =  1.0f;
    const float noInput         =  0.0f;
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_1, noInput, noInput, noInput, 1.0, noInput, noInput, 1);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_2, noInput, noInput, noInput, 1.0, noInput, noInput, 2);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_3, noInput, noInput, yawFactor, 0.0, noInput, noInput, 3);
#endif
}

void BlimpMixer::mix(const MixerInputs& inputs, MixerState& state, MixerOutputs& outputs)
{
    // Initialize outputs
    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) outputs.motor_thrust[i] = 0.0f;
    outputs.limit.roll = outputs.limit.pitch = outputs.limit.yaw = false;
    outputs.limit.throttle_lower = outputs.limit.throttle_upper = false;

    // Determine Mode
    bool in_manual_override = (g_config.emergency_blimp_manual_mode && inputs.manual_override_pwm > 1200);
    bool in_plane_mode = (inputs.plane.transition_progress > 0.5f);

    if (in_manual_override) {
        // =====================================================================
        // --- STATE A: EMERGENCY MANUAL OVERRIDE (Dumb Passthrough) ---
        // =====================================================================
        state.manual_override_active = true;
        float throttle_thrust = (inputs.rc_in[2] - 1000) / 1000.0f;
        float rc_pitch = (inputs.rc_in[1] - 1500) / 500.0f;
        float rc_yaw = (inputs.rc_in[3] - 1500) / 500.0f;
        outputs.motor_thrust[BLIMP_MOT_LIFT_RIGHT] = outputs.motor_thrust[BLIMP_MOT_LIFT_LEFT] = constrain_float(throttle_thrust, 0.0f, 1.0f);
        outputs.tilt_angle = -constrain_float(rc_pitch, -1.0f, 1.0f);
        if (fabsf(rc_yaw) < MANUAL_YAW_DEADBAND) rc_yaw = 0.0f;
        outputs.motor_thrust[BLIMP_MOT_YAW] = outputs.rudder_out = constrain_float(rc_yaw, -1.0f, 1.0f);

    } else if (in_plane_mode) {
        // =====================================================================
        // --- STATE B: PLANE MODE (Direct Actuator Mapping) ---
        // =====================================================================
        state.manual_override_active = false;
        float pitch_in = inputs.plane.elevator_input / 4500.0f;
        float tilt_delta;
        elevator_tilt_split(pitch_in, g_config.elevator_tilt_handoff_point,
                            outputs.elevator_out, tilt_delta);

        // Neutral forward position; tilt toward vertical on pitch-up, more forward on pitch-down
        float val_neutral = BLIMP_PLANE_FWD_ANGLE / g_config.forward_flight_physical_angle_deg;
        if (pitch_in >= 0.0f) {
            outputs.tilt_angle = val_neutral - tilt_delta * (val_neutral + 1.0f);
        } else {
            outputs.tilt_angle = val_neutral + tilt_delta * (1.0f - val_neutral);
        }
        float throttle_pct = inputs.plane.throttle_pct * 0.01f;
        outputs.motor_thrust[BLIMP_MOT_LIFT_RIGHT] = outputs.motor_thrust[BLIMP_MOT_LIFT_LEFT] = throttle_pct;
        outputs.motor_thrust[BLIMP_MOT_YAW] = outputs.rudder_out = inputs.plane.rudder_input / 4500.0f;

    } else {
        // =====================================================================
        // --- STATE C: COPTER MODE (The TVC Brain) ---
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
        tvc_in.gyro.x = inputs.gyro.x; tvc_in.gyro.y = inputs.gyro.y; tvc_in.gyro.z = inputs.gyro.z;

        auto f2pwm = [](float v, float min, float max) -> int {
             return 1000 + (int)((constrain_float(v, min, max) - min) / (max - min) * 1000);
        };

        for(int k=0; k<16; k++) tvc_in.rc_in[k] = 1500;
        tvc_in.rc_in[THRUST_CHANNEL] = f2pwm(inputs.throttle, -1.0f, 1.0f);
        tvc_in.rc_in[FORWARD_CHANNEL] = f2pwm(inputs.forward * 2.0f, -1.0f, 1.0f); 
        tvc_in.rc_in[LATERAL_CHANNEL] = f2pwm(inputs.lateral * 2.0f, -1.0f, 1.0f);
        tvc_in.rc_in[TRANSITION_PROGRESS_CHANNEL] = f2pwm(inputs.plane.transition_progress, 0.0f, 1.0f);
        
        TVC_CoreState tvc_s = state.get_tvc_state();
        TVC_Outputs tvc_out = tvc_run_main_logic(tvc_in, tvc_s, tvc_config);

        outputs.tilt_angle = tvc_out.pitch_angle_norm;
        float throttle_thrust = tvc_out.total_throttle;
        outputs.debug_data = tvc_out.debug_data;

        // [BL-INVAR:tilt-servo-tracking] — see Blimp_Design.md § 2 "Non-obvious code behaviors"
        // outputs.tilt_angle (servo command) is already set to the TVC target above.
        // state.current_tilt_deg is a rate-limited model of where the servo physically is.
        // Motor thrust and elevator trim both use the physical position so they remain
        // correct while the servo is still travelling to its target.
        float tilt_rate = std::max(1.0f, inputs.tilt_rate_up_dps);
        float target_deg = tvc_out.debug_data.target_pitch_deg;
        state.current_tilt_deg = constrain_float(target_deg, state.current_tilt_deg - (tilt_rate * inputs.dt), state.current_tilt_deg + (tilt_rate * inputs.dt));
        float error_deg = fabsf(state.current_tilt_deg - target_deg);
        throttle_thrust *= constrain_float(cosf(radians(error_deg)), 0.0f, 1.0f);

        outputs.motor_thrust[BLIMP_MOT_LIFT_RIGHT] = outputs.motor_thrust[BLIMP_MOT_LIFT_LEFT] = throttle_thrust;
        outputs.motor_thrust[BLIMP_MOT_YAW] = outputs.rudder_out = inputs.yaw;
        outputs.elevator_out = cosf(radians(state.current_tilt_deg));
    }

    // Final Safety Clamp
    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) outputs.motor_thrust[i] = constrain_float(outputs.motor_thrust[i], -1.0f, 1.0f);
    outputs.tilt_angle = constrain_float(outputs.tilt_angle, -1.0f, 1.0f);
}

} // namespace AP_Motors6DOF_Mixer