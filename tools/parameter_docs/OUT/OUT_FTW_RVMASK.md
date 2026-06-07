---
alias_target: SERVO_FTW_RVMASK
default_value: 0
description: Mask of channels which are reversed. This is used to configure ESCs to
  reverse motor direction for unidirectional rotation. Do not use for channels selected
  with SERVO_BLH_3DMASK.
display_name: BLHeli bitmask of reversed channels
group: OUT
investigation_status: alias
layout: parameter
name: OUT_FTW_RVMASK
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L158
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L70
units: null
visual_asset_id: null
---

# BLHeli bitmask of reversed channels

**Note:** This parameter configures instance FTW_RVMASK. It functions identically to [SERVO_FTW_RVMASK](../SERVO/SERVO_FTW_RVMASK.html).
