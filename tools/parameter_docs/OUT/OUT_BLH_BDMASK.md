---
alias_target: SERVO_BLH_BDMASK
default_value: 0
description: Mask of channels which support bi-directional dshot telemetry. This is
  used for ESCs which have firmware that supports bi-directional dshot allowing fast
  rpm telemetry values to be returned for the harmonic notch.
display_name: BLHeli bitmask of bi-directional dshot channels
group: OUT
investigation_status: alias
layout: parameter
name: OUT_BLH_BDMASK
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L150
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L53
units: ''
visual_asset_id: null
---

# BLHeli bitmask of bi-directional dshot channels

**Note:** This parameter configures instance BLH_BDMASK. It functions identically to [SERVO_BLH_BDMASK](../SERVO/SERVO_BLH_BDMASK.html).
