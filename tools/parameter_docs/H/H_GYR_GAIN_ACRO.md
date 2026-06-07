---
layout: parameter
name: H_GYR_GAIN_ACRO
display_name: ACRO External Gyro Gain
description: The PWM value sent to an external tail gyro specifically when in ACRO flight mode.
default_value: 0
range: 0 1000
units: PWM
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L64
---

# ACRO External Gyro Gain (H_GYR_GAIN_ACRO)

## Description
`H_GYR_GAIN_ACRO` allows you to have a separate tail gyro sensitivity for aerobatic flying.

In `ACRO` mode, pilots often want a more aggressive or direct response from the tail compared to stabilized modes. This parameter overrides the standard [H_GYR_GAIN](H_GYR_GAIN.html) when you switch to ACRO.

*   **0 (Default):** Use the standard `H_GYR_GAIN` for all modes.
*   **> 0:** Use this specific value when in ACRO mode.

## Tuning & Behavior
*   **Recommendation:** Only used if `H_TAIL_TYPE = 1` (External Gyro).
