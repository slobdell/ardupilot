---
alias_target: SERVO_BLH_PORT
default_value: 0
description: This sets the mavlink channel to use for blheli pass-thru. The channel
  number is determined by the number of serial ports configured to use mavlink. So
  0 is always the console, 1 is the next serial port using mavlink, 2 the next after
  that and so on.
display_name: Control port
group: OUT
investigation_status: alias
layout: parameter
name: OUT_BLH_PORT
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L125
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L77
units: null
visual_asset_id: null
---

# Control port

**Note:** This parameter configures instance BLH_PORT. It functions identically to [SERVO_BLH_PORT](../SERVO/SERVO_BLH_PORT.html).
