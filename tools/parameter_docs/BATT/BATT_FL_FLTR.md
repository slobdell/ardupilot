---
layout: parameter
name: BATT_FL_FLTR
display_name: Fuel Level Filter Frequency
description: Filter frequency for fuel level sensor.
default_value: 0.3
range: 
units: Hz
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_FuelLevel_Analog.cpp
---

# Fuel Level Filter Frequency (BATT_FL_FLTR)

## Description
Low-pass filter frequency for smoothing fuel level readings, preventing spikes caused by sloshing.
