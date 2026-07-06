#ifndef CUSTOM_CONFIG_H
#define CUSTOM_CONFIG_H

#include <stdint.h>

// Configuration Types (Preprocessor compatible)
#define CONFIG_TYPE_BLIMP 0
#define CONFIG_TYPE_AVATAR 1

// --- ACTIVE CONFIGURATION SELECTOR ---
#define ACTIVE_CONFIG CONFIG_TYPE_AVATAR
// -------------------------------------

struct CustomConfig {
    bool run_custom_loop;
    bool force_6dof_attitude_controller;
    bool lateral_motors_config4;
    bool caterpillar_h_frame_6dof;
    bool lifting_motors_reversible;
    int16_t mot_spin_neutral;
    int16_t mot_spin_min;
    float acro_yaw_gain;
    bool failsafe_kill_motors;
    bool failsafe_disarm_when_landed; // [AV-INVAR:fs-ground-disarm] RC linkloss + !is_flying + thrust quiet => disarm
    bool indoor_aircraft;
    int diff_yaw_enabled;
    bool visodom_primary_compass;
    bool optical_flow_stabilized_roll;
    bool optical_flow_stabilized_pitch;
    bool disable_position_heading_loiter;
    bool custom_weathervane;
    int enable_tricopter_vtol_backend;
    bool tricopter_is_blimp;
    bool emergency_blimp_manual_mode;
    float forward_flight_physical_angle_deg; // Physical servo limit: angle corresponding to SERVO5_MIN
    float cruise_physical_angle_deg;         // Cruise equilibrium angle (≤ forward_flight_physical_angle_deg)
    float reverse_flight_physical_angle_deg;
    float platform_max_angle_deg;
    float elevator_tilt_handoff_point; // 0.0-1.0: fraction of pitch demand where elevator saturates and motor tilt begins
};

extern const CustomConfig blimpConfig;
extern const CustomConfig avatarConfig;
extern const CustomConfig& g_config;

// --- Preprocessor Compatibility Layer ---
// These MUST remain defines because they are used in #if directives.
#if ACTIVE_CONFIG == CONFIG_TYPE_BLIMP
    #define ENABLE_TRICOPTER_VTOL_BACKEND 1
    #define RUN_CUSTOM_LOOP false
    #define EMERGENCY_BLIMP_MANUAL_MODE true
#elif ACTIVE_CONFIG == CONFIG_TYPE_AVATAR
    #define ENABLE_TRICOPTER_VTOL_BACKEND 1
    #define RUN_CUSTOM_LOOP false
    #define EMERGENCY_BLIMP_MANUAL_MODE false // Placeholder for Avatar
#endif

#define EXTERNAL_YAW_CONTROL (g_config.diff_yaw_enabled == 0)

#define AP_MOTORS_MATRIX_YAW_FACTOR_CW   (-(float)g_config.diff_yaw_enabled)
#define AP_MOTORS_MATRIX_YAW_FACTOR_CCW   ((float)g_config.diff_yaw_enabled)

#endif // CUSTOM_CONFIG_H