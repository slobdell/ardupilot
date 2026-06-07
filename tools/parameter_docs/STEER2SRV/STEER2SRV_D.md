---
layout: parameter
name: STEER2SRV_D
display_name: Steering D Gain
description: The derivative gain for the Rover steering controller. Dampens the steering response to prevent overshoot.
default_value: 0.005
range: 0 0.1
units: 
group: STEER2SRV
visual_asset_id: rover_steering_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_SteerController.cpp#L102
---

# Steering D Gain (STEER2SRV_D)

## Description
`STEER2SRV_D` stops the Rover from "Wagging its tail."

As the Rover reaches its target heading, it has momentum. `D` predicts that the error is closing and applies counter-steering to stop the turn smoothly.