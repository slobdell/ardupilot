#include "AP_CustomConfig.h"

const CustomConfig blimpConfig = {
    .run_custom_loop = false,
    .force_6dof_attitude_controller = true,
    .lateral_motors_config4 = false,
    .caterpillar_h_frame_6dof = false,
    .lifting_motors_reversible = false,
    .mot_spin_neutral = 1500,
    .mot_spin_min = 1000,
    .acro_yaw_gain = 1.0f,
    .failsafe_kill_motors = true,
    .indoor_aircraft = false,
    .diff_yaw_enabled = 0,
    .visodom_primary_compass = false,
    .optical_flow_stabilized_roll = true,
    .optical_flow_stabilized_pitch = true,
    .disable_position_heading_loiter = false,
    .custom_weathervane = false,
    .enable_tricopter_vtol_backend = 1,
    .tricopter_is_blimp = true,
    .emergency_blimp_manual_mode = true,
    .forward_flight_physical_angle_deg = 180.0f,
    .reverse_flight_physical_angle_deg = -90.0f,
    .platform_max_angle_deg = 45.0f
};

const CustomConfig avatarConfig = {
    .run_custom_loop = false,
    .force_6dof_attitude_controller = true,
    .lateral_motors_config4 = false,
    .caterpillar_h_frame_6dof = false,
    .lifting_motors_reversible = false,
    .mot_spin_neutral = 1000, // Avatar might not use reversible motors by default
    .mot_spin_min = 1000,
    .acro_yaw_gain = 1.0f,
    .failsafe_kill_motors = true,
    .indoor_aircraft = false,
    .diff_yaw_enabled = 1,    // Avatar might use differential yaw
    .visodom_primary_compass = false,
    .optical_flow_stabilized_roll = false,
    .optical_flow_stabilized_pitch = false,
    .disable_position_heading_loiter = false,
    .custom_weathervane = false,
    .enable_tricopter_vtol_backend = 1,
    .tricopter_is_blimp = false,
    .emergency_blimp_manual_mode = false,
    .forward_flight_physical_angle_deg = 90.0f, // Standard VTOL tilt
    .reverse_flight_physical_angle_deg = 0.0f,
    .platform_max_angle_deg = 90.0f
};

#if ACTIVE_CONFIG == CONFIG_TYPE_BLIMP
const CustomConfig& g_config = blimpConfig;
#elif ACTIVE_CONFIG == CONFIG_TYPE_AVATAR
const CustomConfig& g_config = avatarConfig;
#endif
