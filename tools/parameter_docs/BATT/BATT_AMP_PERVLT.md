---
layout: parameter
name: BATT_AMP_PERVLT
display_name: Amps per volt
description: Number of amps that a 1V reading on the current sensor corresponds to.
default_value: 17.0
range: 
units: A/V
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Analog.cpp
---

# Amps per volt (BATT_AMP_PERVLT)

## Description
Scaling factor for the current ADC reading. It defines the relationship between the voltage output of the current sensor and the actual amperage flowing through it.
