---
layout: parameter
name: BRAKE_RATE
display_name: FlowHold Brake Rate
description: Maximum rate in degrees/sec at which the vehicle will attempt to brake when pilot releases sticks in FlowHold mode.
default_value: 8
range: 1 50
units: deg/s
group: BRAKE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold Brake Rate (BRAKE_RATE)

## Description
Defines the maximum angular rate used for automatic braking in FlowHold mode.