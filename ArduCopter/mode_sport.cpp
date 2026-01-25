#include "Copter.h"
#include <AP_CustomConfig/AP_CustomConfig.h>

#if MODE_SPORT_ENABLED

/*
 * Init and run calls for sport flight mode
 */

// sport_init - initialise sport controller
bool ModeSport::init(bool ignore_checks)
{
    // set vertical speed and acceleration limits
    pos_control->set_max_speed_accel_z(-get_pilot_speed_dn(), g.pilot_speed_up, g.pilot_accel_z);
    pos_control->set_correction_speed_accel_z(-get_pilot_speed_dn(), g.pilot_speed_up, g.pilot_accel_z);

    // initialise the vertical position controller
    if (!pos_control->is_active_z()) {
        pos_control->init_z_controller();
    }

    return true;
}

// sport_run - runs the sport controller
// should be called at 100hz or more
void ModeSport::run_OBSOLETE()
{
    // set vertical speed and acceleration limits
    pos_control->set_max_speed_accel_z(-get_pilot_speed_dn(), g.pilot_speed_up, g.pilot_accel_z);

    // apply SIMPLE mode transform
    update_simple_mode();

    // get pilot's desired roll and pitch rates

    // calculate rate requests
    float target_roll_rate = channel_roll->get_control_in() * g2.command_model_acro_rp.get_rate() * 100.0 / ROLL_PITCH_YAW_INPUT_MAX;
    float target_pitch_rate = channel_pitch->get_control_in() * g2.command_model_acro_rp.get_rate() * 100.0 / ROLL_PITCH_YAW_INPUT_MAX;

    // SBL CUSTOM HACKS
    if(g_config.force_6dof_attitude_controller) {
      target_roll_rate = 0;
      target_pitch_rate = 0;
    }

    // get attitude targets
    const Vector3f att_target = attitude_control->get_att_target_euler_cd();

    // Calculate trainer mode earth frame rate command for roll
    int32_t roll_angle = wrap_180_cd(att_target.x);
    target_roll_rate -= constrain_int32(roll_angle, -ACRO_LEVEL_MAX_ANGLE, ACRO_LEVEL_MAX_ANGLE) * g.acro_balance_roll;

    // Calculate trainer mode earth frame rate command for pitch
    int32_t pitch_angle = wrap_180_cd(att_target.y);
    target_pitch_rate -= constrain_int32(pitch_angle, -ACRO_LEVEL_MAX_ANGLE, ACRO_LEVEL_MAX_ANGLE) * g.acro_balance_pitch;

    const float angle_max = copter.aparm.angle_max;
    if (roll_angle > angle_max){
        target_roll_rate +=  sqrt_controller(angle_max - roll_angle, g2.command_model_acro_rp.get_rate() * 100.0 / ACRO_LEVEL_MAX_OVERSHOOT, attitude_control->get_accel_roll_max_cdss(), G_Dt);
    }else if (roll_angle < -angle_max) {
        target_roll_rate +=  sqrt_controller(-angle_max - roll_angle, g2.command_model_acro_rp.get_rate() * 100.0 / ACRO_LEVEL_MAX_OVERSHOOT, attitude_control->get_accel_roll_max_cdss(), G_Dt);
    }

    if (pitch_angle > angle_max){
        target_pitch_rate +=  sqrt_controller(angle_max - pitch_angle, g2.command_model_acro_rp.get_rate() * 100.0 / ACRO_LEVEL_MAX_OVERSHOOT, attitude_control->get_accel_pitch_max_cdss(), G_Dt);
    }else if (pitch_angle < -angle_max) {
        target_pitch_rate +=  sqrt_controller(-angle_max - pitch_angle, g2.command_model_acro_rp.get_rate() * 100.0 / ACRO_LEVEL_MAX_OVERSHOOT, attitude_control->get_accel_pitch_max_cdss(), G_Dt);
    }

    // get pilot's desired yaw rate
    float target_yaw_rate = get_pilot_desired_yaw_rate();

    // get pilot desired climb rate
    float target_climb_rate = get_pilot_desired_climb_rate(channel_throttle->get_control_in());
    target_climb_rate = constrain_float(target_climb_rate, -get_pilot_speed_dn(), g.pilot_speed_up);

    // Sport State Machine Determination
    AltHoldModeState sport_state = get_alt_hold_state(target_climb_rate);

    // State Machine
    switch (sport_state) {

    case AltHoldModeState::MotorStopped:
        attitude_control->reset_rate_controller_I_terms();
        attitude_control->reset_yaw_target_and_rate(false);
        pos_control->relax_z_controller(0.0f);   // forces throttle output to decay to zero
        break;

    case AltHoldModeState::Landed_Ground_Idle:
        attitude_control->reset_yaw_target_and_rate();
        FALLTHROUGH;

    case AltHoldModeState::Landed_Pre_Takeoff:
        attitude_control->reset_rate_controller_I_terms_smoothly();
        pos_control->relax_z_controller(0.0f);   // forces throttle output to decay to zero
        break;

    case AltHoldModeState::Takeoff:
        // initiate take-off
        if (!takeoff.running()) {
            takeoff.start(constrain_float(g.pilot_takeoff_alt,0.0f,1000.0f));
        }

        // get avoidance adjusted climb rate
        target_climb_rate = get_avoidance_adjusted_climbrate(target_climb_rate);

        // set position controller targets adjusted for pilot input
        takeoff.do_pilot_takeoff(target_climb_rate);
        break;

    case AltHoldModeState::Flying:
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::THROTTLE_UNLIMITED);

        // get avoidance adjusted climb rate
        target_climb_rate = get_avoidance_adjusted_climbrate(target_climb_rate);

#if AP_RANGEFINDER_ENABLED
        // update the vertical offset based on the surface measurement
        copter.surface_tracking.update_surface_offset();
#endif

        // Send the commanded climb rate to the position controller
        pos_control->set_pos_target_z_from_climb_rate_cm(target_climb_rate);
        break;
    }

    // call attitude controller
    attitude_control->input_euler_rate_roll_pitch_yaw(target_roll_rate, target_pitch_rate, target_yaw_rate);

    // run the vertical position controller and set output throttle
    pos_control->update_z_controller();

    // SBL CUSTOM HACK
    if(g_config.force_6dof_attitude_controller) {
        motors->set_forward(-0.5 * channel_pitch->norm_input_dz());
        motors->set_lateral(0.5 * channel_roll->norm_input_dz());
    }
}

void ModeSport::run()
{
    // set vertical speed and acceleration limits
    pos_control->set_max_speed_accel_z(-get_pilot_speed_dn(), g.pilot_speed_up, g.pilot_accel_z);

    // this line unnecessary because it only affects pitch and roll
    // apply SIMPLE mode transform
    // update_simple_mode();

    // convert the input to the desired body frame rate
    float target_roll, target_pitch, target_yaw;
    get_pilot_desired_angle_rates(channel_roll->norm_input_dz(), channel_pitch->norm_input_dz(), channel_yaw->norm_input_dz(), target_roll, target_pitch, target_yaw);

    if (!motors->armed()) {
        // Motors should be Stopped
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::SHUT_DOWN);
    } else if (copter.ap.throttle_zero
               || (copter.air_mode == AirMode::AIRMODE_ENABLED && motors->get_spool_state() == AP_Motors::SpoolState::SHUT_DOWN)) {
        // throttle_zero is never true in air mode, but the motors should be allowed to go through ground idle
        // in order to facilitate the spoolup block

        // Attempting to Land or motors not yet spinning
        // if airmode is enabled only an actual landing will spool down the motors
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::GROUND_IDLE);
    } else {
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::THROTTLE_UNLIMITED);
    }

    // get pilot desired climb rate
    float target_climb_rate = get_pilot_desired_climb_rate(channel_throttle->get_control_in());
    target_climb_rate = constrain_float(target_climb_rate, -get_pilot_speed_dn(), g.pilot_speed_up);

    // Sport State Machine Determination
    AltHoldModeState sport_state = get_alt_hold_state(target_climb_rate);
    // State Machine
    switch (sport_state) {

    case AltHoldModeState::MotorStopped:
        attitude_control->reset_rate_controller_I_terms();
        attitude_control->reset_yaw_target_and_rate(false);
        pos_control->relax_z_controller(0.0f);   // forces throttle output to decay to zero
        break;

    case AltHoldModeState::Landed_Ground_Idle:
        attitude_control->reset_yaw_target_and_rate();
        FALLTHROUGH;

    case AltHoldModeState::Landed_Pre_Takeoff:
        attitude_control->reset_rate_controller_I_terms_smoothly();
        pos_control->relax_z_controller(0.0f);   // forces throttle output to decay to zero
        break;

    case AltHoldModeState::Takeoff:
        // initiate take-off
        if (!takeoff.running()) {
            takeoff.start(constrain_float(g.pilot_takeoff_alt,0.0f,1000.0f));
        }

        // get avoidance adjusted climb rate
        target_climb_rate = get_avoidance_adjusted_climbrate(target_climb_rate);

        // set position controller targets adjusted for pilot input
        takeoff.do_pilot_takeoff(target_climb_rate);
        break;

    case AltHoldModeState::Flying:
        motors->set_desired_spool_state(AP_Motors::DesiredSpoolState::THROTTLE_UNLIMITED);

        // get avoidance adjusted climb rate
        target_climb_rate = get_avoidance_adjusted_climbrate(target_climb_rate);

        // update the vertical offset based on the surface measurement
        copter.surface_tracking.update_surface_offset();

        // Send the commanded climb rate to the position controller
        pos_control->set_pos_target_z_from_climb_rate_cm(target_climb_rate);
        break;
    }

    // run attitude controller
    if (g2.acro_options.get() & uint8_t(ModeAcro::AcroOptions::RATE_LOOP_ONLY)) {
        attitude_control->input_rate_bf_roll_pitch_yaw_2(target_roll, target_pitch, target_yaw);
    } else {
        attitude_control->input_rate_bf_roll_pitch_yaw(target_roll, target_pitch, target_yaw);
    }

    // run the vertical position controller and set output throttle
    pos_control->update_z_controller();

    // output pilot's throttle without angle boost
    // attitude_control->set_throttle_out(pilot_desired_throttle, false, copter.g.throttle_filt);
    // SBL CUSTOM HACK
    motors->set_forward(-0.5 * channel_pitch->norm_input_dz());
    motors->set_lateral(0.5 * channel_roll->norm_input_dz());
}


// get_pilot_desired_angle_rates - transform pilot's normalised roll pitch and yaw input into a desired lean angle rates
// inputs are -1 to 1 and the function returns desired angle rates in centi-degrees-per-second
void ModeSport::get_pilot_desired_angle_rates(float roll_in, float pitch_in, float yaw_in, float &roll_out, float &pitch_out, float &yaw_out)
{
    // SBL CUSTOM HACK
    roll_in = 0;
    pitch_in = 0;

    float rate_limit;
    Vector3f rate_ef_level_cd, rate_bf_level_cd, rate_bf_request_cd;

    // apply circular limit to pitch and roll inputs
    float total_in = norm(pitch_in, roll_in);

    if (total_in > 1.0) {
        float ratio = 1.0 / total_in;
        roll_in *= ratio;
        pitch_in *= ratio;
    }

    // calculate roll, pitch rate requests

    // roll expo
    rate_bf_request_cd.x = g2.command_model_acro_rp.get_rate() * 100.0 * input_expo(roll_in, g2.command_model_acro_rp.get_expo());

    // pitch expo
    rate_bf_request_cd.y = g2.command_model_acro_rp.get_rate() * 100.0 * input_expo(pitch_in, g2.command_model_acro_rp.get_expo());

    // yaw expo
    rate_bf_request_cd.z = g2.command_model_acro_y.get_rate() * 100.0 * input_expo(yaw_in, g2.command_model_acro_y.get_expo());

    // calculate earth frame rate corrections to pull the copter back to level while in ACRO mode

    if (g.acro_trainer != (uint8_t)ModeAcro::Trainer::OFF) {

        // get attitude targets
        const Vector3f att_target = attitude_control->get_att_target_euler_cd();

        // Calculate trainer mode earth frame rate command for roll
        int32_t roll_angle = wrap_180_cd(att_target.x);
        rate_ef_level_cd.x = -constrain_int32(roll_angle, -ACRO_LEVEL_MAX_ANGLE, ACRO_LEVEL_MAX_ANGLE) * g.acro_balance_roll;

        // Calculate trainer mode earth frame rate command for pitch
        int32_t pitch_angle = wrap_180_cd(att_target.y);
        rate_ef_level_cd.y = -constrain_int32(pitch_angle, -ACRO_LEVEL_MAX_ANGLE, ACRO_LEVEL_MAX_ANGLE) * g.acro_balance_pitch;

        // Calculate trainer mode earth frame rate command for yaw
        rate_ef_level_cd.z = 0;

        // Calculate angle limiting earth frame rate commands
        if (g.acro_trainer == (uint8_t)ModeAcro::Trainer::LIMITED) {
            const float angle_max = copter.aparm.angle_max;
            if (roll_angle > angle_max){
                rate_ef_level_cd.x += sqrt_controller(angle_max - roll_angle, g2.command_model_acro_rp.get_rate() * 100.0 / ACRO_LEVEL_MAX_OVERSHOOT, attitude_control->get_accel_roll_max_cdss(), G_Dt);
            }else if (roll_angle < -angle_max) {
                rate_ef_level_cd.x += sqrt_controller(-angle_max - roll_angle, g2.command_model_acro_rp.get_rate() * 100.0 / ACRO_LEVEL_MAX_OVERSHOOT, attitude_control->get_accel_roll_max_cdss(), G_Dt);
            }

            if (pitch_angle > angle_max){
                rate_ef_level_cd.y += sqrt_controller(angle_max - pitch_angle, g2.command_model_acro_rp.get_rate() * 100.0 / ACRO_LEVEL_MAX_OVERSHOOT, attitude_control->get_accel_pitch_max_cdss(), G_Dt);
            }else if (pitch_angle < -angle_max) {
                rate_ef_level_cd.y += sqrt_controller(-angle_max - pitch_angle, g2.command_model_acro_rp.get_rate() * 100.0 / ACRO_LEVEL_MAX_OVERSHOOT, attitude_control->get_accel_pitch_max_cdss(), G_Dt);
            }
        }

        // convert earth-frame level rates to body-frame level rates
        attitude_control->euler_rate_to_ang_vel(attitude_control->get_attitude_target_quat(), rate_ef_level_cd, rate_bf_level_cd);

        // combine earth frame rate corrections with rate requests
        if (g.acro_trainer == (uint8_t)ModeAcro::Trainer::LIMITED) {
            rate_bf_request_cd.x += rate_bf_level_cd.x;
            rate_bf_request_cd.y += rate_bf_level_cd.y;
            rate_bf_request_cd.z += rate_bf_level_cd.z;
        }else{
            float acro_level_mix = constrain_float(1-float(MAX(MAX(abs(roll_in), abs(pitch_in)), abs(yaw_in))/4500.0), 0, 1)*ahrs.cos_pitch();

            // Scale levelling rates by stick input
            rate_bf_level_cd = rate_bf_level_cd * acro_level_mix;

            // Calculate rate limit to prevent change of rate through inverted
            rate_limit = fabsf(fabsf(rate_bf_request_cd.x)-fabsf(rate_bf_level_cd.x));
            rate_bf_request_cd.x += rate_bf_level_cd.x;
            rate_bf_request_cd.x = constrain_float(rate_bf_request_cd.x, -rate_limit, rate_limit);

            // Calculate rate limit to prevent change of rate through inverted
            rate_limit = fabsf(fabsf(rate_bf_request_cd.y)-fabsf(rate_bf_level_cd.y));
            rate_bf_request_cd.y += rate_bf_level_cd.y;
            rate_bf_request_cd.y = constrain_float(rate_bf_request_cd.y, -rate_limit, rate_limit);

            // Calculate rate limit to prevent change of rate through inverted
            rate_limit = fabsf(fabsf(rate_bf_request_cd.z)-fabsf(rate_bf_level_cd.z));
            rate_bf_request_cd.z += rate_bf_level_cd.z * g_config.acro_yaw_gain;
            rate_bf_request_cd.z = constrain_float(rate_bf_request_cd.z, -rate_limit, rate_limit);
        }
    }

    // hand back rate request
    roll_out = rate_bf_request_cd.x;
    pitch_out = rate_bf_request_cd.y;
    yaw_out = rate_bf_request_cd.z;
}
#endif
