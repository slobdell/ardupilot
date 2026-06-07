---
alias_target: BATT_SHUNT
default_value: HAL_BATTMON_INA239_SHUNT_RESISTANCE
description: This sets the shunt resistor used in the device
display_name: Battery monitor shunt resistor
group: BATTG
investigation_status: alias
layout: parameter
name: BATTG_SHUNT
range: 0.0001 0.01
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_INA239.cpp#L49
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_INA239.h#L51
units: Ohm
visual_asset_id: null
---

# Battery monitor shunt resistor

**Note:** This parameter configures Battery Monitor G. It functions identically to [BATT_SHUNT](../BATT/BATT_SHUNT.html).
