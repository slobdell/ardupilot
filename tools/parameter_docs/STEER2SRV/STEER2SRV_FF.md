---
layout: parameter
name: STEER2SRV_FF
display_name: Steering Feed-Forward
description: The feed-forward gain for the Rover steering controller. Provides immediate steering deflection based on the target turn rate.
default_value: 0
range: 0 5.0
units: 
group: STEER2SRV
visual_asset_id: rover_steering_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_SteerController.cpp#L103
---

# Steering Feed-Forward (STEER2SRV_FF)

## Description
`STEER2SRV_FF` is the "Guess" gain.

It tells the autopilot: "I know that to turn this fast, I need exactly this much steering angle." This provides the bulk of the steering command directly from the physics of the vehicle, leaving the P and I terms to only fix small errors.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Tune this first. Adjust until the Rover follows a circular path at the correct radius for the given speed.