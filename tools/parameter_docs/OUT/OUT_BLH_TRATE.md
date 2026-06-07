---
alias_target: SERVO_BLH_TRATE
default_value: 10
description: This sets the rate in Hz for requesting telemetry from ESCs. It is the
  rate per ESC. Setting to zero disables telemetry requests
display_name: BLHeli telemetry rate
group: OUT
investigation_status: alias
layout: parameter
name: OUT_BLH_TRATE
range: 0 500
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L103
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L58
units: Hz
visual_asset_id: null
---

# BLHeli telemetry rate

**Note:** This parameter configures instance BLH_TRATE. It functions identically to [SERVO_BLH_TRATE](../SERVO/SERVO_BLH_TRATE.html).
