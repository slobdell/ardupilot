---
layout: parameter
name: STR_ACC_MAX
display_name: Steering control angular acceleration maximum
description: Steering control angular acceleration maximum (in deg/s/s).  0 to disable acceleration limiting
default_value: 120
range: 0 1000
units: deg/s/s
group: STR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L312
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.h#L156
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Steering control angular acceleration maximum (STR_ACC_MAX)

## Description
This parameter limits the angular acceleration (rotational jerk) of the steering control loop. It essentially smoothens the steering response by preventing the vehicle from trying to change its turn rate too instantly.

This is particularly useful for preventing "twitchy" behavior or mechanical stress on steering servos/linkages during aggressive maneuvers.

## The Mathematics
The controller limits the *rate of change* of the desired turn rate.

$$ |\Delta \text{Rate}| \le \text{ACC\_MAX} \times dt $$

If the desired change in turn rate exceeds this limit, the requested rate is clamped to the maximum allowable step for that time step.

## The Engineer's View
In `AR_AttitudeControl::get_steering_out_rate`, `_steer_accel_max` is used to calculate `change_max`.
The current `_desired_turn_rate` is constrained to be within `+/- change_max` of the previous time step's rate.
This acts as a slew rate limiter on the target yaw rate.

## Tuning & Behavior
*   **Default Value:** 120 deg/s/s (Rover default, may vary by frame).
*   **Range:** 0 to 1000.
*   **0:** Disabled (Unlimited acceleration).
*   **Lower Value:** Smoother, lazier steering starts.
*   **Higher Value:** Snappier response, potentially causing overshoot or mechanical strain.
*   **Dependency:** This works in conjunction with `STR_RAT_MAX` (which limits the *speed* of the turn) and `STR_ANG_P` (which determines the *aggressiveness* of the correction).

