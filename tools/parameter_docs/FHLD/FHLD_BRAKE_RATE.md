---
layout: parameter
name: FHLD_BRAKE_RATE
display_name: FlowHold Braking rate
description: Controls the deceleration rate in degrees/sec when the pilot releases the sticks in FlowHold mode.
default_value: 8
range: 1 30
units: deg/s
group: FHLD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold Braking rate (FHLD_BRAKE_RATE)

## Description
Defines the intensity of the automatic braking maneuver in FlowHold mode. Higher values result in a more aggressive stop.