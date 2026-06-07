---
layout: parameter
name: ATC_STOP_SPEED
display_name: Speed Control Stop Speed
description: The speed (in m/s) below which the rover is considered stopped.
default_value: 0.1
range: 0 0.5
units: m/s
group: ATC
visual_asset_id: atc_stop_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L273
---

# Speed Control Stop Speed (ATC_STOP_SPEED)

## Description
`ATC_STOP_SPEED` is the "Zero Threshold."

When the rover slows down, at some point the autopilot has to decide "Okay, we are stopped now" and cut the throttle completely.

## Tuning & Behavior
*   **Default Value:** 0.1 m/s.
*   **Recommendation:** If the rover creeps or jitters at a standstill, increase this to **0.2**.