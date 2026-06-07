---
alias_target: BATT_LOW_VOLT
default_value: DEFAULT_LOW_BATTERY_VOLTAGE
description: Battery voltage that triggers a low battery failsafe. Set to 0 to disable.
  If the battery voltage drops below this voltage continuously for more then the period
  specified by the @PREFIX@LOW_TIMER parameter then the vehicle will perform the failsafe
  specified by the @PREFIX@FS_LOW_ACT parameter.
display_name: Low battery voltage
group: BATTB
investigation_status: alias
layout: parameter
name: BATTB_LOW_VOLT
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L86
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L37
units: V
visual_asset_id: null
---

# Low battery voltage

**Note:** This parameter is functionally identical to [BATT_LOW_VOLT](../BATTB/BATT_LOW_VOLT.html).

Please refer to the documentation for the primary instance for detailed configuration instructions.
