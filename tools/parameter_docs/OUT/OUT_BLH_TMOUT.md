---
alias_target: SERVO_BLH_TMOUT
default_value: 0
description: This sets the inactivity timeout for the BLHeli protocol in seconds.
  If no packets are received in this time normal MAVLink operations are resumed. A
  value of 0 means no timeout
display_name: BLHeli protocol timeout
group: OUT
investigation_status: alias
layout: parameter
name: OUT_BLH_TMOUT
range: 0 300
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L95
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L73
units: s
visual_asset_id: null
---

# BLHeli protocol timeout

**Note:** This parameter configures instance BLH_TMOUT. It functions identically to [SERVO_BLH_TMOUT](../SERVO/SERVO_BLH_TMOUT.html).
