---
layout: parameter
name: ACT_VOLT_MULT
display_name: Voltage Multiplier
description: Used to convert the voltage of the voltage sensing pin (ACT_VOLT_PIN) to the actual battery's voltage (pin_voltage * VOLT_MULT).
default_value: 0
range: 
units: 
group: ACT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_AD7091R5.cpp
---

# Voltage Multiplier (ACT_VOLT_MULT)

## Description
Used to convert the voltage of the voltage sensing pin (ACT_VOLT_PIN) to the actual battery's voltage (pin_voltage * VOLT_MULT).

## Tuning & Behavior
*   **Default Value:** 0
