---
layout: parameter
name: H_DDFP_THST_EXPO
display_name: DDVP Tail Thrust Expo
description: The thrust curve exponent for the direct-drive tail motor.
default_value: 0
range: 0 1
units: 
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L100
---

# DDVP Tail Thrust Expo (H_DDFP_THST_EXPO)

## Description
`H_DDFP_THST_EXPO` linearizes the thrust of the tail motor.

Propeller thrust is roughly proportional to `RPM^2`. This parameter applies the inverse curve so that a 50% yaw command results in 50% thrust, not 25%.

## Tuning & Behavior
*   **0.65:** Typical for 5-inch props.
*   **0:** Linear output (bad for thrust).