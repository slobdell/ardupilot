---
layout: parameter
name: BATT_MAX_AMPS
display_name: Maximum current
description: Maximum current that the battery monitor can measure.
default_value: 90
range: 
units: A
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_INA2xx.cpp
---

# Maximum current (BATT_MAX_AMPS)

## Description
The hardware measurement limit for the current sensor (e.g., for INA2xx or similar sensors).