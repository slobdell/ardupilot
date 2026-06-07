---
layout: parameter
name: BATT_CRT_VOLT
display_name: Critical battery voltage
description: Battery voltage that triggers a critical battery failsafe.
default_value: 0
range: 
units: V
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Critical battery voltage (BATT_CRT_VOLT)

## Description
The emergency voltage threshold for the "Battery Critical" failsafe. Triggers BATT_FS_CRT_ACT immediately when the voltage stays below this level for BATT_LOW_TIMER.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Typically set lower than BATT_LOW_VOLT (e.g., 3.3V/cell).**
