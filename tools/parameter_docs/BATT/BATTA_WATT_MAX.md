---
alias_target: BATT_WATT_MAX
default_value: 0
description: If battery wattage (voltage * current) exceeds this value then the system
  will reduce max throttle (THR_MAX, TKOFF_THR_MAX and THR_MIN for reverse thrust)
  to satisfy this limit. This helps limit high current to low C rated batteries regardless
  of battery voltage. The max throttle will slowly grow back to THR_MAX (or TKOFF_THR_MAX
  ) and THR_MIN if demanding the current max and under the watt max. Use 0 to disable.
display_name: Maximum allowed power (Watts)
group: BATT
investigation_status: alias
layout: parameter
name: BATTA_WATT_MAX
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L54
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L45
units: W
visual_asset_id: null
---

# Maximum allowed power (Watts)

**Note:** This parameter functions identically to [BATT_WATT_MAX](../BATT/BATT_WATT_MAX.html).
