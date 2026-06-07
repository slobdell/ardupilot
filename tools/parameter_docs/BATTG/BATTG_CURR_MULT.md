---
alias_target: BATT_CURR_MULT
default_value: 1.0
description: Multiplier applied to all current related reports to allow for adjustment
  if no UAVCAN param access or current splitting applications
display_name: Scales reported power monitor current
group: BATTG
investigation_status: alias
layout: parameter
name: BATTG_CURR_MULT
range: .1 10
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_DroneCAN.cpp#L27
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_DroneCAN.h#L103
units: null
visual_asset_id: null
---

# Scales reported power monitor current

**Note:** This parameter configures instance G. It functions identically to [BATT_CURR_MULT](../BATT/BATT_CURR_MULT.html).
