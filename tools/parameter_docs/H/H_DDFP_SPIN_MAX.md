---
layout: parameter
name: H_DDFP_SPIN_MAX
display_name: DDFP Tail Motor Spin Maximum
description: The maximum thrust ratio for a direct-drive fixed-pitch (DDFP) tail motor.
default_value: 0.95
range: 0.8 1.0
units: 
group: H
visual_asset_id: heli_tail_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsHeli_Single.cpp#L112
---

# DDFP Tail Motor Spin Maximum (H_DDFP_SPIN_MAX)

## Description
`H_DDFP_SPIN_MAX` defines the saturation point for the tail motor.
