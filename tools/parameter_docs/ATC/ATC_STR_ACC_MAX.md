---
layout: parameter
name: ATC_STR_ACC_MAX
display_name: Steering Control Angular Acceleration Maximum
description: The maximum angular acceleration (in deg/s/s) the rover can use to change its turn rate.
default_value: 120
range: 0 1000
units: deg/s/s
group: ATC
visual_asset_id: atc_str_acc_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L191
---

# Steering Control Angular Acceleration Maximum (ATC_STR_ACC_MAX)

## Description
`ATC_STR_ACC_MAX` controls the "jerkiness" of the steering. It limits how fast the turn rate can change.

*   **Low Value:** The steering wheel turns slowly. The rover eases into turns.
*   **High Value:** The steering snaps to the desired angle.

## Tuning & Behavior
*   **Default Value:** 120 deg/s/s.
*   **Recommendation:**
    *   **Cars:** Set to 180-360 to ensure the servo moves fast enough to catch slides.
    *   **Large Tanks:** Set lower (e.g. 60) to prevent current spikes when reversing the motors for a pivot turn.