---
alias_target: BATT_LOW_MAH
default_value: 0
description: Battery capacity at which the low battery failsafe is triggered. Set
  to 0 to disable battery remaining failsafe. If the battery capacity drops below
  this level the vehicle will perform the failsafe specified by the @PREFIX@FS_LOW_ACT
  parameter.
display_name: Low battery capacity
group: BATTD
investigation_status: alias
layout: parameter
name: BATTD_LOW_MAH
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L94
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L38
units: mAh
visual_asset_id: null
---

# Low battery capacity

**Note:** This parameter is functionally identical to [BATT_LOW_MAH](../BATTD/BATT_LOW_MAH.html).

Please refer to the documentation for the primary instance for detailed configuration instructions.
