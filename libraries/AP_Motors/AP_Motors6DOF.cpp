/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  See the <http://www.gnu.org/licenses/>.
 */

/*
 *       AP_Motors6DOF.cpp - ArduSub motors library
 */

#include <AP_BattMonitor/AP_BattMonitor.h>
#include <AP_HAL/AP_HAL.h>
#include "AP_Motors6DOF_BlimpMixer.h"
#include "AP_Motors6DOF_AvatarMixer.h"
#include "AP_Motors6DOF.h"
#include <GCS_MAVLink/GCS.h>

#if ENABLE_TRICOPTER_VTOL_BACKEND
#include <../ArduPlane/quadplane.h>
#endif

#include <AP_CustomConfig/AP_CustomConfig.h>
#include "TVC_Core.h"
#include <SRV_Channel/SRV_Channel.h>
#include <AP_AHRS/AP_AHRS.h>

// --- RC-to-SBUS Pass-through Channel Definitions for In-Flight PID Tuning ---
// The RC input channel (0-indexed) from the pilot's receiver for the gain selector switch.
#define RC_INPUT_TUNING_SELECTOR_CHAN 12
// The RC input channel (0-indexed) from the pilot's receiver for the gain value knob.
#define RC_INPUT_TUNING_VALUE_CHAN 13
// The motor output channel (0-indexed) to broadcast the selector switch value on.
#define SBUS_OUTPUT_TUNING_SELECTOR_CHAN 12
// The SBUS output channel (0-indexed) to broadcast the value knob on.
#define SBUS_OUTPUT_TUNING_VALUE_CHAN 13

// convert PWM to a float in the range -1 to 1
static float pwm_to_thrust_float(int16_t pwm) __attribute__((unused));
static float pwm_to_thrust_float(int16_t pwm)
{
    return (pwm - 1500) / 500.0f;
}

#define DEAD_BAND 0.05
uint32_t lastLogTime6 = 0;
#define LOG_PERIOD 3000

extern const AP_HAL::HAL& hal;

// parameters for the motor class
const AP_Param::GroupInfo AP_Motors6DOF::var_info[] = {
    AP_NESTEDGROUPINFO(AP_MotorsMulticopter, 0),
    // @Param: 1_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("1_DIRECTION", 1, AP_Motors6DOF, _motor_reverse[0], 1),

    // @Param: 2_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("2_DIRECTION", 2, AP_Motors6DOF, _motor_reverse[1], 1),

    // @Param: 3_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("3_DIRECTION", 3, AP_Motors6DOF, _motor_reverse[2], 1),

    // @Param: 4_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("4_DIRECTION", 4, AP_Motors6DOF, _motor_reverse[3], 1),

    // @Param: 5_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("5_DIRECTION", 5, AP_Motors6DOF, _motor_reverse[4], 1),

    // @Param: 6_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("6_DIRECTION", 6, AP_Motors6DOF, _motor_reverse[5], 1),

    // @Param: 7_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("7_DIRECTION", 7, AP_Motors6DOF, _motor_reverse[6], 1),

    // @Param: 8_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("8_DIRECTION", 8, AP_Motors6DOF, _motor_reverse[7], 1),

    // @Param: FV_CPLNG_K
    // @DisplayName: Forward/vertical to pitch decoupling factor
    // @Description: Used to decouple pitch from forward/vertical motion. 0 to disable, 1.2 normal
    // @Range: 0.0 1.5
    // @Increment: 0.1
    // @User: Standard
    AP_GROUPINFO("FV_CPLNG_K", 9, AP_Motors6DOF, _forwardVerticalCouplingFactor, 1.0),

    // @Param: 9_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("9_DIRECTION", 10, AP_Motors6DOF, _motor_reverse[8], 1),

    // @Param: 10_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standagd
    AP_GROUPINFO("10_DIRECTION", 11, AP_Motors6DOF, _motor_reverse[9], 1),

    // @Param: 11_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("11_DIRECTION", 12, AP_Motors6DOF, _motor_reverse[10], 1),

    // @Param: 12_DIRECTION
    // @DisplayName: Motor normal or reverse
    // @Description: Used to change motor rotation directions without changing wires
    // @Values: 1:normal,-1:reverse
    // @User: Standard
    AP_GROUPINFO("12_DIRECTION", 13, AP_Motors6DOF, _motor_reverse[11], 1),

    AP_GROUPEND
};

AP_Motors6DOF::~AP_Motors6DOF()
{
    if (_mixer != nullptr) {
        delete _mixer;
    }
}

void AP_Motors6DOF::init(motor_frame_class frame_class, motor_frame_type frame_type)
{
    if (_mixer != nullptr) {
        delete _mixer;
    }
    
    if (g_config.tricopter_is_blimp) {
        _mixer = new ::AP_Motors6DOF_Mixer::BlimpMixer();
    } else {
        _mixer = new ::AP_Motors6DOF_Mixer::AvatarMixer();
    }

    setup_motors(frame_class, frame_type);
    set_update_rate(_speed_hz);
}

bool AP_Motors6DOF::init(uint8_t expected_num_motors) {
    if (_mixer != nullptr) {
        delete _mixer;
    }
    
    if (g_config.tricopter_is_blimp) {
        _mixer = new ::AP_Motors6DOF_Mixer::BlimpMixer();
    } else {
        _mixer = new ::AP_Motors6DOF_Mixer::AvatarMixer();
    }

    setup_motors(MOTOR_FRAME_UNDEFINED, MOTOR_FRAME_TYPE_PLUS);

    // Validate motor count matches expectation
    int wantMotors = 12;
    if(g_config.lateral_motors_config4) wantMotors = 8;
    if (g_config.caterpillar_h_frame_6dof) wantMotors = 9;
    if (ENABLE_TRICOPTER_VTOL_BACKEND) {
      wantMotors = g_config.tricopter_is_blimp ? 3 : 5;
    }

    uint8_t num_motors = 0;
    for(uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) num_motors++;
    }
    
    set_initialised_ok(wantMotors == num_motors);
    set_update_rate(_speed_hz);
    
    return initialised_ok();
}

void AP_Motors6DOF::setup_motors(motor_frame_class frame_class, motor_frame_type frame_type)
{
    for (int8_t i=0; i<AP_MOTORS_MAX_NUM_MOTORS; i++) {
        remove_motor(i);
    }

    if (_mixer != nullptr) {
        _mixer->setup_motors(this);
        set_initialised_ok(true);
    } else {
        set_initialised_ok(false);
    }
}

void AP_Motors6DOF::add_motor_raw_6dof(int8_t motor_num, float roll_fac, float pitch_fac, float yaw_fac, float throttle_fac, float forward_fac, float lat_fac, uint8_t testing_order)
{
    add_motor_raw(motor_num, roll_fac, pitch_fac, yaw_fac, testing_order);
    _throttle_factor[motor_num] = throttle_fac;
    _forward_factor[motor_num] = forward_fac;
    _lateral_factor[motor_num] = lat_fac;
}

void AP_Motors6DOF::output_min()
{
    _spool_state = SpoolState::SHUT_DOWN;
    limit.roll = true;
    limit.pitch = true;
    limit.yaw = true;
    limit.throttle_lower = false;
    limit.throttle_upper = false;
    output_to_motors();
}

int16_t AP_Motors6DOF::calc_thrust_to_pwm(float thrust_in, bool reversible) const
{
    if(!reversible) {
        int16_t minPwm = get_pwm_output_min();
        if(thrust_in <= 0) return minPwm;
        return (thrust_in * (get_pwm_output_max() - minPwm)) + minPwm;
    }
    if(fabsf(thrust_in) <= DEAD_BAND) thrust_in = 0;
    int16_t range_up = get_pwm_output_max() - g_config.mot_spin_neutral;
    int16_t range_down = g_config.mot_spin_neutral - get_pwm_output_min();
    return g_config.mot_spin_neutral + thrust_in * (thrust_in > 0 ? range_up : range_down);
}

void AP_Motors6DOF::output_to_motors()
{
    int8_t i;
    int16_t motor_out[AP_MOTORS_MAX_NUM_MOTORS];
    bool is_shut_down = (_spool_state == SpoolState::SHUT_DOWN);

    for (i=0; i<AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            bool is_reversible = g_config.lifting_motors_reversible;
            float thrust_val = _thrust_rpyt_out[i];
            #if ENABLE_TRICOPTER_VTOL_BACKEND
            if (g_config.tricopter_is_blimp && i < 2) {
                thrust_val = fabsf(thrust_val);
            }
            if (g_config.tricopter_is_blimp && i == 2) is_reversible = true;
            #endif
            motor_out[i] = calc_thrust_to_pwm(thrust_val, is_reversible);
        }
    }

    if (_mixer != nullptr) {
        #if ENABLE_TRICOPTER_VTOL_BACKEND
        if (g_config.tricopter_is_blimp) {
            float tilt = is_shut_down ? 0.0f : _mixer_results.tilt_angle;
            float rudder = is_shut_down ? 0.0f : _mixer_results.rudder_out;
            SRV_Channels::set_output_norm(SRV_Channel::k_scripting2, tilt);
            SRV_Channels::set_output_norm(SRV_Channel::k_scripting3, rudder);
            SRV_Channels::set_output_norm(SRV_Channel::k_scripting4, _mixer_results.elevator_out);

            // Platform Stabilization (Scripting 5 & 6)
            // Concept: Output = -Attitude to keep platform level.
            // Assumption: Servo Range 1.0 = platform_max_angle_deg degrees.
            const AP_AHRS &ahrs = AP::ahrs();
            const float max_angle = g_config.platform_max_angle_deg;
            
            if (g_config.optical_flow_stabilized_roll) {
                float roll_deg = degrees(ahrs.get_roll());
                float roll_comp = -constrain_float(roll_deg, -max_angle, max_angle) / max_angle;
                SRV_Channels::set_output_norm(SRV_Channel::k_scripting5, roll_comp);
            }

            if (g_config.optical_flow_stabilized_pitch) {
                float pitch_deg = degrees(ahrs.get_pitch());
                float pitch_comp = -constrain_float(pitch_deg, -max_angle, max_angle) / max_angle;
                SRV_Channels::set_output_norm(SRV_Channel::k_scripting6, pitch_comp);
            }
        }
        #endif
    }

    for (i=0; i<AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) rc_write(i, motor_out[i]);
    }
}

float AP_Motors6DOF::get_current_limit_max_throttle()
{
    return 1.0f;
}

void AP_Motors6DOF::output_armed_stabilizing()
{
    static uint32_t last_dbg_ms = 0;
    uint32_t now_ms = AP_HAL::millis();
    bool should_log = (now_ms - last_dbg_ms > 2000);
    if (should_log) last_dbg_ms = now_ms;

    float roll_thrust = (_roll_in + _roll_in_ff);
    float pitch_thrust = (_pitch_in + _pitch_in_ff);
    float yaw_thrust = (_yaw_in + _yaw_in_ff);
    float throttle_thrust = (g_config.lifting_motors_reversible || g_config.tricopter_is_blimp) ? get_throttle_bidirectional() : get_throttle();
    float forward_thrust = _forward_in;
    float lateral_thrust = _lateral_in;

    AP_Motors6DOF_Mixer::MixerInputs mixer_in;
    mixer_in.roll = roll_thrust;
    mixer_in.pitch = pitch_thrust;
    mixer_in.yaw = yaw_thrust;
    mixer_in.throttle = throttle_thrust;
    mixer_in.forward = forward_thrust;
    mixer_in.lateral = lateral_thrust;
    mixer_in.plane.pitch_cd = _plane_inputs.pitch_cd;
    mixer_in.plane.roll_cd = _plane_inputs.roll_cd;
    mixer_in.plane.throttle_pct = _plane_inputs.throttle_pct;
    mixer_in.plane.rudder_input = _plane_inputs.rudder_input;
    mixer_in.plane.elevator_input = _plane_inputs.elevator_input;
    mixer_in.plane.aileron_input = _plane_inputs.aileron_input;
    mixer_in.plane.transition_progress = _plane_inputs.transition_progress;
    mixer_in.dt = _dt;
    mixer_in.spool_state = _spool_state;
    mixer_in.is_armed = armed();
    mixer_in.tilt_rate_up_dps = 40.0f;

#if ENABLE_TRICOPTER_VTOL_BACKEND
    QuadPlane *qp = QuadPlane::get_singleton();
    if (qp != nullptr) mixer_in.tilt_rate_up_dps = (float)qp->tiltrotor.max_rate_up_dps;
#endif

    const AP_AHRS &ahrs = AP::ahrs();
    mixer_in.ahrs_healthy = true; 
    mixer_in.ahrs_roll_rad = ahrs.get_roll();
    mixer_in.ahrs_pitch_rad = ahrs.get_pitch();
    mixer_in.gyro = ahrs.get_gyro();

    auto f2pwm = [](float v, float min, float max) -> uint16_t {
        return 1000 + (uint16_t)((constrain_float(v, min, max) - min) / (max - min) * 1000);
    };

    for (int k=0; k<16; k++) {
        const RC_Channel *c = RC_Channels::rc_channel(k);
        mixer_in.rc_in[k] = (c != nullptr) ? c->get_radio_in() : 1500;
    }

    mixer_in.manual_override_pwm = mixer_in.rc_in[7]; // Channel 8
    mixer_in.transition_pwm = mixer_in.rc_in[10];     // Channel 11

    mixer_in.rc_in[6] = f2pwm(throttle_thrust, -1.0f, 1.0f);
    mixer_in.rc_in[7] = f2pwm(forward_thrust, -1.0f, 1.0f);
    mixer_in.rc_in[8] = f2pwm(lateral_thrust, -1.0f, 1.0f);
    mixer_in.rc_in[10] = f2pwm(_plane_inputs.transition_progress, 0.0f, 1.0f);

    if (_mixer != nullptr) _mixer->mix(mixer_in, _mixer_state, _mixer_results);

    for (int i=0; i<AP_MOTORS_MAX_NUM_MOTORS; i++) _thrust_rpyt_out[i] = _mixer_results.motor_thrust[i];
    
    limit.roll = _mixer_results.limit.roll;
    limit.pitch = _mixer_results.limit.pitch;
    limit.yaw = _mixer_results.limit.yaw;
    limit.throttle_lower = _mixer_results.limit.throttle_lower;
    limit.throttle_upper = _mixer_results.limit.throttle_upper;

    if (g_config.caterpillar_h_frame_6dof) {
        #if SBUS_OUTPUT_TUNING_SELECTOR_CHAN < AP_MOTORS_MAX_NUM_MOTORS
        _thrust_rpyt_out[SBUS_OUTPUT_TUNING_SELECTOR_CHAN] = pwm_to_thrust_float(hal.rcin->read(RC_INPUT_TUNING_SELECTOR_CHAN));
        #endif
        #if SBUS_OUTPUT_TUNING_VALUE_CHAN < AP_MOTORS_MAX_NUM_MOTORS
        _thrust_rpyt_out[SBUS_OUTPUT_TUNING_VALUE_CHAN] = pwm_to_thrust_float(hal.rcin->read(RC_INPUT_TUNING_VALUE_CHAN));
        #endif
    }

    #if AP_BATTERY_ENABLED
    const AP_BattMonitor &battery = AP::battery();
    float _batt_current;
    if (_batt_current_max > 0.0f && battery.current_amps(_batt_current)) {
        float _batt_current_delta = _batt_current - _batt_current_last;
        float predicted_current = _batt_current + ((_batt_current_delta / _dt) * _dt * 5);
        float batt_current_ratio = _batt_current / _batt_current_max;
        if (predicted_current > _batt_current_max * 1.5f) batt_current_ratio = 2.5f;
        else if (_batt_current < _batt_current_max && predicted_current > _batt_current_max) batt_current_ratio = predicted_current / _batt_current_max;
        _output_limited += (_dt / (_dt + _batt_current_time_constant)) * (1 - batt_current_ratio);
        _batt_current_last = _batt_current;
    }
    #endif

    _output_limited = constrain_float(_output_limited, 0.0f, 1.0f);
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) _thrust_rpyt_out[i] *= _output_limited;
    }
}

Vector3f AP_Motors6DOF::get_motor_angular_factors(int motor_number) {
    if (motor_number < 0 || motor_number >= AP_MOTORS_MAX_NUM_MOTORS) return Vector3f(0,0,0);
    return Vector3f(_roll_factor[motor_number], _pitch_factor[motor_number], _yaw_factor[motor_number]);
}

bool AP_Motors6DOF::motor_is_enabled(int motor_number) {
    if (motor_number < 0 || motor_number >= AP_MOTORS_MAX_NUM_MOTORS) return false;
    return motor_enabled[motor_number];
}

bool AP_Motors6DOF::set_reversed(int motor_number, bool reversed) {
    if (motor_number < 0 || motor_number >= AP_MOTORS_MAX_NUM_MOTORS) return false;
    _motor_reverse[motor_number].set_and_save(reversed ? -1 : 1);
    return true;
}
