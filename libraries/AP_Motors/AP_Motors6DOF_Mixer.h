#pragma once

#ifdef MIXER_STANDALONE_BUILD
// Minimal standalone types — no ArduPilot library chain required.
// Pulled in only when compiling tests/mixer_test/ outside the normal waf build.
#include <cmath>
#include <cstdint>
#include <algorithm>

#define AP_MOTORS_MAX_NUM_MOTORS 12

namespace AP_Motors {
    enum class SpoolState : uint8_t {
        SHUT_DOWN = 0, GROUND_IDLE = 1, SPOOLING_UP = 2, THROTTLE_UNLIMITED = 3, SPOOLING_DOWN = 4
    };
}

struct Vector3f { float x, y, z; };

static inline float constrain_float(float x, float lo, float hi) { return x < lo ? lo : x > hi ? hi : x; }
static inline float radians(float deg) { return deg * (float)(M_PI / 180.0); }
static inline float degrees(float rad) { return rad * (float)(180.0 / M_PI); }
#else
#include "AP_Motors_Class.h"
#include <AP_Math/AP_Math.h>
#endif

#include <AP_CustomConfig/AP_CustomConfig.h>
#include "TVC_Core.h"
#include "TVC_PID.h"
#include "TVC_Filters.h"

class AP_Motors6DOF;

namespace AP_Motors6DOF_Mixer {

// --- Perception Inputs ---
struct MixerInputs {
    // Standard Copter Perception (Normalized -1.0 to 1.0)
    // PID + FF combined — use for motor outputs (closed-loop stable).
    float roll;
    float pitch;
    float yaw;
    float throttle;     // 0.0 to 1.0 (or -1.0 to 1.0 if reversible)
    float forward;
    float lateral;

    // Feedforward-only pilot stick inputs — use for aerodynamic surface outputs.
    // These bypass the PID loop for direct, full-authority surface deflection.
    float surface_roll;   // _roll_in_ff
    float surface_yaw;    // _yaw_in_ff
    float surface_pitch;  // _pitch_in_ff

    // Plane State Perception (for QuadPlane transitions)
    struct {
        float pitch_cd;
        float roll_cd;
        float throttle_pct;
        float rudder_input;
        float elevator_input;
        float aileron_input;
        float transition_progress; // 0.0 (Hover) -> 1.0 (Plane)
        float pitch_tilt_demand;   // Pilot pitch stick -1..1; positive = pitch up = tilt rotors toward vertical
    } plane;

    // System Perception
    float dt;
    AP_Motors::SpoolState spool_state;
    bool is_armed;
    float spin_min;           // Q_M_SPIN_MIN — in-flight floor applied to all motors to prevent DShot 0 while airborne
    float tilt_rate_up_dps;   // physical servo slew rate — calibrated to hardware (see [AV-INVAR:tilt-servo-tracking])
    float tilt_rate_down_dps; // commanded transition rate toward horizontal — design choice (see [AV-INVAR:plane-tilt-slew]); 0 = use tilt_rate_up_dps
    
    // Sensor Perception
    bool ahrs_healthy;
    float ahrs_roll_rad;
    float ahrs_pitch_rad;
    Vector3f gyro;

    // Raw RC Perception (for Overrides and Tuning)
    uint16_t rc_in[16];
    uint16_t manual_override_pwm;
    uint16_t transition_pwm;
};

// --- Mixer Output Actuation ---
struct MixerOutputs {
    float motor_thrust[AP_MOTORS_MAX_NUM_MOTORS]; // -1.0 to 1.0
    
    // Abstract Actuators (Normalized -1.0 to 1.0)
    float tilt_angle;
    float rudder_out;
    float elevator_out;
    float aileron_out;

    // Navigation Limits (Saturation feedback)
    struct {
        bool roll;
        bool pitch;
        bool yaw;
        bool throttle_lower;
        bool throttle_upper;
    } limit;

    // Debugging data passed from mixer to backend
    TVC_Debug_Data debug_data;
};

// --- Persistent State ---
struct MixerState {
    float current_tilt_deg;
    bool manual_override_active;
    bool pitch_saturated;
    bool roll_saturated;
    
    // "Brain" (TVC) Persistent Objects
    LinearPIDController pitch_rate_pid;
    LinearPIDController roll_rate_pid;
    LinearPIDController pitch_angle_pid;
    LinearPIDController roll_angle_pid;
    CustomFilter target_pitch_rate_filter;
    CustomFilter target_roll_rate_filter;

    MixerState() :
        current_tilt_deg(0.0f),
        manual_override_active(false),
        pitch_saturated(false),
        roll_saturated(false),
        pitch_rate_pid(0,0,0,0),
        roll_rate_pid(0,0,0,0),
        pitch_angle_pid(::tvc_config.pitch_angle.p, ::tvc_config.pitch_angle.i, ::tvc_config.pitch_angle.d, ::tvc_config.i_max_angle),
        roll_angle_pid(::tvc_config.roll_angle.p, ::tvc_config.roll_angle.i, ::tvc_config.roll_angle.d, ::tvc_config.i_max_angle),
        target_pitch_rate_filter(20.0, 1.0/400.0, IIR::ORDER::OD2, IIR::TYPE::LOWPASS),
        target_roll_rate_filter(20.0, 1.0/400.0, IIR::ORDER::OD2, IIR::TYPE::LOWPASS)
    {}

    // Helper to generate the TVC_CoreState expected by tvc_run_main_logic
    TVC_CoreState get_tvc_state() {
        return {
            pitch_rate_pid,
            roll_rate_pid,
            pitch_angle_pid,
            roll_angle_pid,
            target_pitch_rate_filter,
            target_roll_rate_filter,
            this->pitch_saturated,
            this->roll_saturated
        };
    }
};

// Splits a normalized pitch demand [-1,1] into elevator and tilt contributions.
// Below threshold: elevator fills proportionally, tilt_delta = 0.
// Above threshold: elevator saturates at ±1, tilt_delta ramps 0→1.
static inline void elevator_tilt_split(float pitch_in, float threshold,
                                       float& elevator_out, float& tilt_delta)
{
    float abs_pitch = fabsf(pitch_in);
    float sign = (pitch_in >= 0.0f) ? 1.0f : -1.0f;
    if (abs_pitch <= threshold) {
        elevator_out = sign * (abs_pitch / threshold);
        tilt_delta = 0.0f;
    } else {
        elevator_out = sign;
        tilt_delta = (abs_pitch - threshold) / (1.0f - threshold);
    }
}

// --- The Mixer Interface ---
class Interface {
public:
    virtual void setup_motors(::AP_Motors6DOF* backend) = 0;
    virtual void mix(const MixerInputs& inputs, MixerState& state, MixerOutputs& outputs) = 0;
    virtual ~Interface() {}
};

class BlimpMixer;
class AvatarMixer;

} // namespace AP_Motors6DOF_Mixer