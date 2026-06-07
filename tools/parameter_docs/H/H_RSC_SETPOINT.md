---
layout: parameter
name: H_RSC_SETPOINT
display_name: External Motor Governor Setpoint
description: Throttle output in percent to the external motor governor when motor interlock is enabled.
default_value: 70
range: 0 100
units: %
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_RSC.cpp
---

# External Motor Governor Setpoint (H_RSC_SETPOINT)

## Description
Defines the target throttle percentage sent to an external Electronic Speed Controller (ESC) or governor. This value is used when the pilot enables the "Motor Interlock" (throttle hold off).
*   **Typical values range from 60% to 80% depending on the desired head speed.**
