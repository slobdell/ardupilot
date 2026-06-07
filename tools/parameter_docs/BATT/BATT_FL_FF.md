---
layout: parameter
name: BATT_FL_FF
display_name: Fuel Level First Order Coefficient
description: First order coefficient for fuel level fitting.
default_value: 1.0
range: 
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_FuelLevel_Analog.cpp
---

# Fuel Level First Order Coefficient (BATT_FL_FF)

## Description
Part of a polynomial fit used to linearize non-linear fuel level sensors (e.g., irregularly shaped tanks).
