---
layout: parameter
name: ATC_DECEL_MAX
display_name: Speed Control Deceleration Max
description: The maximum deceleration (in m/s/s) the rover will use to stop.
default_value: 0
range: 0 10
units: m/s/s
group: ATC
visual_asset_id: atc_accel_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L297
---

# Speed Control Deceleration Max (ATC_DECEL_MAX)

## Description
`ATC_DECEL_MAX` is the "ABS" setting.

It limits how hard the rover brakes.

*   **0 (Default):** Use the same value as `ATC_ACCEL_MAX`.
*   **Value:** Override braking limit.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Rovers usually brake faster than they accelerate. Set this higher than `ATC_ACCEL_MAX` (e.g. 2.0).