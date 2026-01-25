#include "AP_Motors6DOF.h"
#include "AP_Motors6DOF_BlimpMixer.h"
#include <SRV_Channel/SRV_Channel.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_HAL/AP_HAL.h>

#if ENABLE_TRICOPTER_VTOL_BACKEND
#include <../ArduPlane/quadplane.h>
#endif

namespace AP_Motors6DOF_Mixer {

// --- Blimp Motor Index Definitions (0-indexed) ---
#define BLIMP_MOT_LIFT_RIGHT 0 // Motor 1
#define BLIMP_MOT_LIFT_LEFT  1 // Motor 2
#define BLIMP_MOT_YAW        2 // Motor 3 (Tail Motor)
#define BLIMP_MOT_RUDDER     3 // Motor 4 (Rudder Servo - Virtual)
#define BLIMP_MOT_TILT       4 // Motor 5 (Tilt Servo - Virtual)

// --- Blimp Output Function Mappings ---
#define BLIMP_TILT_SERVO_FUNC   SRV_Channel::k_scripting2 // Function 95
#define BLIMP_RUDDER_SERVO_FUNC SRV_Channel::k_scripting3 // Function 96
#define BLIMP_ELEV_SERVO_FUNC   SRV_Channel::k_scripting4 // Function 97

// --- Blimp Control Parameters ---
#define BLIMP_ELEVATOR_SPLIT    0.0f 
const float BLIMP_PLANE_FWD_ANGLE = 90.0f;
const float MANUAL_YAW_DEADBAND = 0.05f;

void BlimpMixer::setup_motors(::AP_Motors6DOF* backend)
{
    // --- BLIMP CONFIGURATION ---
    // Output 1: Right Lift. Output 2: Left Lift. Output 3: Tail Yaw.
    // Factor logic: No Roll or Pitch stabilization - rely on inherent buoyancy stability.
    const float yawFactor       =  1.0f;
    const float noInput         =  0.0f;

    backend->add_motor_raw_6dof(AP_MOTORS_MOT_1, noInput, noInput, noInput, 1.0, noInput, noInput, 1);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_2, noInput, noInput, noInput, 1.0, noInput, noInput, 2);
    backend->add_motor_raw_6dof(AP_MOTORS_MOT_3, noInput, noInput, yawFactor, 0.0, noInput, noInput, 3);
}

void BlimpMixer::mix(const MixerInputs& inputs, MixerState& state, MixerOutputs& outputs)
{
    float roll_thrust = inputs.roll;
    float pitch_thrust = inputs.pitch;
    float yaw_thrust = inputs.yaw;
    float throttle_thrust = inputs.throttle;
    float forward_thrust = inputs.forward;
    float lateral_thrust = inputs.lateral;

    // Initialize outputs
    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        outputs.motor_thrust[i] = 0.0f;
    }
    outputs.limit.roll = false;
    outputs.limit.pitch = false;
    outputs.limit.yaw = false;
    outputs.limit.throttle_lower = false;
    outputs.limit.throttle_upper = false;

    // --- 1. VTOL Mode Selection & TVC Integration ---
    uint16_t override_pwm = inputs.rc_in[8]; // Channel 9
    
    if (g_config.emergency_blimp_manual_mode && override_pwm > 1200) {
        state.manual_override_active = true;

        // --- Manual Passthrough Logic ---
        // Throttle (RC3) -> Lift Motors (0-1)
        float rc_throttle = (inputs.rc_in[2] - 1000) / 1000.0f;
        throttle_thrust = constrain_float(rc_throttle, 0.0f, 1.0f);

        // Pitch (RC2) -> Tilt Servo (-1 to 1)
        float rc_pitch = (inputs.rc_in[1] - 1500) / 500.0f;
        outputs.tilt_angle = -constrain_float(rc_pitch, -1.0f, 1.0f);
        forward_thrust = outputs.tilt_angle;

        // Yaw (RC4) -> Yaw/Rudder (-1 to 1)
        float rc_yaw = (inputs.rc_in[3] - 1500) / 500.0f;
        if (fabsf(rc_yaw) < MANUAL_YAW_DEADBAND) {
            rc_yaw = 0.0f;
        }
        yaw_thrust = constrain_float(rc_yaw, -1.0f, 1.0f);
        
        roll_thrust = 0.0f;
        lateral_thrust = 0.0f;

    } else {
        state.manual_override_active = false;
        
        // --- TVC Integration (Standard Logic) ---
        // Scale inputs for vectoring authority
        forward_thrust *= 2.0f;
        lateral_thrust *= 2.0f;

        TVC_Inputs tvc_in;
        tvc_in.now_us = AP_HAL::micros();
        tvc_in.ahrs_healthy = inputs.ahrs_healthy;
        tvc_in.in_failsafe = !inputs.is_armed; // Simplified
        tvc_in.roll_rad = inputs.ahrs_roll_rad;
        tvc_in.pitch_rad = inputs.ahrs_pitch_rad;
        tvc_in.gyro.x = inputs.gyro.x;
        tvc_in.gyro.y = inputs.gyro.y;
        tvc_in.gyro.z = inputs.gyro.z;

        auto f2pwm = [](float v, float min, float max) -> int {
             return 1000 + (int)((constrain_float(v, min, max) - min) / (max - min) * 1000);
        };

        for(int k=0; k<16; k++) tvc_in.rc_in[k] = inputs.rc_in[k];
        tvc_in.rc_in[THRUST_CHANNEL] = f2pwm(throttle_thrust, -1.0f, 1.0f);
        tvc_in.rc_in[FORWARD_CHANNEL] = f2pwm(forward_thrust, -1.0f, 1.0f);
        tvc_in.rc_in[LATERAL_CHANNEL] = f2pwm(lateral_thrust, -1.0f, 1.0f);
        tvc_in.rc_in[TRANSITION_PROGRESS_CHANNEL] = f2pwm(inputs.plane.transition_progress, 0.0f, 1.0f);
        
        TVC_State tvc_s = state.get_tvc_state();
        TVC_Outputs tvc_out = tvc_run_main_logic(tvc_in, tvc_s, tvc_config);

        outputs.limit.pitch = tvc_out.debug_data.pitch_saturated;
        outputs.limit.roll = tvc_out.debug_data.roll_saturated;

        outputs.tilt_angle = tvc_out.pitch_angle_norm;
        throttle_thrust = tvc_out.total_throttle;

        // --- Slew Limiter & Transient Thrust Mitigation ---
        float tilt_rate = inputs.tilt_rate_up_dps; 
        if (tilt_rate <= 1.0f) tilt_rate = 40.0f;

        float target_deg = tvc_out.debug_data.target_pitch_deg;
        float max_change = tilt_rate * inputs.dt;
        state.current_tilt_deg = constrain_float(target_deg, state.current_tilt_deg - max_change, state.current_tilt_deg + max_change);

        float error_deg = fabsf(state.current_tilt_deg - target_deg);
        float throttle_scaler = constrain_float(cosf(radians(error_deg)), 0.0f, 1.0f);
        throttle_thrust *= throttle_scaler;

        // --- VTOL State Broadcasting (for downstream controllers) ---
        // Scale the 0-1 progress to a 1000-2000us PWM value.
        uint16_t transition_pwm = 1000 + (uint16_t)(inputs.plane.transition_progress * 1000.0f);
        // Channel 10: Transition Progress (SBUS Channel 11)
        outputs.motor_thrust[10] = (transition_pwm - 1500) / 500.0f;
        // Channel 11: Plane Throttle Debug (SBUS Channel 12)
        outputs.motor_thrust[11] = ((1000 + (int16_t)inputs.plane.throttle_pct * 10) - 1500) / 500.0f;
    }

    // --- 2. Mixing Logic ---
    if (inputs.plane.transition_progress > 0.5f) {
        // --- PLANE MODE (Direct Mapping) ---
        if (inputs.spool_state == AP_Motors::SpoolState::SHUT_DOWN) {
            outputs.motor_thrust[BLIMP_MOT_LIFT_RIGHT] = 0.0f;
            outputs.motor_thrust[BLIMP_MOT_LIFT_LEFT]  = 0.0f;
            outputs.motor_thrust[BLIMP_MOT_YAW]        = 0.0f;
            outputs.tilt_angle = 0.0f;
            outputs.rudder_out = 0.0f;
            outputs.elevator_out = 0.0f;
        } else {
            float pitch_in = inputs.plane.elevator_input / 4500.0f; 
            float abs_pitch = fabsf(pitch_in);
            float elev_cmd = 0.0f;
            float tilt_cmd = 0.0f;

            if (abs_pitch <= BLIMP_ELEVATOR_SPLIT) {
                 if (BLIMP_ELEVATOR_SPLIT > 0.001f) elev_cmd = pitch_in / BLIMP_ELEVATOR_SPLIT;
                 tilt_cmd = 0.0f; 
            } else {
                 elev_cmd = (pitch_in > 0) ? 1.0f : -1.0f;
                 if (BLIMP_ELEVATOR_SPLIT < 0.999f) {
                     float remainder = (abs_pitch - BLIMP_ELEVATOR_SPLIT) / (1.0f - BLIMP_ELEVATOR_SPLIT);
                     tilt_cmd = (pitch_in > 0) ? -remainder * 2.0f : remainder;
                 }
            }

            float val_neutral = BLIMP_PLANE_FWD_ANGLE / g_config.forward_flight_physical_angle_deg;
            if (tilt_cmd >= 0) {
                outputs.tilt_angle = val_neutral + tilt_cmd * (1.0f - val_neutral);
            } else {
                outputs.tilt_angle = val_neutral + tilt_cmd * (val_neutral - (-1.0f));
            }

            outputs.elevator_out = elev_cmd;
            float throttle_pct = inputs.plane.throttle_pct * 0.01f;
            outputs.motor_thrust[BLIMP_MOT_LIFT_RIGHT] = throttle_pct;
            outputs.motor_thrust[BLIMP_MOT_LIFT_LEFT]  = throttle_pct;
            
            float tail_thrust = inputs.plane.rudder_input / 4500.0f;
            outputs.motor_thrust[BLIMP_MOT_YAW] = tail_thrust;
            outputs.rudder_out = tail_thrust;
        }
    } else {
        // --- COPTER MODE ---
        if (inputs.spool_state == AP_Motors::SpoolState::SHUT_DOWN) {
            state.current_tilt_deg = 0.0f;
            outputs.tilt_angle = 0.0f;
            outputs.motor_thrust[BLIMP_MOT_YAW] = 0.0f;
            outputs.rudder_out = 0.0f;
        } else {
            // Standard Copter Mix
            outputs.motor_thrust[BLIMP_MOT_LIFT_RIGHT] = throttle_thrust - roll_thrust + pitch_thrust;
            outputs.motor_thrust[BLIMP_MOT_LIFT_LEFT]  = throttle_thrust + roll_thrust + pitch_thrust;
            outputs.motor_thrust[BLIMP_MOT_YAW]        = yaw_thrust;
            outputs.rudder_out = yaw_thrust;
        }
    }

    // Final Clamp
    for (int i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        outputs.motor_thrust[i] = constrain_float(outputs.motor_thrust[i], -1.0f, 1.0f);
    }
    outputs.tilt_angle = constrain_float(outputs.tilt_angle, -1.0f, 1.0f);
}

} // namespace AP_Motors6DOF_Mixer
