---
alias_target: BATT_CRT_MAH
default_value: 0
description: Battery capacity at which the critical battery failsafe is triggered.
  Set to 0 to disable battery remaining failsafe. If the battery capacity drops below
  this level the vehicle will perform the failsafe specified by the @PREFIX@FS_CRT_ACT
  parameter.
display_name: Battery critical capacity
group: BATT
investigation_status: alias
layout: parameter
name: BATTD_CRT_MAH
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L110
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L40
units: mAh
visual_asset_id: null
---

# Battery critical capacity

**Note:** This parameter functions identically to [BATT_CRT_MAH](../BATT/BATT_CRT_MAH.html).
