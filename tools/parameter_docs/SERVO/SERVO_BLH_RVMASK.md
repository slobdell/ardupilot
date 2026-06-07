---
alias_target: OUT_BLH_RVMASK
default_value: 0
description: Mask of channels which are reversed. This is used to configure ESCs to
  reverse motor direction for unidirectional rotation. Do not use for channels selected
  with SERVO_BLH_3DMASK.
display_name: BLHeli bitmask of reversed channels
group: SERVO
investigation_status: alias
layout: parameter
name: SERVO_BLH_RVMASK
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L158
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L70
units: null
visual_asset_id: null
---

# BLHeli bitmask of reversed channels

**Legacy Note:** `SERVO_*` parameters have been renamed to `OUT_*` in newer firmware versions. This parameter functions identically to [OUT_BLH_RVMASK](../OUT/OUT_BLH_RVMASK.html).
