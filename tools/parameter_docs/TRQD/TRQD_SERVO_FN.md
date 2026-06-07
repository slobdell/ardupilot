---
layout: parameter
name: TRQD_SERVO_FN
display_name: Torqeedo Servo Function
description: The servo output function ID used to drive the Torqeedo motor.
default_value: 0
range: 0 100
units: 
group: TRQD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L70
---

# Torqeedo Servo Function (TRQD_SERVO_FN)

## Description
`TRQD_SERVO_FN` maps the Torqeedo driver to a specific motor output channel logic.

*   **73:** Throttle Left.
*   **74:** Throttle Right.
*   **0:** Disabled.