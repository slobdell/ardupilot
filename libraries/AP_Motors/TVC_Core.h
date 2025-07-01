#pragma once

#include <stdint.h> // For uint32_t etc.
#include <algorithm> // For std::min/max
#include <cmath> // For M_PI
#include <AP_CustomConfig/AP_CustomConfig.h>

// If custom_main.h (legacy caterpillar code) was included first in this TU,
// it already defined these types and constants. Skip redefinition to prevent
// ODR errors. TVC_Core.cpp and all normal users never define this sentinel.
#ifndef CUSTOM_MAIN_LEGACY_TYPES_DEFINED

// SBUS PWM Value Ranges used by helper functions
const int SBUS_MIN_PWM = 1000;
const int SBUS_MAX_PWM = 2000;

// =============================================================================
// --- IN-FLIGHT TUNING CONFIGURATION ---
// =============================================================================

#define PID_TUNING_MODE true

#define TUNING_SELECTOR_CHANNEL 12
#define TUNING_VALUE_CHANNEL    13

const float P_GAIN_MIN = 0.0f;
const float P_GAIN_MAX = 0.01f;

const float I_GAIN_MIN = 0.0f;
const float I_GAIN_MAX = 0.01f;

const float D_GAIN_MIN = 0.0f;
const float D_GAIN_MAX = 0.0001f;


// =============================================================================
// --- PLATFORM-INDEPENDENT TYPES ---
// =============================================================================

struct TVC_Vector3f {
    float x;
    float y;
    float z;
};


// =============================================================================
// --- CONFIGURATION STRUCTS ---
// =============================================================================

struct PID_Gain_Tune_Point {
    const float thrust_point;
    const float p;
    const float i;
    const float d;
};

struct Angle_PID_Gains {
    const float p;
    const float i;
    const float d;
};

struct TVC_Config {
    const PID_Gain_Tune_Point pitch_rate_tune_point_low;
    const PID_Gain_Tune_Point pitch_rate_tune_point_high;
    const PID_Gain_Tune_Point roll_rate_tune_point_low;
    const PID_Gain_Tune_Point roll_rate_tune_point_high;

    const Angle_PID_Gains pitch_angle;
    const Angle_PID_Gains roll_angle;

    const float i_max_angle;
    const float i_max_pitch_rate;
    const float i_max_roll_rate;
};

extern const TVC_Config tvc_config;


// =============================================================================
// --- DATA CONTRACTS ---
// =============================================================================

class LinearPIDController;
class CustomFilter;

struct TVC_Inputs {
    bool ahrs_healthy;
    bool in_failsafe;
    int rc_in[16];
    float roll_rad;
    float pitch_rad;
    TVC_Vector3f gyro;
    uint32_t now_us;
};

struct TVC_Debug_Data {
    float forward_cmd;
    float lateral_cmd;
    float thrust_cmd;
    float vector_magnitude;
    float target_pitch_deg;
    float target_roll_deg;
    float vector_pitch_out;
    float vector_roll_out;
    float total_throttle;
    bool pitch_saturated;
    bool roll_saturated;
};

struct TVC_Outputs {
    float pitch_angle_norm; // -1.0 to 1.0
    float roll_angle_norm;  // -1.0 to 1.0
    float total_throttle;   // 0.0 to 1.0 (Total Vector Magnitude)
    bool tvc_healthy;
    TVC_Debug_Data debug_data;
};

const float MAX_TARGET_ANGLE_DEG = 180.0f;
const float MAX_SAFE_ANGLE_RAD = MAX_TARGET_ANGLE_DEG * (M_PI / 180.0);
const float MAX_THRUST_FACTOR = 1.0f / cosf(MAX_SAFE_ANGLE_RAD);
const float max_tan_angle = tanf(MAX_TARGET_ANGLE_DEG * M_PI / 180.0);

const float VERTICAL_THROTTLE_DEADBAND = 0.05f;
const float MANUAL_YAW_DEADBAND = 0.05f;

// --- SBUS Channel Mapping (from PFC) ---
const int THRUST_CHANNEL  = 6; // Channel 7
const int FORWARD_CHANNEL = 7; // Channel 8
const int LATERAL_CHANNEL = 8; // Channel 9

// --- Logging config ---
static const int BAUD = 115200;
static const int SERIAL_NUM = 4;
static const uint32_t LOG_PERIOD = 2000; // milliseconds

static inline float sbus_pwm_to_float(int pwm, float min_float, float max_float) {
    int constrained_pwm = std::min(SBUS_MAX_PWM, std::max(SBUS_MIN_PWM, pwm));
    return (float)(constrained_pwm - SBUS_MIN_PWM) / (float)(SBUS_MAX_PWM - SBUS_MIN_PWM) * (max_float - min_float) + min_float;
}

#endif // CUSTOM_MAIN_LEGACY_TYPES_DEFINED


// =============================================================================
// --- TYPES UNIQUE TO TVC_Core.h (never in custom_main.h) ---
// =============================================================================

struct TVC_CoreState {
    LinearPIDController& pitch_rate_pid;
    LinearPIDController& roll_rate_pid;
    LinearPIDController& pitch_angle_pid;
    LinearPIDController& roll_angle_pid;
    CustomFilter& target_pitch_rate_filter;
    CustomFilter& target_roll_rate_filter;
    bool& pitch_saturated;
    bool& roll_saturated;
};

void newMain();
TVC_Outputs tvc_run_main_logic(const TVC_Inputs& inputs, TVC_CoreState& state, const TVC_Config& config);

// --- MASTER FEATURE FLAGS ---
#ifndef NUM_PODS
#define NUM_PODS 6
#endif

#ifndef VTOL_MODE
#define VTOL_MODE true
#endif

#ifndef OPEN_LOOP_SERVO_MODE
#define OPEN_LOOP_SERVO_MODE true
#endif

// --- PID Tuning Mode (guarded in case custom_main.h defined it) ---
#ifndef PID_TUNING_MODE
#define PID_TUNING_MODE true
#endif

#if VTOL_MODE == true
    const int TRANSITION_PROGRESS_CHANNEL = 10; // SBUS Ch 11
    const int PLANE_THROTTLE_CHANNEL      = 11; // SBUS Ch 12
#endif
