---
layout: parameter
name: BRD_HEAT_IMAX
display_name: Board Heater IMAX
description: Integrator maximum for the board heater controller.
default_value: 100
range: 0 100
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Board Heater IMAX (BRD_HEAT_IMAX)

## Description
Limits the maximum authority of the heater's integral term to prevent "wind-up" and overheating.