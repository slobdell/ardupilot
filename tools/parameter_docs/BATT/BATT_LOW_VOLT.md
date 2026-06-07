---
layout: parameter
name: BATT_LOW_VOLT
display_name: Low battery voltage
description: Battery voltage that triggers a low battery failsafe.
default_value: 10.5
range: 
units: V
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Low battery voltage (BATT_LOW_VOLT)

## Description
The primary voltage threshold for the "Battery Low" failsafe. When the voltage stays below this value for BATT_LOW_TIMER, the action defined in BATT_FS_LOW_ACT is taken.

## Tuning & Behavior
*   **Default Value:** 10.5 V (Copter), 0.0 V (Plane)
*   **For 3S LiPo, 10.5V (3.5V/cell) is a common safe threshold.**