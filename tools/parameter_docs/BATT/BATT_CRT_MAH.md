---
layout: parameter
name: BATT_CRT_MAH
display_name: Battery critical capacity
description: Battery capacity at which the critical battery failsafe is triggered.
default_value: 0
range: 
units: mAh
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Battery critical capacity (BATT_CRT_MAH)

## Description
The emergency capacity threshold for the "Battery Critical" failsafe. Triggers BATT_FS_CRT_ACT when the remaining mAh drops below this value.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Typically set to 10% of the total BATT_CAPACITY.**
