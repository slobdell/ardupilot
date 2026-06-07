---
layout: parameter
name: BATT_VOLT_MULT
display_name: Voltage Multiplier
description: Used to convert the voltage of the voltage sensing pin to the actual battery's voltage (pin_voltage * VOLT_MULT).
default_value: 10.1
range: 
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.cpp
---

# Voltage Multiplier (BATT_VOLT_MULT)

## Description
Scaling factor for the voltage ADC reading. This value depends on the resistor divider ratio in your power module.