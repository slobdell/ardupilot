#include "Copter.h"
#include "custom_main.h"
#include <AP_Vehicle/AP_Vehicle.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_HAL/AP_HAL.h>
#include <AP_Notify/AP_Notify.h>
#include <AP_SerialManager/AP_SerialManager.h>
#include <RC_Channel/RC_Channel.h>
#include <SRV_Channel/SRV_Channel.h>
#include "filters.h"
#include "PID.h"

// =============================================================================
// --- GLOBAL STATE & OBJECTS ---
// =============================================================================
// Global state variables for this file
static uint32_t last_log_time = 0;
static uint32_t loop_counter = 0;

// =============================================================================
// --- MAIN ENTRY POINT (Humble I/O Layer) ---
// =============================================================================
void newMain()
{
    // Initialization of state and hardware
    static LinearPIDController static_pitch_rate_pid(tvc_config.pitch_rate_low.p, tvc_config.pitch_rate_low.i, tvc_config.pitch_rate_low.d, tvc_config.i_max_pitch_rate);
    static LinearPIDController static_roll_rate_pid(tvc_config.roll_rate_low.p, tvc_config.roll_rate_low.i, tvc_config.roll_rate_low.d, tvc_config.i_max_roll_rate);
    static LinearPIDController static_pitch_angle_pid(tvc_config.pitch_angle.p, tvc_config.pitch_angle.i, tvc_config.pitch_angle.d, tvc_config.i_max_angle);
    static LinearPIDController static_roll_angle_pid(tvc_config.roll_angle.p, tvc_config.roll_angle.i, tvc_config.roll_angle.d, tvc_config.i_max_angle);
    static CustomFilter static_target_pitch_rate_filter(20.0 * 2, (1.0/400.0), IIR::ORDER::OD2, IIR::TYPE::LOWPASS);
    static CustomFilter static_target_roll_rate_filter(20.0 * 2, (1.0/400.0), IIR::ORDER::OD2, IIR::TYPE::LOWPASS);

    static TVC_State state = {
        static_pitch_rate_pid,
        static_roll_rate_pid,
        static_pitch_angle_pid,
        static_roll_angle_pid,
        static_target_pitch_rate_filter,
        static_target_roll_rate_filter,
        false,
        false
    };

    static bool initialized = false;
    if (!initialized) {
        AP_HAL::UARTDriver *debug_uart = AP::serialmanager().get_serial_by_id(SERIAL_NUM);
        if (debug_uart != nullptr) {
            debug_uart->begin(BAUD);
        }
        #if defined(FILTER_D) && FILTER_D == true
            state.pitch_rate_pid.useDFilter((.75 * 20.0), (1.0/400.0));
            state.roll_rate_pid.useDFilter((.75 * 20.0), (1.0/400.0));
        #endif
        last_log_time = AP_HAL::millis();
        initialized = true;
    }

    loop_counter++;

    // 1. --- GATHER INPUTS from HAL ---
    TVC_Inputs inputs;
    inputs.ahrs_healthy = AP::ahrs().healthy();
    inputs.in_failsafe = rc().in_rc_failsafe();
    for (int i = 0; i < 16; i++) {
        inputs.rc_in[i] = RC_Channels::get_radio_in(i);
    }
    AP::vehicle()->get_osd_roll_pitch_rad(inputs.roll_rad, inputs.pitch_rad);
    
    // Convert ArduPilot Vector3f to our platform-independent TVC_Vector3f
    const Vector3f &gyro_ap = copter.attitude_control->get_latest_gyro();
    inputs.gyro.x = gyro_ap.x;
    inputs.gyro.y = gyro_ap.y;
    inputs.gyro.z = gyro_ap.z;
    
    inputs.now_us = AP_HAL::micros();

    // 5. --- CALL PURE LOGIC CORE ---
    TVC_Outputs outputs = tvc_run_main_logic(inputs, state, tvc_config);

    // 6. --- UPDATE ARDUPILOT NOTIFICATION SYSTEM ---
    // Set the AP_Notify EKF_BAD flag based on the TVC's health.
    // If the TVC is unhealthy, this will force the main status LED red.
    AP_Notify::flags.ekf_bad = !outputs.tvc_healthy;

    // 7. --- WRITE OUTPUTS TO SBUS ---
    // Write SBUS outputs
    for (int i = 0; i < (NUM_PODS * 2 + 1); i++) {
        SRV_Channels::set_output_pwm_chan(i, outputs.sbus_outputs[i]);
    }

    // Write logging outputs
    uint32_t current_time_ms = AP_HAL::millis();
    if (current_time_ms - last_log_time >= LOG_PERIOD) {
        AP_HAL::UARTDriver *debug_uart = AP::serialmanager().get_serial_by_id(SERIAL_NUM);
        if (debug_uart != nullptr) {
            float elapsed_secs = (current_time_ms - last_log_time) / 1000.0f;
            float loop_hz = (float)loop_counter / elapsed_secs;
            const TVC_Debug_Data& d = outputs.debug_data;

            debug_uart->printf("---------- TVC STATUS REPORT ----------\n");
            debug_uart->printf("SYSTEM | Freq: %.1f Hz\n", loop_hz);
            debug_uart->printf("INPUTS | Fwd: %.2f, Lat: %.2f, Thr: %.2f\n", d.forward_cmd, d.lateral_cmd, d.thrust_cmd);
            debug_uart->printf("STATE  | Pitch curr: %.2f, targ: %.2f | Roll curr: %.2f, targ: %.2f\n", degrees(inputs.pitch_rad), d.target_pitch_deg, degrees(inputs.roll_rad), d.target_roll_deg);
            debug_uart->printf("PID    | Pitch sat: %d, out: %.3f | Roll sat: %d, out: %.3f\n", d.pitch_saturated, d.vector_pitch_out, d.roll_saturated, d.vector_roll_out);
            debug_uart->printf("OUTPUT | VecP: %.3f, VecR: %.3f, Factor: %.3f\n", d.vector_pitch_out, d.vector_roll_out, d.thrust_factor);
            debug_uart->printf("---------------------------------------\n");
        }
        last_log_time = current_time_ms;
        loop_counter = 0;
    }
}
