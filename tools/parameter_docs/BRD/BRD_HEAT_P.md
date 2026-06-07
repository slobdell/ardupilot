---
layout: parameter
name: BRD_HEAT_P
display_name: Board Heater P gain
description: Proportional gain for the board heater PI controller.
default_value: 50
range: 1 500
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Board Heater P gain (BRD_HEAT_P)

## Description
Determines how aggressively the heater reacts to temperature deviations from the target.
