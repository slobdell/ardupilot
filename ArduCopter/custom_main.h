#pragma once

#include <stdint.h> // For uint32_t etc.

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

struct Rate_PID_Gains {
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
    const Rate_PID_Gains pitch_rate_low;
    const Rate_PID_Gains pitch_rate_high;
    const Rate_PID_Gains roll_rate_low;
    const Rate_PID_Gains roll_rate_high;

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





// The main entry point, implemented in the _ardupilot.cpp file


void newMain();





// The pure logic core, implemented in the main .cpp file


TVC_Outputs tvc_run_main_logic(const TVC_Inputs& inputs, TVC_State& state, const TVC_Config& config);








// =============================================================================


// --- SHARED CONSTANTS ---


// =============================================================================


static const int BAUD = 115200;


static const int SERIAL_NUM = 4;


static const uint32_t LOG_PERIOD = 2000; // milliseconds

const int NUM_PODS = 6;
