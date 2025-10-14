#include "custom_main.h"
#include "filters.h"
#include "PID.h"
#include <cmath> // For sqrtf, powf, atan2f, cosf
#include <algorithm> // For std::min

// =============================================================================
// --- TVC CONFIGURATION & CONSTANTS ---
// =============================================================================
#define PER_POD_SCALING true
#define FILTER_D true

// --- CustomFilter Constants ---
#define GYRO_HZ 400  // ArduCopter main loop rate
#define SAMPLE_TIME (1.0 / (double)GYRO_HZ)
#define IMU_CUTOFF_FREQUENCY 20.0
#define D_CUTOFF_FREQUENCY (.75 * IMU_CUTOFF_FREQUENCY)
#define MOTOR_OFF_THRESHOLD 1063 // SBUS PWM threshold for motors off

// --- TVC Configuration Instance ---
const TVC_Config tvc_config = {
    .pitch_rate_low   = {0.0036, 0.0036, 0.000011},
    .pitch_rate_high  = {0.0018, 0.0036, 0.0000055},
    .roll_rate_low    = {0.001, 0.001, 0.000005899},
    .roll_rate_high   = {0.0005, 0.001, 0.0000029},
    .pitch_angle      = {1.5, 0.0, 0.015},
    .roll_angle       = {1.5, 0.0, 0.015},
    .i_max_angle      = 100.0,
    .i_max_pitch_rate = 240.0,
    .i_max_roll_rate  = 500.0
};

// --- SBUS Channel Mapping ---
const int THRUST_CHANNEL  = 6; // Channel 7
const int FORWARD_CHANNEL = 7; // Channel 8
const int LATERAL_CHANNEL = 8; // Channel 9

// SBUS PWM Value Ranges
const int SBUS_MIN_PWM = 1000;
const int SBUS_MAX_PWM = 2000;

const float MAX_TARGET_ANGLE_DEG = 45.0f;
const float MAX_SAFE_ANGLE_RAD = MAX_TARGET_ANGLE_DEG * (M_PI / 180.0);
const float max_tan_angle = tanf(MAX_TARGET_ANGLE_DEG * M_PI / 180.0);

// =============================================================================
// --- HELPER PROTOTYPES (Internal to this file) ---
// =============================================================================
float sbus_pwm_to_float(int pwm, float min_float, float max_float);
int float_to_sbus_pwm(float float_val, float min_float, float max_float);
void clip_vectors_for_saturation(float base_throttles[], float* vector_pitch, float* vector_roll, bool& pitch_saturated, bool& roll_saturated);

// Helper to constrain a float value
static inline float constrain_float(float val, float min, float max) {
    return std::min(max, std::max(min, val));
}

// Helper to convert radians to degrees
static inline float degrees(float rad) {
    return rad * (180.0f / M_PI);
}


// =============================================================================
// --- CORE LOGIC IMPLEMENTATION (No HAL Dependencies) ---
// =============================================================================

TVC_Outputs tvc_run_main_logic(const TVC_Inputs& inputs, TVC_State& state, const TVC_Config& config)
{
    TVC_Outputs outputs;
    
    // 1. --- FAILSAFE CHECKS ---
    if (!inputs.ahrs_healthy) {
#if PER_POD_SCALING
        for (int i = 0; i < NUM_PODS * 2; i++) {
            outputs.sbus_outputs[i] = float_to_sbus_pwm(0.0f, -1.0f, 1.0f);
        }
        outputs.sbus_outputs[12] = float_to_sbus_pwm(1.0f, 1.0f, 1.5f);
#else
        outputs.sbus_outputs[0] = float_to_sbus_pwm(0.0f, -1.0f, 1.0f);
        outputs.sbus_outputs[1] = float_to_sbus_pwm(0.0f, -1.0f, 1.0f);
        outputs.sbus_outputs[2] = float_to_sbus_pwm(1.0f, 1.0f, 1.5f);
#endif
        return outputs;
    }

    bool all_motors_commanded_off = true;
    for (int i = 0; i < NUM_PODS; i++) {
        if (inputs.rc_in[i] > MOTOR_OFF_THRESHOLD) {
            all_motors_commanded_off = false;
            break;
        }
    }

    if (inputs.in_failsafe || all_motors_commanded_off) {
#if PER_POD_SCALING
        for (int i = 0; i < NUM_PODS * 2; i++) {
            outputs.sbus_outputs[i] = float_to_sbus_pwm(0.0f, -1.0f, 1.0f);
        }
        outputs.sbus_outputs[12] = float_to_sbus_pwm(1.0f, 1.0f, 1.5f);
#else
        outputs.sbus_outputs[0] = float_to_sbus_pwm(0.0f, -1.0f, 1.0f);
        outputs.sbus_outputs[1] = float_to_sbus_pwm(0.0f, -1.0f, 1.0f);
        outputs.sbus_outputs[2] = float_to_sbus_pwm(1.0f, 1.0f, 1.5f);
#endif
        state.pitch_angle_pid.reset();
        state.roll_angle_pid.reset();
        state.pitch_rate_pid.reset();
        state.roll_rate_pid.reset();
        state.target_pitch_rate_filter.filterIn(0);
        state.target_roll_rate_filter.filterIn(0);
        return outputs;
    }

    // 2. --- DE-INTERPOLATE INPUTS ---
    float thrust_cmd  = sbus_pwm_to_float(inputs.rc_in[THRUST_CHANNEL],  0.0f, 1.0f);
    float forward_cmd = sbus_pwm_to_float(inputs.rc_in[FORWARD_CHANNEL],-1.0f, 1.0f);
    float lateral_cmd = sbus_pwm_to_float(inputs.rc_in[LATERAL_CHANNEL],-1.0f, 1.0f);

    float max_horizontal_magnitude = thrust_cmd * max_tan_angle;
    float current_horizontal_magnitude = sqrtf(powf(forward_cmd, 2) + powf(lateral_cmd, 2));
    if (current_horizontal_magnitude > max_horizontal_magnitude) {
        if (current_horizontal_magnitude > 0.0f) {
            float scale_factor = max_horizontal_magnitude / current_horizontal_magnitude;
            forward_cmd *= scale_factor;
            lateral_cmd *= scale_factor;
        }
    }

    float base_throttles[NUM_PODS];
    for(int i=0; i<NUM_PODS; ++i) {
        base_throttles[i] = sbus_pwm_to_float(inputs.rc_in[i], 0.0f, 1.0f);
    }
  
    // 3. --- GAIN SCHEDULING ---
    float vector_magnitude = sqrtf(powf(thrust_cmd, 2) + powf(forward_cmd, 2) + powf(lateral_cmd, 2));
    vector_magnitude = constrain_float(vector_magnitude, 0.0, 1.0);
  
    state.pitch_rate_pid.p = config.pitch_rate_low.p + (config.pitch_rate_high.p - config.pitch_rate_low.p) * vector_magnitude;
    state.pitch_rate_pid.d = config.pitch_rate_low.d + (config.pitch_rate_high.d - config.pitch_rate_low.d) * vector_magnitude;
    state.pitch_rate_pid.i = config.pitch_rate_low.i + (config.pitch_rate_high.i - config.pitch_rate_low.i) * vector_magnitude;

    state.roll_rate_pid.p = config.roll_rate_low.p + (config.roll_rate_high.p - config.roll_rate_low.p) * vector_magnitude;
    state.roll_rate_pid.d = config.roll_rate_low.d + (config.roll_rate_high.d - config.roll_rate_low.d) * vector_magnitude;
    state.roll_rate_pid.i = config.roll_rate_low.i + (config.roll_rate_high.i - config.roll_rate_low.i) * vector_magnitude;

    // 4. --- GET STATE & CALCULATE TARGETS ---
    float current_roll_deg = degrees(inputs.roll_rad);
    float current_pitch_deg = degrees(inputs.pitch_rad);
    
    float current_roll_rate_dps = degrees(inputs.gyro.x);
    float current_pitch_rate_dps = degrees(inputs.gyro.y);

    float target_pitch_rad = atan2f(forward_cmd, thrust_cmd);
    float target_pitch_deg = degrees(target_pitch_rad);
    float down_and_forward_mag = sqrtf(powf(forward_cmd, 2) + powf(thrust_cmd, 2));
    float target_roll_rad = atan2f(lateral_cmd, down_and_forward_mag);
    float target_roll_deg = degrees(target_roll_rad);

    // 5. --- RUN PID CONTROLLERS ---
    float target_pitch_rate = state.pitch_angle_pid.update(inputs.now_us, current_pitch_deg, target_pitch_deg, state.pitch_saturated);
    float target_roll_rate = state.roll_angle_pid.update(inputs.now_us, current_roll_deg, target_roll_deg, state.roll_saturated);
    target_pitch_rate = state.target_pitch_rate_filter.filterIn(target_pitch_rate);
    target_roll_rate = state.target_roll_rate_filter.filterIn(target_roll_rate);

    float vector_pitch_out = state.pitch_rate_pid.update(inputs.now_us, current_pitch_rate_dps, target_pitch_rate, state.pitch_saturated);
    float vector_roll_out  = state.roll_rate_pid.update(inputs.now_us, current_roll_rate_dps, target_roll_rate, state.roll_saturated);

    // 6. --- SATURATION & THRUST COMPENSATION ---
    clip_vectors_for_saturation(base_throttles, &vector_pitch_out, &vector_roll_out, state.pitch_saturated, state.roll_saturated);

    float target_pitch_rad_clamped = constrain_float(target_pitch_rad, -MAX_SAFE_ANGLE_RAD, MAX_SAFE_ANGLE_RAD);
    float target_roll_rad_clamped = constrain_float(target_roll_rad, -MAX_SAFE_ANGLE_RAD, MAX_SAFE_ANGLE_RAD);

    float thrust_factor = 1.0f / (cosf(target_pitch_rad_clamped) * cosf(target_roll_rad_clamped));
    thrust_factor = constrain_float(thrust_factor, 1.0f, 1.5f);

    // 7. --- ENCODE OUTPUTS ---
#if PER_POD_SCALING
    float average_throttle = 0.0f;
    for (int i = 0; i < NUM_PODS; i++) {
        average_throttle += base_throttles[i];
    }
    average_throttle /= NUM_PODS;

    for (int i = 0; i < NUM_PODS; i++) {
        float scale_factor = 1.0f;
        if (average_throttle > 1e-6 && base_throttles[i] > 1e-6) {
            scale_factor = average_throttle / base_throttles[i];
        }
        float scaled_pitch = vector_pitch_out * scale_factor;
        float scaled_roll = vector_roll_out * scale_factor;
        outputs.sbus_outputs[i * 2] = float_to_sbus_pwm(scaled_pitch, -1.0f, 1.0f);
        outputs.sbus_outputs[i * 2 + 1] = float_to_sbus_pwm(scaled_roll, -1.0f, 1.0f);
    }
    outputs.sbus_outputs[12] = float_to_sbus_pwm(thrust_factor, 1.0f, 1.5f);
#else
    outputs.sbus_outputs[0] = float_to_sbus_pwm(vector_pitch_out, -1.0f, 1.0f);
    outputs.sbus_outputs[1] = float_to_sbus_pwm(vector_roll_out, -1.0f, 1.0f);
    outputs.sbus_outputs[2] = float_to_sbus_pwm(thrust_factor, 1.0f, 1.5f);
#endif

    // 8. --- POPULATE DEBUG DATA ---
    outputs.debug_data.forward_cmd = forward_cmd;
    outputs.debug_data.lateral_cmd = lateral_cmd;
    outputs.debug_data.thrust_cmd = thrust_cmd;
    outputs.debug_data.target_pitch_deg = target_pitch_deg;
    outputs.debug_data.target_roll_deg = target_roll_deg;
    outputs.debug_data.vector_pitch_out = vector_pitch_out;
    outputs.debug_data.vector_roll_out = vector_roll_out;
    outputs.debug_data.thrust_factor = thrust_factor;
    outputs.debug_data.pitch_saturated = state.pitch_saturated;
    outputs.debug_data.roll_saturated = state.roll_saturated;

    return outputs;
}


// =============================================================================
// --- HELPER IMPLEMENTATIONS (No HAL Dependencies) ---
// =============================================================================

float sbus_pwm_to_float(int pwm, float min_float, float max_float) {
  // constrain_int16 is not available, use std::min/max
  int constrained_pwm = std::min(SBUS_MAX_PWM, std::max(SBUS_MIN_PWM, pwm));
  return (float)(constrained_pwm - SBUS_MIN_PWM) / (float)(SBUS_MAX_PWM - SBUS_MIN_PWM) * (max_float - min_float) + min_float;
}

int float_to_sbus_pwm(float float_val, float min_float, float max_float) {
  float_val = constrain_float(float_val, min_float, max_float);
  return (int)(((float_val - min_float) / (max_float - min_float)) * (SBUS_MAX_PWM - SBUS_MIN_PWM) + SBUS_MIN_PWM);
}

void clip_vectors_for_saturation(float base_throttles[], float* vector_pitch, float* vector_roll, bool& pitch_saturated, bool& roll_saturated) {
  pitch_saturated = false;
  roll_saturated = false;
  float max_base_throttle = 0.0f;
  float min_base_throttle = 1.0f;

  for (int i = 0; i < NUM_PODS; i++) {
    if (base_throttles[i] > max_base_throttle) {
      max_base_throttle = base_throttles[i];
    }
    if (base_throttles[i] < min_base_throttle) {
      min_base_throttle = base_throttles[i];
    }
  }

  float positive_headroom = 1.0f - max_base_throttle;
  float negative_headroom = min_base_throttle;
  float available_headroom = std::min(positive_headroom, negative_headroom);
  
  if (available_headroom < 0.0f) {
    available_headroom = 0.0f;
  }

  float original_pitch = *vector_pitch;
  float original_roll = *vector_roll;

  *vector_pitch = constrain_float(*vector_pitch, -available_headroom, available_headroom);
  *vector_roll = constrain_float(*vector_roll, -available_headroom, available_headroom);

  pitch_saturated = (fabsf(original_pitch - *vector_pitch) > 1e-6);
  roll_saturated = (fabsf(original_roll - *vector_roll) > 1e-6);
}
