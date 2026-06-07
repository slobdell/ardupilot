---
layout: parameter
name: YAW2SRV_IMAX
display_name: Yaw Integrator Limit
description: The maximum authority (in centi-degrees of rudder travel) the integrator can apply.
default_value: 1500
range: 0 4500
units: cdeg
group: YAW2SRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/APM_Control/AP_YawController.cpp#L73
---

# Yaw Integrator Limit (YAW2SRV_IMAX)

## Description
`YAW2SRV_IMAX` prevents the "Integrator Windup" problem.

The integrator ([YAW2SRV_INT](YAW2SRV_INT.html)) slowly adds rudder trim to correct for persistent errors. However, if this value can grow too large, the rudder might get "stuck" over to one side for a long time even after the error is gone. This parameter sets a hard limit on how much the integrator can move the servo.

*   **1500 (Default):** Allows up to 15 degrees of rudder trim (approx 1/3 of total travel).

## Tuning & Behavior
*   **Recommendation:** Leave at **1500**. If your plane needs more than 15 degrees of constant rudder to fly straight, you have a major mechanical build issue.