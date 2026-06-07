---
layout: parameter
name: STEER2SRV_P
display_name: Steering P Gain
description: The proportional gain for the Rover steering controller. Converts heading error into steering deflection.
default_value: 1.8
range: 0.1 5.0
units: 
group: STEER2SRV
visual_asset_id: rover_steering_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_SteerController.cpp#L100
---

# Steering P Gain (STEER2SRV_P)

## Description
`STEER2SRV_P` controls how aggressively a Rover turns to fix a heading error.

When the Rover is not pointed exactly at its target waypoint, the P-gain determines how much "Steering Angle" is applied immediately.

*   **Too High:** The Rover will "Snake" or weave back and forth down the path.
*   **Too Low:** The Rover will take a very long time to turn and may miss its waypoint.