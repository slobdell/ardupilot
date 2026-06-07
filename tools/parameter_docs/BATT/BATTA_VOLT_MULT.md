---
alias_target: BATT_VOLT_MULT
default_value: AP_BATT_VOLTDIVIDER_DEFAULT
description: Used to convert the voltage of the voltage sensing pin (@PREFIX@VOLT_PIN)
  to the actual battery's voltage (pin_voltage * VOLT_MULT). For the 3DR Power brick
  with a Pixhawk, this should be set to 10.1. For the Pixhawk with the 3DR 4in1 ESC
  this should be 12.02. For the PX using the PX4IO power supply this should be set
  to 1.
display_name: Voltage Multiplier
group: BATT
investigation_status: alias
layout: parameter
name: BATTA_VOLT_MULT
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.cpp#L35
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.h#L125
units: ''
visual_asset_id: null
---

# Voltage Multiplier

**Note:** This parameter functions identically to [BATT_VOLT_MULT](../BATT/BATT_VOLT_MULT.html).
