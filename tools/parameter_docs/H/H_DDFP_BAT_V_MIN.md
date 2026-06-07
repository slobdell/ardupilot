---
layout: parameter
name: H_DDFP_BAT_V_MIN
display_name: DDVP Battery Voltage Min
description: The battery voltage at which maximum boost is applied to the tail motor.
default_value: 0
range: 0 100
units: V
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L100
---

# DDVP Battery Voltage Min (H_DDFP_BAT_V_MIN)

## Description
`H_DDFP_BAT_V_MIN` sets the "Empty" reference.

As the battery drops to this level, the mixer boosts the PWM signal to the ESC to compensate for the lower voltage, keeping the RPM consistent.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to 3.3V * Cell Count.