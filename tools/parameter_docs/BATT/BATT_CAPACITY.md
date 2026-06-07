---
layout: parameter
name: BATT_CAPACITY
display_name: Battery capacity
description: Capacity of the battery in mAh when full.
default_value: 3300
range: 
units: mAh
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Battery capacity (BATT_CAPACITY)

## Description
Defines the total usable capacity of the battery pack. This is used to calculate the "Battery Remaining" percentage and trigger capacity-based failsafes.

## Tuning & Behavior
*   **Default Value:** 3300 mAh
*   **Set this to the value printed on your battery label, or slightly lower (e.g., 90%) for a safety margin.**