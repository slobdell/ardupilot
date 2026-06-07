---
layout: parameter
name: BATT_WATT_MAX
display_name: Maximum allowed power (Watts)
description: If battery wattage (voltage * current) exceeds this value then the system will reduce max throttle to satisfy this limit (Plane).
default_value: 0
range: 
units: W
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Maximum allowed power (BATT_WATT_MAX)

## Description
A power-limiting safety feature for ArduPlane. If the instantaneous power consumption exceeds this threshold, the flight controller will automatically cap the maximum throttle to protect the battery and ESCs.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Prevents over-discharging low-C rated batteries or overheating the powertrain.**
