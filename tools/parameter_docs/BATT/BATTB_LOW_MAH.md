---
alias_target: BATT_LOW_MAH
default_value: 0
description: Battery capacity at which the low battery failsafe is triggered. Set
  to 0 to disable battery remaining failsafe. If the battery capacity drops below
  this level the vehicle will perform the failsafe specified by the @PREFIX@FS_LOW_ACT
  parameter.
display_name: Low battery capacity
group: BATT
investigation_status: alias
layout: parameter
name: BATTB_LOW_MAH
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L94
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L38
units: mAh
visual_asset_id: null
---

# Low battery capacity

**Note:** This parameter functions identically to [BATT_LOW_MAH](../BATT/BATT_LOW_MAH.html).
