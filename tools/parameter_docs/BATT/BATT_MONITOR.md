---
layout: parameter
name: BATT_MONITOR
display_name: Battery monitoring
description: Controls enabling monitoring of the battery's voltage and current.
default_value: 0
range: 
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Battery monitoring (BATT_MONITOR)

## Description
Enables the battery monitoring system and selects the sensor type (Analog, SMBus, DroneCAN, etc.).

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Common Values:** 3:Analog Voltage Only, 4:Analog Voltage and Current, 8:DroneCAN, 9:ESC
*   **Requires reboot after changing to initialize the specific driver.**