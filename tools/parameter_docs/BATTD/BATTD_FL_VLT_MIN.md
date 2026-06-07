---
alias_target: BATT_FL_VLT_MIN
default_value: 0.5
description: 'The voltage seen on the analog pin when the fuel tank is empty. Note:
  For this type of battery monitor, the voltage seen by the analog pin is displayed
  as battery voltage on a GCS.'
display_name: Empty fuel level voltage
group: BATTD
investigation_status: alias
layout: parameter
name: BATTD_FL_VLT_MIN
range: 0.01 10
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_FuelLevel_Analog.cpp#L37
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_BattMonitor/AP_BattMonitor_FuelLevel_Analog.h#L50
units: V
visual_asset_id: null
---

# Empty fuel level voltage

**Note:** This parameter configures instance D. It functions identically to [BATT_FL_VLT_MIN](../BATT/BATT_FL_VLT_MIN.html).
