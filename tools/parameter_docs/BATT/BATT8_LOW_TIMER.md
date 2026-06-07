---
alias_target: BATT_LOW_TIMER
default_value: 10
description: This is the timeout in seconds before a low voltage event will be triggered.
  For aircraft with low C batteries it may be necessary to raise this in order to
  cope with low voltage on long takeoffs. A value of zero disables low voltage errors.
display_name: Low voltage timeout
group: BATT
investigation_status: alias
layout: parameter
name: BATT8_LOW_TIMER
range: 0 120
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L71
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L48
units: s
visual_asset_id: null
---

# Low voltage timeout

**Note:** This parameter functions identically to [BATT_LOW_TIMER](../BATT/BATT_LOW_TIMER.html).
