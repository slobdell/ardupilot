---
alias_target: BATT_MAX_AMPS
default_value: HAL_BATTMON_INA239_MAX_CURRENT
description: This controls the maximum current the INA239 sensor will work with.
display_name: Battery monitor max current
group: BATTF
investigation_status: alias
layout: parameter
name: BATTF_MAX_AMPS
range: 1 400
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_INA239.cpp#L41
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_INA239.h#L50
units: A
visual_asset_id: null
---

# Battery monitor max current

**Note:** This parameter configures Battery Monitor F. It functions identically to [BATT_MAX_AMPS](../BATT/BATT_MAX_AMPS.html).
