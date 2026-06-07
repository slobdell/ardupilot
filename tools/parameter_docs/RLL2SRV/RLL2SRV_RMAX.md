---
layout: parameter
name: RLL2SRV_RMAX
display_name: Steering Max Rate
description: The maximum allowed rotation speed (in deg/s) for the steering actuator.
default_value: 0
range: 0 180
units: deg/s
group: RLL2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_SteerController.cpp#L43
---

# Steering Max Rate (RLL2SRV_RMAX)

## Description
`RLL2SRV_RMAX` limits how fast the steering servo or motor is allowed to move. 

*   **0:** Disabled (No limit).
*   **Value:** Degrees per second.