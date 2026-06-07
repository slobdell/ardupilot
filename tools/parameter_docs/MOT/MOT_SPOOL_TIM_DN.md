---
layout: parameter
name: MOT_SPOOL_TIM_DN
display_name: Motor Spool-Down Time
description: The time (in seconds) the motors take to ramp down from minimum throttle to zero.
default_value: 0
range: 0 2.0
units: s
group: MOT
visual_asset_id: mot_spool_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L232
---

# Motor Spool-Down Time (MOT_SPOOL_TIM_DN)

## Description
`MOT_SPOOL_TIM_DN` defines the duration of the motor ramp-down when the drone lands or is disarmed.

*   **0 (Default):** Uses the same value as [MOT_SPOOL_TIME](MOT_SPOOL_TIME.html).
*   **Non-Zero:** Sets a specific time for the ramp-down.

## Tuning & Behavior
*   **Recommendation:** Keep at **0** to match the spool-up time.
*   **Safety:** This ensures the motors don't stop instantly, which can be useful to prevent large props from unscrewing themselves due to sudden deceleration (on some older hardware) or simply to provide a more predictable disarm feel.