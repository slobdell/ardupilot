---
layout: parameter
name: BATT_ESC_INDEX
display_name: ESC Telemetry Index
description: ESC Telemetry Index to write voltage, current, consumption and temperature data to. Use 0 to disable.
default_value: 0
range: 0 10
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# ESC Telemetry Index (BATT_ESC_INDEX)

## Description
Links the battery monitor instance to a specific ESC telemetry channel. This allows the FC to log battery data alongside individual ESC metrics.
