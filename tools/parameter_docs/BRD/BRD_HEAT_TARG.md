---
layout: parameter
name: BRD_HEAT_TARG
display_name: Board heater temperature target
description: Board heater target temperature for boards with controllable heating units. Set to -1 to disable the heater.
default_value: -1
range: -1 80
units: degC
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BoardConfig/AP_BoardConfig.cpp
---

# Board heater temperature target (BRD_HEAT_TARG)

## Description
Target temperature for the integrated IMU heater. Keeping the IMU at a constant temperature reduces thermal drift and improves sensor accuracy, especially in cold environments.