---
alias_target: SERVO_BLH_TEST
default_value: 0
description: Setting SERVO_BLH_TEST to a motor number enables an internal test of
  the BLHeli ESC protocol to the corresponding ESC. The debug output is displayed
  on the USB console.
display_name: BLHeli internal interface test
group: OUT
investigation_status: alias
layout: parameter
name: OUT_BLH_TEST
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L87
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L72
units: null
visual_asset_id: null
---

# BLHeli internal interface test

**Note:** This parameter configures instance BLH_TEST. It functions identically to [SERVO_BLH_TEST](../SERVO/SERVO_BLH_TEST.html).
