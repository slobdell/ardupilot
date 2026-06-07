---
layout: parameter
name: RLL_RATE_D
display_name: Roll Rate D Gain
description: The derivative gain for the roll rate controller. Dampens the roll response to prevent overshoot.
default_value: 0.004
range: 0.001 0.03
units: 
group: RLL
visual_asset_id: pid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AP_RollController.cpp#L78
---

# Roll Rate D Gain (RLL_RATE_D)

## Description
`RLL_RATE_D` acts as a "Shock Absorber" for the roll axis.

When the plane rolls quickly to the target angle, it has momentum. `D` predicts that the error is closing fast and applies "Counter-Steer" to stop the roll smoothly without overshooting.

## Tuning & Behavior
*   **Default Value:** 0.004.
*   **Too High:** You will see rapid, jittery oscillations or hear the servos chattering.
*   **Too Low:** The plane will bounce or "Wag" when you stop a roll.