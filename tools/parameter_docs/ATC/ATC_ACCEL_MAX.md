---
layout: parameter
name: ATC_ACCEL_MAX
display_name: Speed Control Acceleration Max
description: The maximum acceleration (in m/s/s) the rover will attempt to achieve.
default_value: 1.0
range: 0 10
units: m/s/s
group: ATC
visual_asset_id: atc_accel_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L257
---

# Speed Control Acceleration Max (ATC_ACCEL_MAX)

## Description
`ATC_ACCEL_MAX` is the "Launch Control."

It limits how fast the rover tries to speed up. 

*   **Low Value (e.g. 0.5):** Slow, smooth starts. No wheelspin.
*   **High Value (e.g. 5.0):** Drag race mode.

## Tuning & Behavior
*   **Default Value:** 1.0 m/s/s.
*   **Recommendation:** Set slightly lower than the physical limit of your traction to prevent wheelspin.