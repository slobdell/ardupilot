#include "TVC_Core.h"
#include "TVC_Filters.h"
#include "TVC_PID.h"
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
// This now defines two arbitrary points on the gain schedule spectrum.
// The system will create a linear function based on these two points.
const TVC_Config tvc_config = {
    .pitch_rate_tune_point_low  = {0.25f, 0.0036f, 0.0036f, 0.000011f}, // Tuned at low thrust (e.g., 25%)
    .pitch_rate_tune_point_high = {0.75f, 0.0018f, 0.0036f, 0.0000055f},// Tuned at high thrust (e.g., 75%)
    .roll_rate_tune_point_low   = {0.25f, 0.001f, 0.001f, 0.000005899f},
    .roll_rate_tune_point_high  = {0.75f, 0.0005f, 0.001f, 0.0000029f},
    .pitch_angle      = {1.5, 0.0, 0.015},
    .roll_angle       = {1.5, 0.0, 0.015},
    .i_max_angle      = 100.0,
    .i_max_pitch_rate = 240.0,
    .i_max_roll_rate  = 500.0
};

// =============================================================================
// --- HELPER PROTOTYPES (Internal to this file) ---
// =============================================================================
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
    
#if !OPEN_LOOP_SERVO_MODE
    // 1. --- FAILSAFE CHECKS (Closed-Loop Only) ---
    if (!inputs.ahrs_healthy) {
        outputs.pitch_angle_norm = 0.0f;
        outputs.roll_angle_norm = 0.0f;
        outputs.total_throttle = sbus_pwm_to_float(inputs.rc_in[THRUST_CHANNEL], 0.0f, 1.0f);
        return outputs;
    }
#endif

    bool all_motors_commanded_off = true;
    for (int i = 0; i < NUM_PODS; i++) {
        if (inputs.rc_in[i] > MOTOR_OFF_THRESHOLD) {
            all_motors_commanded_off = false;
            break;
        }
    }

    if (inputs.in_failsafe || all_motors_commanded_off) {
        outputs.pitch_angle_norm = 0.0f;
        outputs.roll_angle_norm = 0.0f;
        outputs.total_throttle = sbus_pwm_to_float(inputs.rc_in[THRUST_CHANNEL], 0.0f, 1.0f);
        state.pitch_angle_pid.reset();
        state.roll_angle_pid.reset();
        state.pitch_rate_pid.reset();
        return outputs;
    }

    // 2. --- DE-INTERPOLATE INPUTS ---
    float thrust_cmd  = sbus_pwm_to_float(inputs.rc_in[THRUST_CHANNEL],  0.0f, 1.0f);
    float forward_cmd = sbus_pwm_to_float(inputs.rc_in[FORWARD_CHANNEL],-1.0f, 1.0f);
    float lateral_cmd = sbus_pwm_to_float(inputs.rc_in[LATERAL_CHANNEL],-1.0f, 1.0f);

    // 2. --- INPUT SHAPING (Altitude Priority) ---
    // Prioritize altitude control by budgeting thrust. The total thrust vector magnitude cannot exceed 1.0.
    float vertical_thrust_component = thrust_cmd;

    // Calculate the maximum available thrust for horizontal movement using pythagorean theorem.
    // a^2 + b^2 = c^2  =>  b = sqrt(c^2 - a^2), where c is the max thrust of 1.0.
    float max_horizontal_component = 0.0f;
    if (1.0f > vertical_thrust_component) {
        max_horizontal_component = sqrtf(1.0f - (vertical_thrust_component * vertical_thrust_component));
    }

    // Get the magnitude of the pilot's current horizontal request.
    float requested_horizontal_magnitude = sqrtf(powf(forward_cmd, 2) + powf(lateral_cmd, 2));

    // If the requested horizontal thrust exceeds the available budget, scale it back.
    if (requested_horizontal_magnitude > max_horizontal_component) {
        if (requested_horizontal_magnitude > 0.0f) {
            float scale_factor = max_horizontal_component / requested_horizontal_magnitude;
            forward_cmd *= scale_factor;
            lateral_cmd *= scale_factor;
        }
    }

#if VTOL_MODE == false
    float base_throttles[NUM_PODS];
    for(int i=0; i<NUM_PODS; ++i) {
        base_throttles[i] = sbus_pwm_to_float(inputs.rc_in[i], 0.0f, 1.0f);
    }
#endif
  
    // 3. --- GAIN SCHEDULING (y = mx + c from two points) ---
    float vector_magnitude = sqrtf(powf(thrust_cmd, 2) + powf(forward_cmd, 2) + powf(lateral_cmd, 2));
    vector_magnitude = constrain_float(vector_magnitude, 0.0, 1.0);
#if !PID_TUNING_MODE

    // --- Pitch Rate Gains ---
    float pitch_thrust_delta = config.pitch_rate_tune_point_high.thrust_point - config.pitch_rate_tune_point_low.thrust_point;
    if (fabsf(pitch_thrust_delta) < 1e-6) {
        // Thrust points are the same, use the 'low' point as a constant gain to avoid division by zero.
        state.pitch_rate_pid.p = config.pitch_rate_tune_point_low.p;
        state.pitch_rate_pid.i = config.pitch_rate_tune_point_low.i;
        state.pitch_rate_pid.d = config.pitch_rate_tune_point_low.d;
    } else {
        // Calculate slope (m) and y-intercept (c) for each gain
        float p_gain_slope = (config.pitch_rate_tune_point_high.p - config.pitch_rate_tune_point_low.p) / pitch_thrust_delta;
        float p_gain_y_intercept = config.pitch_rate_tune_point_low.p - p_gain_slope * config.pitch_rate_tune_point_low.thrust_point;
        state.pitch_rate_pid.p = p_gain_slope * vector_magnitude + p_gain_y_intercept;

        float i_gain_slope = (config.pitch_rate_tune_point_high.i - config.pitch_rate_tune_point_low.i) / pitch_thrust_delta;
        float i_gain_y_intercept = config.pitch_rate_tune_point_low.i - i_gain_slope * config.pitch_rate_tune_point_low.thrust_point;
        state.pitch_rate_pid.i = i_gain_slope * vector_magnitude + i_gain_y_intercept;

        float d_gain_slope = (config.pitch_rate_tune_point_high.d - config.pitch_rate_tune_point_low.d) / pitch_thrust_delta;
        float d_gain_y_intercept = config.pitch_rate_tune_point_low.d - d_gain_slope * config.pitch_rate_tune_point_low.thrust_point;
        state.pitch_rate_pid.d = d_gain_slope * vector_magnitude + d_gain_y_intercept;
    }

    // --- Roll Rate Gains ---
    float roll_thrust_delta = config.roll_rate_tune_point_high.thrust_point - config.roll_rate_tune_point_low.thrust_point;
    if (fabsf(roll_thrust_delta) < 1e-6) {
        // Thrust points are the same, use the 'low' point as a constant gain.
        state.roll_rate_pid.p = config.roll_rate_tune_point_low.p;
        state.roll_rate_pid.i = config.roll_rate_tune_point_low.i;
        state.roll_rate_pid.d = config.roll_rate_tune_point_low.d;
    } else {
        float p_gain_slope = (config.roll_rate_tune_point_high.p - config.roll_rate_tune_point_low.p) / roll_thrust_delta;
        float p_gain_y_intercept = config.roll_rate_tune_point_low.p - p_gain_slope * config.roll_rate_tune_point_low.thrust_point;
        state.roll_rate_pid.p = p_gain_slope * vector_magnitude + p_gain_y_intercept;

        float i_gain_slope = (config.roll_rate_tune_point_high.i - config.roll_rate_tune_point_low.i) / roll_thrust_delta;
        float i_gain_y_intercept = config.roll_rate_tune_point_low.i - i_gain_slope * config.roll_rate_tune_point_low.thrust_point;
        state.roll_rate_pid.i = i_gain_slope * vector_magnitude + i_gain_y_intercept;

        float d_gain_slope = (config.roll_rate_tune_point_high.d - config.roll_rate_tune_point_low.d) / roll_thrust_delta;
        float d_gain_y_intercept = config.roll_rate_tune_point_low.d - d_gain_slope * config.roll_rate_tune_point_low.thrust_point;
        state.roll_rate_pid.d = d_gain_slope * vector_magnitude + d_gain_y_intercept;
    }
#endif // !PID_TUNING_MODE

    // 4. --- GET STATE & CALCULATE TARGETS ---
    // In OPEN_LOOP_SERVO_MODE, we still need current pitch for vector compensation
    float current_pitch_deg = degrees(inputs.pitch_rad);
    // float current_roll_deg = degrees(inputs.roll_rad); // Unused for pitch comp but good for consistency

#if !OPEN_LOOP_SERVO_MODE
    float current_roll_rate_dps = degrees(inputs.gyro.x);
    float current_pitch_rate_dps = degrees(inputs.gyro.y);
#endif

    float target_pitch_rad = atan2f(forward_cmd, thrust_cmd);
    float target_pitch_deg = degrees(target_pitch_rad);
    float down_and_forward_mag = sqrtf(powf(forward_cmd, 2) + powf(thrust_cmd, 2));
    float target_roll_rad = atan2f(lateral_cmd, down_and_forward_mag);
    float target_roll_deg = degrees(target_roll_rad);

    // --- COMMAND LIMITING ---
    // Limit the stick-commanded angle to the safe target range before compensation.
    // This ensures the "absolute" angle relative to the ground is capped.
    target_pitch_deg = constrain_float(target_pitch_deg, -MAX_TARGET_ANGLE_DEG, MAX_TARGET_ANGLE_DEG);
    target_roll_deg  = constrain_float(target_roll_deg, -MAX_TARGET_ANGLE_DEG, MAX_TARGET_ANGLE_DEG);

    // --- PITCH COMPENSATION ---
    // Offset the servo pitch target by the aircraft's current pitch to maintain absolute vector angle.
    // Example: If aircraft pitches up (+30 deg), servos tilt forward (+30 deg) to stay vertical.
    target_pitch_deg += current_pitch_deg;

    // 5. --- RUN PID CONTROLLERS ---
#if !OPEN_LOOP_SERVO_MODE
    float target_pitch_rate = state.pitch_angle_pid.update(inputs.now_us, current_pitch_deg, target_pitch_deg, state.pitch_saturated);
    float target_roll_rate = state.roll_angle_pid.update(inputs.now_us, current_roll_deg, target_roll_deg, state.roll_saturated);
    target_pitch_rate = state.target_pitch_rate_filter.filterIn(target_pitch_rate);
    target_roll_rate = state.target_roll_rate_filter.filterIn(target_roll_rate);

    float vector_pitch_out = state.pitch_rate_pid.update(inputs.now_us, current_pitch_rate_dps, target_pitch_rate, state.pitch_saturated);
    float vector_roll_out  = state.roll_rate_pid.update(inputs.now_us, current_roll_rate_dps, target_roll_rate, state.roll_saturated);
#else
    // --- NEW: OPEN LOOP MODE (Piecewise Normalization) ---
    // Normalize the target physical angle into a -1.0 to 1.0 command.
    // This uses a piecewise function to correctly handle asymmetric ranges.
    float vector_pitch_out;
    if (target_pitch_deg >= 0) {
        vector_pitch_out = target_pitch_deg / FORWARD_FLIGHT_PHYSICAL_ANGLE_DEG;
    } else {
        vector_pitch_out = target_pitch_deg / fabsf(REVERSE_FLIGHT_PHYSICAL_ANGLE_DEG);
    }

    float vector_roll_out;
    if (target_roll_deg >= 0) {
        vector_roll_out = target_roll_deg / FORWARD_FLIGHT_PHYSICAL_ANGLE_DEG;
    } else {
        vector_roll_out = target_roll_deg / fabsf(REVERSE_FLIGHT_PHYSICAL_ANGLE_DEG);
    }
#endif

    // 6. --- SATURATION & THRUST COMPENSATION ---
#if VTOL_MODE == true
    // --- NEW: VTOL Servo Saturation Logic ---
    // In VTOL mode, the PID output is a direct servo command.
    // We clip it to a normalized range (e.g., -1.0 to 1.0) that the SFC
    // will map to the servo's PWM range.

    // Store the original command to check for saturation.
    float original_pitch_out = vector_pitch_out;
    float original_roll_out = vector_roll_out;

    // Constrain the output to the valid normalized range.
    vector_pitch_out = constrain_float(vector_pitch_out, -1.0f, 1.0f);
    vector_roll_out = constrain_float(vector_roll_out, -1.0f, 1.0f);

    // Update the saturation flags. Saturation now means the servo is being
    // commanded to its physical limit. This is still important feedback for the PID's anti-windup.
    state.pitch_saturated = (fabsf(original_pitch_out - vector_pitch_out) > 1e-6);
    state.roll_saturated = (fabsf(original_roll_out - vector_roll_out) > 1e-6);

#else
    // --- ORIGINAL: Multicopter Saturation Logic ---
    clip_vectors_for_saturation(base_throttles, &vector_pitch_out, &vector_roll_out, state.pitch_saturated, state.roll_saturated);
#endif

    // Calculate total magnitude of the pilot's 3D request (Vertical + Forward + Lateral)
    float total_throttle = sqrtf(powf(forward_cmd, 2) + powf(lateral_cmd, 2) + powf(thrust_cmd, 2));
    total_throttle = constrain_float(total_throttle, 0.0f, 1.0f);

#if VTOL_MODE == true
    // --- VTOL ANGLE BLENDING LOGIC ---
    float transition_progress = sbus_pwm_to_float(inputs.rc_in[TRANSITION_PROGRESS_CHANNEL], 0.0f, 1.0f);
    
    // Model A: Hover Control Output (already calculated and compensated)
    float hover_model_pitch_output = vector_pitch_out;
    float hover_model_roll_output = vector_roll_out;

    // Model B: Forward Flight Control (Fixed Angle Command)
    // No compensation here as requested; motors clamp to full forward.
    float fw_model_pitch_output = FORWARD_FLIGHT_PHYSICAL_ANGLE_DEG / FORWARD_FLIGHT_PHYSICAL_ANGLE_DEG; // 1.0f
    float fw_model_roll_output = 0.0f; 

    // Linearly interpolate between the two model outputs.
    vector_pitch_out = (1.0f - transition_progress) * hover_model_pitch_output + transition_progress * fw_model_pitch_output;
    vector_roll_out  = (1.0f - transition_progress) * hover_model_roll_output  + transition_progress * fw_model_roll_output;
    
    // Ensure final blended output is still within bounds
    vector_pitch_out = constrain_float(vector_pitch_out, -1.0f, 1.0f);
#endif

    // 7. --- ENCODE OUTPUTS ---
    // Direct float assignment (No SBUS packing)
    outputs.pitch_angle_norm = vector_pitch_out;
    outputs.roll_angle_norm = vector_roll_out;
    outputs.total_throttle = total_throttle;

    // 8. --- POPULATE DEBUG DATA ---
    outputs.debug_data.forward_cmd = forward_cmd;
    outputs.debug_data.lateral_cmd = lateral_cmd;
    outputs.debug_data.thrust_cmd = thrust_cmd;
    outputs.debug_data.vector_magnitude = vector_magnitude;
    outputs.debug_data.target_pitch_deg = target_pitch_deg;
    outputs.debug_data.target_roll_deg = target_roll_deg;
    outputs.debug_data.vector_pitch_out = vector_pitch_out;
    outputs.debug_data.vector_roll_out = vector_roll_out;
    outputs.debug_data.thrust_factor = thrust_factor;
    outputs.debug_data.pitch_saturated = state.pitch_saturated;
    outputs.debug_data.roll_saturated = state.roll_saturated;

    // 9. --- PASS HEALTH STATUS TO OUTPUTS ---
    outputs.tvc_healthy = inputs.ahrs_healthy;

    return outputs;
}

// =============================================================================
// --- HELPER IMPLEMENTATIONS (No HAL Dependencies) ---
// =============================================================================

// float_to_sbus_pwm removed.

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
