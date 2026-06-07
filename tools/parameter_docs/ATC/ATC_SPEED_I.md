---
layout: parameter
name: ATC_SPEED_I
display_name: Speed Control I Gain
description: The integral gain for the rover speed controller. Corrects for long-term speed errors (e.g. driving uphill).
default_value: 0.2
range: 0.0 2.0
units: 
group: ATC
visual_asset_id: atc_speed_i_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/APM_Control/AR_AttitudeControl.cpp#L132
---

# Speed Control I Gain (ATC_SPEED_I)

## Description
`ATC_SPEED_I` is the "Cruise Control."

If `ATC_SPEED_P` isn't enough to hold the speed (e.g., going up a steep hill), the I-term slowly increases the throttle until the error is gone.

## Tuning & Behavior
*   **Default Value:** 0.20.
*   **Recommendation:** Set equal to `ATC_SPEED_P`.
