---
alias_target: OUT_BLH_3DMASK
default_value: 0
description: Mask of channels which are dynamically reversible. This is used to configure
  ESCs in '3D' mode, allowing for the motor to spin in either direction. Do not use
  for channels selected with SERVO_BLH_RVMASK.
display_name: BLHeli bitmask of 3D channels
group: SERVO
investigation_status: alias
layout: parameter
name: SERVO_BLH_3DMASK
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L141
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L69
units: null
visual_asset_id: null
---

# BLHeli bitmask of 3D channels

**Legacy Note:** `SERVO_*` parameters have been renamed to `OUT_*` in newer firmware versions. This parameter functions identically to [OUT_BLH_3DMASK](../OUT/OUT_BLH_3DMASK.html).
