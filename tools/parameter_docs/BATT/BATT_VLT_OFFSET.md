---
layout: parameter
name: BATT_VLT_OFFSET
display_name: Voltage offset
description: Voltage offset on voltage pin. This allows for an offset due to a diode.
default_value: 0
range: 
units: V
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.cpp
---

# Voltage offset (BATT_VLT_OFFSET)

## Description
A static voltage offset subtracted from the ADC reading before the multiplier is applied. Commonly used to account for voltage drops across protective diodes.