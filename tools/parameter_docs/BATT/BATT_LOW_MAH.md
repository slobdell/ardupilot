---
layout: parameter
name: BATT_LOW_MAH
display_name: Low battery capacity
description: Battery capacity at which the low battery failsafe is triggered.
default_value: 0
range: 
units: mAh
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Low battery capacity (BATT_LOW_MAH)

## Description
The primary capacity threshold for the "Battery Low" failsafe. Triggers BATT_FS_LOW_ACT when the remaining mAh drops below this value.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Typically set to 20% of the total BATT_CAPACITY.**
