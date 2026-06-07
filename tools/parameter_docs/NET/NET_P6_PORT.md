---
alias_target: NET_P1_PORT
default_value: 0
description: This sets the mavlink channel to use for blheli pass-thru. The channel
  number is determined by the number of serial ports configured to use mavlink. So
  0 is always the console, 1 is the next serial port using mavlink, 2 the next after
  that and so on.
display_name: Control port
group: NET
investigation_status: alias
layout: parameter
name: NET_P6_PORT
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.cpp#L125
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BLHeli/AP_BLHeli.h#L77
units: null
visual_asset_id: null
---

# Control port

**Note:** This parameter functions identically to [NET_P1_PORT](../NET/NET_P1_PORT.html).
