---
alias_target: BATT_VOLT_MULT
default_value: 0
description: Used to convert the voltage of the voltage sensing pin (@PREFIX@VOLT_PIN)
  to the actual battery's voltage (pin_voltage * VOLT_MULT).
display_name: Voltage Multiplier
group: BATTD
investigation_status: alias
layout: parameter
name: BATTD_VOLT_MULT
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_AD7091R5.cpp#L64
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_AD7091R5.h#L67
units: null
visual_asset_id: null
---

# Voltage Multiplier

**Note:** This parameter is functionally identical to [BATT_VOLT_MULT](../BATTD/BATT_VOLT_MULT.html).

Please refer to the documentation for the primary instance for detailed configuration instructions.
