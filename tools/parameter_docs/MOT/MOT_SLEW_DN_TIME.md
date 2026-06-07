---
layout: parameter
name: MOT_SLEW_DN_TIME
display_name: Output slew time for decreasing throttle
description: The time (in seconds) it takes to ramp the motor output from 100% to 0% throttle.
default_value: 0
range: 0 0.5
units: s
group: MOT
visual_asset_id: mot_slew_time_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L138
---

# Output slew time for decreasing throttle (MOT_SLEW_DN_TIME)

## Description
`MOT_SLEW_DN_TIME` accounts for the "spool down" time of large props.

Active Braking (Damped Light) helps motors slow down fast, but large props still have momentum. This parameter prevents the PID loops from under-shooting when reducing throttle.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Usually same as `MOT_SLEW_UP_TIME`.