---
layout: parameter
name: BATT_SHUNT
display_name: Shunt resistance
description: Resistance of the shunt resistor in Ohms.
default_value: 0.0005
range: 
units: Ohm
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_INA2xx.cpp
---

# Shunt resistance (BATT_SHUNT)

## Description
The resistance value of the physical shunt resistor used for current measurement. Critical for accurate amperage reporting on certain sensor types.
