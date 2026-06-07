---
layout: parameter
name: BATT_FS_VOLTSRC
display_name: Failsafe voltage source
description: Voltage type used for detection of low voltage event.
default_value: 0
range: 0 1
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Failsafe voltage source (BATT_FS_VOLTSRC)

## Description
Selects whether the failsafe logic uses the "Raw" measured voltage or the "Sag Compensated" voltage (which accounts for voltage drops under load).

## Tuning & Behavior
*   **Default Value:** 0 (Raw Voltage)
*   **Values:** 0:Raw Voltage, 1:Sag Compensated Voltage
