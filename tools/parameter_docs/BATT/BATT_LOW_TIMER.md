---
layout: parameter
name: BATT_LOW_TIMER
display_name: Low voltage timeout
description: This is the timeout in seconds before a low voltage event will be triggered.
default_value: 10
range: 0 120
units: s
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Low voltage timeout (BATT_LOW_TIMER)

## Description
Defines how long the battery voltage must remain below the BATT_LOW_VOLT threshold before a failsafe is triggered. This prevents false triggers caused by brief voltage sags during high-throttle maneuvers.

## Tuning & Behavior
*   **Default Value:** 10 s
*   **Range:** 0 to 120 s
