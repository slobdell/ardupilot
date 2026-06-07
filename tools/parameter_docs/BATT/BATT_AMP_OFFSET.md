---
layout: parameter
name: BATT_AMP_OFFSET
display_name: AMP offset
description: Voltage offset at zero current on current sensor.
default_value: 0
range: 
units: V
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.cpp
---

# AMP offset (BATT_AMP_OFFSET)

## Description
The voltage reported by the current sensor when zero current is flowing. This value is subtracted from the reading before scaling to ensure accuracy at low loads.
