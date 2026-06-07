---
layout: parameter
name: BATT_FS_LOW_ACT
display_name: Low battery failsafe action
description: What action the vehicle should perform if it hits a low battery failsafe.
default_value: 0
range: 0 7
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Low battery failsafe action (BATT_FS_LOW_ACT)

## Description
Specifies the flight behavior when the battery reaches the "Low" threshold.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Common Values:** 1:RTL, 2:Land, 3:SmartRTL
*   **Ensure your chosen action is appropriate for your flying environment.**