#include "Copter.h"
#include "custom_main.h"
#include <AP_Vehicle/AP_Vehicle.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_SerialManager/AP_SerialManager.h>
#include <RC_Channel/RC_Channel.h>
#include <SRV_Channel/SRV_Channel.h>
#include "filters.h"
#include "PID.h"

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

// --- PID Gains for Gain Scheduling ---
const float P_PITCH_LOW = 0.0036;
const float I_PITCH_LOW = 0.0036;
const float D_PITCH_LOW = 0.000011;
const float P_ROLL_LOW = 0.001;
const float I_ROLL_LOW = 0.001;
const float D_ROLL_LOW = 0.000005899;

const float P_PITCH_HIGH = 0.0018;
const float I_PITCH_HIGH = 0.0036;
const float D_PITCH_HIGH = 0.0000055;
const float P_ROLL_HIGH = 0.0005;
const float I_ROLL_HIGH = 0.001;
const float D_ROLL_HIGH = 0.0000029;

// --- Fixed PID Gains (Outer Angle Loop) ---
const float P_PITCH_ANGLE = 1.5;
const float I_PITCH_ANGLE = 0.0;
const float D_PITCH_ANGLE = 0.015;
const float P_ROLL_ANGLE = 1.5;
const float I_ROLL_ANGLE = 0.0;
const float D_ROLL_ANGLE = 0.015;
const float I_MAX_ANGLE = 100.0;

// --- SBUS Channel Mapping (0-indexed from RC_Channels) ---
const int THRUST_CHANNEL  = 6; // Channel 7
const int FORWARD_CHANNEL = 7; // Channel 8
const int LATERAL_CHANNEL = 8; // Channel 9

// SBUS PWM Value Ranges (standard for ArduPilot)
const int SBUS_MIN_PWM = 1000;
const int SBUS_MAX_PWM = 2000;

const int numMotorVectors = 6;
const float MAX_TARGET_ANGLE_DEG = 45.0f;
const float MAX_SAFE_ANGLE_RAD = MAX_TARGET_ANGLE_DEG * (M_PI / 180.0);
const float max_tan_angle = tan(MAX_TARGET_ANGLE_DEG * M_PI / 180.0);

static bool pitch_saturated = false;
static bool roll_saturated = false;

#define LOG_PERIOD 2000 // milliseconds

// =============================================================================
// --- TVC GLOBAL VARIABLES & OBJECTS ---
// =============================================================================
CustomFilter target_pitch_rate_filter(IMU_CUTOFF_FREQUENCY * 2, SAMPLE_TIME, IIR::ORDER::OD2, IIR::TYPE::LOWPASS);
CustomFilter target_roll_rate_filter(IMU_CUTOFF_FREQUENCY * 2, SAMPLE_TIME, IIR::ORDER::OD2, IIR::TYPE::LOWPASS);

LinearPIDController pitch_rate_pid(P_PITCH_LOW, I_PITCH_LOW, D_PITCH_LOW, 240.0);
LinearPIDController roll_rate_pid(P_ROLL_LOW, I_ROLL_LOW, D_ROLL_LOW, 500.0);

LinearPIDController pitch_angle_pid(P_PITCH_ANGLE, I_PITCH_ANGLE, D_PITCH_ANGLE, I_MAX_ANGLE);
LinearPIDController roll_angle_pid(P_ROLL_ANGLE, I_ROLL_ANGLE, D_ROLL_ANGLE, I_MAX_ANGLE);

// State variables
float current_pitch_deg = 0.0f, current_roll_deg = 0.0f, current_pitch_rate_dps = 0.0f, current_roll_rate_dps = 0.0f;

// Logging
uint32_t last_log_time = 0;
uint32_t loop_counter = 0;

// Debug Serial Port
const int BAUD = 115200;
const int SERIAL_NUM = 4;

// =============================================================================
// --- TVC HELPER FUNCTIONS ---
// =============================================================================
float sbus_pwm_to_float(int pwm, float min_float, float max_float);
int float_to_sbus_pwm(float float_val, float min_float, float max_float);
void clip_vectors_for_saturation(float base_throttles[], float* vector_pitch, float* vector_roll);

float sbus_pwm_to_float(int pwm, float min_float, float max_float) {
  pwm = constrain_int16(pwm, SBUS_MIN_PWM, SBUS_MAX_PWM);
  return (float)(pwm - SBUS_MIN_PWM) / (float)(SBUS_MAX_PWM - SBUS_MIN_PWM) * (max_float - min_float) + min_float;
}

int float_to_sbus_pwm(float float_val, float min_float, float max_float) {
  float_val = constrain_float(float_val, min_float, max_float);
  return (int)(((float_val - min_float) / (max_float - min_float)) * (SBUS_MAX_PWM - SBUS_MIN_PWM) + SBUS_MIN_PWM);
}

void clip_vectors_for_saturation(float base_throttles[], float* vector_pitch, float* vector_roll) {
  pitch_saturated = false;
  roll_saturated = false;
  float max_base_throttle = 0.0f;
  float min_base_throttle = 1.0f;

  for (int i = 0; i < 6; i++) {
    if (base_throttles[i] > max_base_throttle) {
      max_base_throttle = base_throttles[i];
    }
    if (base_throttles[i] < min_base_throttle) {
      min_base_throttle = base_throttles[i];
    }
  }

  float positive_headroom = 1.0f - max_base_throttle;
  float negative_headroom = min_base_throttle;
  float available_headroom = MIN(positive_headroom, negative_headroom);
  
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


// =============================================================================
// --- MAIN ENTRY POINT ---
// =============================================================================
void newMain()
{
    static bool initialized = false;
    if (!initialized) {
        AP_HAL::UARTDriver *debug_uart = AP::serialmanager().get_serial_by_id(SERIAL_NUM);
        if (debug_uart != nullptr) {
            debug_uart->begin(BAUD);
        }
        if(FILTER_D) {
            pitch_rate_pid.useDFilter(D_CUTOFF_FREQUENCY, SAMPLE_TIME);
            roll_rate_pid.useDFilter(D_CUTOFF_FREQUENCY, SAMPLE_TIME);
        }
        last_log_time = AP_HAL::millis();
        initialized = true;
    }

    loop_counter++;

    // 1. --- FAILSAFE CHECKS ---
    if (!AP::ahrs().healthy()) {
      // Do nothing if AHRS is not ready
      return;
    }

    bool failsafe = rc().in_rc_failsafe();
    bool all_motors_commanded_off = true;
    for (int i = 0; i < 6; i++) {
        if (RC_Channels::get_radio_in(i) > MOTOR_OFF_THRESHOLD) {
            all_motors_commanded_off = false;
            break;
        }
    }

    if (failsafe || all_motors_commanded_off) {
#if PER_POD_SCALING
        // Zero out all 12 vector channels for the 6 pods
        for (int i = 0; i < numMotorVectors * 2; i++) {
            SRV_Channels::set_output_pwm_chan(i, float_to_sbus_pwm(0.0f, -1.0f, 1.0f));
        }
        // Set neutral thrust factor on the 13th channel
        SRV_Channels::set_output_pwm_chan(12, float_to_sbus_pwm(1.0f, 1.0f, 1.5f));
#else
        SRV_Channels::set_output_pwm_chan(0, float_to_sbus_pwm(0.0f, -1.0f, 1.0f)); // vector_pitch
        SRV_Channels::set_output_pwm_chan(1, float_to_sbus_pwm(0.0f, -1.0f, 1.0f)); // vector_roll
        SRV_Channels::set_output_pwm_chan(2, float_to_sbus_pwm(1.0f, 1.0f, 1.5f)); // thrust_factor
#endif

        pitch_angle_pid.reset();
        roll_angle_pid.reset();
        pitch_rate_pid.reset();
        roll_rate_pid.reset();
        target_pitch_rate_filter.filterIn(0);
        target_roll_rate_filter.filterIn(0);
        return;
    }

    // 2. --- DE-INTERPOLATE INPUTS ---
    float thrust_cmd  = sbus_pwm_to_float(RC_Channels::get_radio_in(THRUST_CHANNEL),  0.0f, 1.0f);
    float forward_cmd = sbus_pwm_to_float(RC_Channels::get_radio_in(FORWARD_CHANNEL),-1.0f, 1.0f);
    float lateral_cmd = sbus_pwm_to_float(RC_Channels::get_radio_in(LATERAL_CHANNEL),-1.0f, 1.0f);

    float max_horizontal_magnitude = thrust_cmd * max_tan_angle;
    float current_horizontal_magnitude = sqrtf(powf(forward_cmd, 2) + powf(lateral_cmd, 2));
    if (current_horizontal_magnitude > max_horizontal_magnitude) {
        if (current_horizontal_magnitude > 0.0f) {
            float scale_factor = max_horizontal_magnitude / current_horizontal_magnitude;
            forward_cmd *= scale_factor;
            lateral_cmd *= scale_factor;
        }
    }

    float base_throttles[numMotorVectors];
    for(int i=0; i<numMotorVectors; ++i) {
        base_throttles[i] = sbus_pwm_to_float(RC_Channels::get_radio_in(i), 0.0f, 1.0f);
    }
  
    // 3. --- GAIN SCHEDULING ---
    float vector_magnitude = sqrtf(powf(thrust_cmd, 2) + powf(forward_cmd, 2) + powf(lateral_cmd, 2));
    vector_magnitude = constrain_float(vector_magnitude, 0.0, 1.0);
  
    pitch_rate_pid.p = P_PITCH_LOW + (P_PITCH_HIGH - P_PITCH_LOW) * vector_magnitude;
    pitch_rate_pid.d = D_PITCH_LOW + (D_PITCH_HIGH - D_PITCH_LOW) * vector_magnitude;
    pitch_rate_pid.i = I_PITCH_LOW + (I_PITCH_HIGH - I_PITCH_LOW) * vector_magnitude;

    roll_rate_pid.p = P_ROLL_LOW + (P_ROLL_HIGH - P_ROLL_LOW) * vector_magnitude;
    roll_rate_pid.d = D_ROLL_LOW + (D_ROLL_HIGH - D_ROLL_LOW) * vector_magnitude;
    roll_rate_pid.i = I_ROLL_LOW + (I_ROLL_HIGH - I_ROLL_LOW) * vector_magnitude;

    // 4. --- GET STATE & CALCULATE TARGETS ---
    float roll_rad = 0, pitch_rad = 0;
    AP::vehicle()->get_osd_roll_pitch_rad(roll_rad, pitch_rad);
    current_roll_deg = degrees(roll_rad);
    current_pitch_deg = degrees(pitch_rad);
    
    const Vector3f &gyro = copter.attitude_control->get_latest_gyro();
    current_roll_rate_dps = degrees(gyro.x);
    current_pitch_rate_dps = degrees(gyro.y);

    float target_pitch_rad = atan2f(forward_cmd, thrust_cmd);
    float target_pitch_deg = degrees(target_pitch_rad);
    float down_and_forward_mag = sqrtf(powf(forward_cmd, 2) + powf(thrust_cmd, 2));
    float target_roll_rad = atan2f(lateral_cmd, down_and_forward_mag);
    float target_roll_deg = degrees(target_roll_rad);

    // 5. --- RUN PID CONTROLLERS ---
    uint32_t now_us = AP_HAL::micros();
    float target_pitch_rate = pitch_angle_pid.update(now_us, current_pitch_deg, target_pitch_deg, pitch_saturated);
    float target_roll_rate = roll_angle_pid.update(now_us, current_roll_deg, target_roll_deg, roll_saturated);
    target_pitch_rate = target_pitch_rate_filter.filterIn(target_pitch_rate);
    target_roll_rate = target_roll_rate_filter.filterIn(target_roll_rate);

    float vector_pitch_out = pitch_rate_pid.update(now_us, current_pitch_rate_dps, target_pitch_rate, pitch_saturated);
    float vector_roll_out  = roll_rate_pid.update(now_us, current_roll_rate_dps, target_roll_rate, roll_saturated);

    // 6. --- SATURATION & THRUST COMPENSATION ---
    clip_vectors_for_saturation(base_throttles, &vector_pitch_out, &vector_roll_out);

    float current_pitch_rad_clamped = constrain_float(pitch_rad, -MAX_SAFE_ANGLE_RAD, MAX_SAFE_ANGLE_RAD);
    float current_roll_rad_clamped = constrain_float(roll_rad, -MAX_SAFE_ANGLE_RAD, MAX_SAFE_ANGLE_RAD);

    float thrust_factor = 1.0f / (cosf(current_pitch_rad_clamped) * cosf(current_roll_rad_clamped));
    thrust_factor = constrain_float(thrust_factor, 1.0f, 1.5f);

    // 7. --- ENCODE & TRANSMIT OUTPUTS ---
#if PER_POD_SCALING
    // New Per-Pod Scaling Logic
    float average_throttle = 0.0f;
    for (int i = 0; i < numMotorVectors; i++) {
        average_throttle += base_throttles[i];
    }
    average_throttle /= numMotorVectors;

    for (int i = 0; i < numMotorVectors; i++) {
        float scale_factor = 1.0f;
        // Avoid division by zero and instability at low throttle
        if (average_throttle > 1e-6 && base_throttles[i] > 1e-6) {
            scale_factor = average_throttle / base_throttles[i];
        }

        float scaled_pitch = vector_pitch_out * scale_factor;
        float scaled_roll = vector_roll_out * scale_factor;

        // Write scaled pitch and roll for this pod to its dedicated channels
        SRV_Channels::set_output_pwm_chan(i * 2, float_to_sbus_pwm(scaled_pitch, -1.0f, 1.0f));
        SRV_Channels::set_output_pwm_chan(i * 2 + 1, float_to_sbus_pwm(scaled_roll, -1.0f, 1.0f));
    }

    // Write the single global thrust factor to the 13th channel (index 12)
    SRV_Channels::set_output_pwm_chan(12, float_to_sbus_pwm(thrust_factor, 1.0f, 1.5f));
#else
    // Original Global Command Logic
    SRV_Channels::set_output_pwm_chan(0, float_to_sbus_pwm(vector_pitch_out, -1.0f, 1.0f));
    SRV_Channels::set_output_pwm_chan(1, float_to_sbus_pwm(vector_roll_out, -1.0f, 1.0f));
    SRV_Channels::set_output_pwm_chan(2, float_to_sbus_pwm(thrust_factor, 1.0f, 1.5f));
#endif

    // 8. --- LOGGING ---
    uint32_t current_time_ms = AP_HAL::millis();
    if (current_time_ms - last_log_time >= LOG_PERIOD) {
        AP_HAL::UARTDriver *debug_uart = AP::serialmanager().get_serial_by_id(SERIAL_NUM);
        if (debug_uart != nullptr) {
            float elapsed_secs = (current_time_ms - last_log_time) / 1000.0f;
            float loop_hz = (float)loop_counter / elapsed_secs;

            debug_uart->printf("---------- TVC STATUS REPORT ----------\n");
            debug_uart->printf("SYSTEM | Freq: %.1f Hz\n", loop_hz);
            debug_uart->printf("INPUTS | Fwd: %.2f, Lat: %.2f, Thr: %.2f\n", forward_cmd, lateral_cmd, thrust_cmd);
            debug_uart->printf("STATE  | Pitch curr: %.2f, targ: %.2f | Roll curr: %.2f, targ: %.2f\n", current_pitch_deg, target_pitch_deg, current_roll_deg, target_roll_deg);
            debug_uart->printf("PID    | Pitch sat: %d, out: %.3f | Roll sat: %d, out: %.3f\n", pitch_saturated, vector_pitch_out, roll_saturated, vector_roll_out);
            debug_uart->printf("OUTPUT | VecP: %.3f, VecR: %.3f, Factor: %.3f\n", vector_pitch_out, vector_roll_out, thrust_factor);
            debug_uart->printf("---------------------------------------\n");
        }
        last_log_time = current_time_ms;
        loop_counter = 0;
    }
}

// Remove the old example functions as they are no longer needed.
void exampleReadInput() {}
void exampleOutput() {}
