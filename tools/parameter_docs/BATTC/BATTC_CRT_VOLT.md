---
alias_target: BATT_CRT_VOLT
default_value: 0
description: Battery voltage that triggers a critical battery failsafe. Set to 0 to
  disable. If the battery voltage drops below this voltage continuously for more then
  the period specified by the @PREFIX@LOW_TIMER parameter then the vehicle will perform
  the failsafe specified by the @PREFIX@FS_CRT_ACT parameter.
display_name: Critical battery voltage
group: BATTC
investigation_status: alias
layout: parameter
name: BATTC_CRT_VOLT
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L102
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L39
units: V
visual_asset_id: null
---

# Critical battery voltage

**Note:** This parameter is functionally identical to [BATT_CRT_VOLT](../BATTC/BATT_CRT_VOLT.html).

Please refer to the documentation for the primary instance for detailed configuration instructions.
