---
layout: parameter
name: H_DDFP_SPIN_MIN
display_name: DDFP Tail Motor Spin Minimum
description: The minimum thrust ratio for a direct-drive fixed-pitch (DDFP) tail motor.
default_value: 0.15
range: 0 0.3
units: 
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L112
---

# DDFP Tail Motor Spin Minimum (H_DDFP_SPIN_MIN)

## Description
`H_DDFP_SPIN_MIN` sets the lower limit for a fixed-pitch tail motor.

If you are using a standard drone motor for your tail, this is the point where it produces reliable thrust. Setting this correctly ensures the tail doesn't "Stall" or stop spinning during low-torque maneuvers.
