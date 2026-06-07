---
alias_target: BATT_FL_V_MULT
default_value: 0.5
description: 'Voltage multiplier to determine what the full tank voltage reading is.
  This is calculated as 1 / (Voltage_Full - Voltage_Empty) Note: For this type of
  battery monitor, the voltage seen by the analog pin is displayed as battery voltage
  on a GCS.'
display_name: Fuel level voltage multiplier
group: BATTB
investigation_status: alias
layout: parameter
name: BATTB_FL_V_MULT
range: 0.01 10
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_FuelLevel_Analog.cpp#L44
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_FuelLevel_Analog.h#L51
units: null
visual_asset_id: null
---

# Fuel level voltage multiplier

**Note:** This parameter configures instance B. It functions identically to [BATT_FL_V_MULT](../BATT/BATT_FL_V_MULT.html).
