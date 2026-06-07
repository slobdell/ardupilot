---
layout: parameter
name: STR_RAT_MAX
display_name: Steering control rotation rate maximum
description: Steering control rotation rate maximum in deg/s.  0 to remove rate limiting
default_value: 120
range: 0 1000
units: deg/s
group: STR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L321
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.h#L157
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Steering control rotation rate maximum (STR_RAT_MAX)

## Description
This parameter sets the hard limit on how fast the vehicle is allowed to turn (yaw) in degrees per second. Ideally, this should match the physical capability of the vehicle to turn without sliding or rolling over.

This acts as a "speed limit" for the steering controller. Even if the navigation system demands a sharp turn, the controller will not request a turn rate higher than this value.

## The Mathematics
The controller clamps the desired turn rate.

$$ |\text{Rate}_{cmd}| \le STR\_RAT\_MAX $$

If `STR_RAT_MAX` is 0, this check is skipped.

## The Engineer's View
In `AR_AttitudeControl::get_steering_out_rate`:
1.  The code converts `_steer_rate_max` to radians.
2.  It checks if `_desired_turn_rate` exceeds this limit.
3.  If it does, it clamps the value and sets the `_steering_limit_left` or `_steering_limit_right` flags, which tells higher-level navigators (like the L1 controller) that the steering is saturated.

## Tuning & Behavior
*   **Default Value:** 120 deg/s
*   **Range:** 0 to 1000 deg/s
*   **Effect of Decreasing:** Makes the vehicle turn slower. Useful for preventing rollovers on high-CG rovers.
*   **Effect of Increasing:** Allows faster turns.
*   **0:** Disabled. The vehicle will try to turn as fast as the steering geometry and P-gain allow.

