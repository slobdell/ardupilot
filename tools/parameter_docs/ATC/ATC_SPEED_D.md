---
layout: parameter
name: ATC_SPEED_D
display_name: Speed Control D Gain
description: The derivative gain for the rover speed controller. Dampens acceleration to prevent overshoot.
default_value: 0.0
range: 0.0 0.4
units: 
group: ATC
visual_asset_id: atc_speed_d_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L146
---

# Speed Control D Gain (ATC_SPEED_D)

## Description
`ATC_SPEED_D` stops the rover from overshooting its target speed.

## Tuning & Behavior
*   **Default Value:** 0.0.
*   **Recommendation:** Usually left at **0** for rovers. Friction provides enough natural damping.
