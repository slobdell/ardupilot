---
layout: parameter
name: BRD_HEAT_I
display_name: Board Heater I gain
description: Integrator gain for the board heater PI controller.
default_value: 0.1
range: 0 1
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Board Heater I gain (BRD_HEAT_I)

## Description
Compensates for long-term temperature steady-state errors in the IMU heater.
