---
layout: parameter
name: BATT_FS_CRT_ACT
display_name: Critical battery failsafe action
description: What action the vehicle should perform if it hits a critical battery failsafe.
default_value: 0
range: 0 7
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Critical battery failsafe action (BATT_FS_CRT_ACT)

## Description
Specifies the flight behavior when the battery reaches the "Critical" threshold.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Common Values:** 1:RTL, 2:Land, 5:Terminate
*   **Usually set to "Land" to force an immediate landing to save the battery and airframe.**
