---
alias_target: BATT_SERIAL_NUM
default_value: AP_BATT_SERIAL_NUMBER_DEFAULT
description: Battery serial number, automatically filled in for SMBus batteries, otherwise
  will be -1. With DroneCan it is the battery_id.
display_name: Battery serial number
group: BATT
investigation_status: alias
layout: parameter
name: BATT8_SERIAL_NUM
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp#L61
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.h#L36
units: ''
visual_asset_id: null
---

# Battery serial number

**Note:** This parameter functions identically to [BATT_SERIAL_NUM](../BATT/BATT_SERIAL_NUM.html).
