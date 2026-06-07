---
alias_target: BATT_CRT_MAH
default_value: 0
description: Battery capacity at which the critical battery failsafe is triggered.
  Set to 0 to disable battery remaining failsafe. If the battery capacity drops below
  this level the vehicle will perform the failsafe specified by the @PREFIX@FS_CRT_ACT
  parameter.
display_name: Battery critical capacity
group: BATTC
investigation_status: alias
layout: parameter
name: BATTC_CRT_MAH
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L110
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L40
units: mAh
visual_asset_id: null
---

# Battery critical capacity

**Note:** This parameter is functionally identical to [BATT_CRT_MAH](../BATTC/BATT_CRT_MAH.html).

Please refer to the documentation for the primary instance for detailed configuration instructions.
