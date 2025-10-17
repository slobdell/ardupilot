#pragma once

#include <stdint.h> // For uint32_t etc.
#include <algorithm> // For std::min/max
#include <cmath> // For M_PI

// SBUS PWM Value Ranges used by helper functions
const int SBUS_MIN_PWM = 1000;
const int SBUS_MAX_PWM = 2000;

// =============================================================================
// --- IN-FLIGHT TUNING CONFIGURATION ---
// =============================================================================

// Set to true to enable RC-based PID tuning mode.
// WARNING: This mode bypasses the saved PID gains from the config struct.
#define PID_TUNING_MODE true

// Define the RC input channels (0-indexed) for tuning, coming from the PFC SBUS.
// Corresponds to SBUS Channel 13 from PFC
#define TUNING_SELECTOR_CHANNEL 12
// Corresponds to SBUS Channel 14 from PFC
#define TUNING_VALUE_CHANNEL    13

// Define the min/max range for each gain.
// These ranges will be mapped to the 1000-2000us range of the value knob.
const float P_GAIN_MIN = 0.0f;
const float P_GAIN_MAX = 0.01f;

const float I_GAIN_MIN = 0.0f;
const float I_GAIN_MAX = 0.01f;

const float D_GAIN_MIN = 0.0f;
const float D_GAIN_MAX = 0.0001f;


// =============================================================================
// --- PLATFORM-INDEPENDENT TYPES ---
// =============================================================================

// A platform-independent replacement for ArduPilot's Vector3f
struct TVC_Vector3f {
    float x;
    float y;
    float z;
};


// =============================================================================
// --- CONFIGURATION STRUCTS ---
// =============================================================================

// Represents a single tuned point on the gain schedule spectrum.
struct PID_Gain_Tune_Point {
    const float thrust_point; // The vector_magnitude at which this gain was tuned (e.g., 0.25)
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

// Public declaration of the global config object.
// The definition is in custom_main.cpp
extern const TVC_Config tvc_config;


// =============================================================================
// --- DATA CONTRACTS (Structs for Dependency Injection) ---
// =============================================================================

// Forward-declare state objects to be included by pointer
class LinearPIDController;
class CustomFilter;

// Input structure: All data read from the ArduPilot HAL
struct TVC_Inputs {
    bool ahrs_healthy;
    bool in_failsafe;
    int rc_in[16];
    float roll_rad;
    float pitch_rad;
    TVC_Vector3f gyro;
    uint32_t now_us;
};

// Debug structure: Intermediate values for logging
struct TVC_Debug_Data {
    float forward_cmd;
    float lateral_cmd;
    float thrust_cmd;
    float vector_magnitude;
    float target_pitch_deg;
    float target_roll_deg;
    float vector_pitch_out;
    float vector_roll_out;
    float thrust_factor;
    bool pitch_saturated;
    bool roll_saturated;
};

// Output structure: All data to be written to the ArduPilot HAL
struct TVC_Outputs {
    int sbus_outputs[16];
    bool tvc_healthy;
    TVC_Debug_Data debug_data;
};

// State structure: All data that must persist between loops
const float MAX_TARGET_ANGLE_DEG = 60.0f;
const float MAX_SAFE_ANGLE_RAD = MAX_TARGET_ANGLE_DEG * (M_PI / 180.0);
const float MAX_THRUST_FACTOR = 1.0f / cosf(MAX_SAFE_ANGLE_RAD);
const float max_tan_angle = tanf(MAX_TARGET_ANGLE_DEG * M_PI / 180.0);

// NEW: Physical angle limits for the system's full range of motion.
// These define the maximum positive and negative physical tilt angles the system is designed to achieve.
const float FORWARD_FLIGHT_PHYSICAL_ANGLE_DEG = 93.0f; // Example: Max forward tilt for cruise
const float REVERSE_FLIGHT_PHYSICAL_ANGLE_DEG = -10.0f; // Example: Max reverse tilt

// =============================================================================
// --- HELPER PROTOTYPES (Internal to this file) ---
// =============================================================================
int float_to_sbus_pwm(float float_val, float min_float, float max_float);


struct TVC_State {
    LinearPIDController& pitch_rate_pid;
    LinearPIDController& roll_rate_pid;
    LinearPIDController& pitch_angle_pid;
    LinearPIDController& roll_angle_pid;
    CustomFilter& target_pitch_rate_filter;
    CustomFilter& target_roll_rate_filter;
    bool pitch_saturated;
    bool roll_saturated;
};


// =============================================================================


// --- FUNCTION PROTOTYPES ---


// =============================================================================








// Helper to convert SBUS PWM to a float


static inline float sbus_pwm_to_float(int pwm, float min_float, float max_float) {


  // constrain_int16 is not available, use std::min/max


  int constrained_pwm = std::min(SBUS_MAX_PWM, std::max(SBUS_MIN_PWM, pwm));


  return (float)(constrained_pwm - SBUS_MIN_PWM) / (float)(SBUS_MAX_PWM - SBUS_MIN_PWM) * (max_float - min_float) + min_float;


}
void newMain();

TVC_Outputs tvc_run_main_logic(const TVC_Inputs& inputs, TVC_State& state, const TVC_Config& config);
static const int BAUD = 115200;
static const int SERIAL_NUM = 4;
static const uint32_t LOG_PERIOD = 2000; // milliseconds

// --- Number of motor pods (for SBUS input and output) ---
#define NUM_PODS 6

// --- MASTER FEATURE FLAGS ---
#define VTOL_MODE false // Set to true for VTOL (tilt-rotor) mode, false for 6DOF multicopter.
#define OPEN_LOOP_SERVO_MODE false // NEW: Bypasses IMU/PIDs for direct servo control.

// --- SBUS Channel Mapping (from PFC) ---
const int THRUST_CHANNEL  = 6; // Channel 7
const int FORWARD_CHANNEL = 7; // Channel 8
const int LATERAL_CHANNEL = 8; // Channel 9

#if VTOL_MODE == true
    const int TRANSITION_PROGRESS_CHANNEL = 10; // SBUS Ch 11
    const int PLANE_THROTTLE_CHANNEL      = 11; // SBUS Ch 12
#endif

// --- TVC SBUS Output Channel Mapping (Bus B: TVC -> SFCs) ---
const int TVC_SBUS_OUT_PITCH_CH           = 0;
const int TVC_SBUS_OUT_ROLL_CH            = 1;
const int TVC_SBUS_OUT_MULTI_THRUST_FACTOR_CH = 2; // For original multicopter mode
const int TVC_SBUS_OUT_HOVER_THRUST_FACTOR_CH = 12; // For VTOL hover model
const int TVC_SBUS_OUT_HEALTH_CH          = 15;

// --- PID Tuning Mode ---
