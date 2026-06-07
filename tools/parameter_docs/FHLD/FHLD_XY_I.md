---
layout: parameter
name: FHLD_XY_I
display_name: FlowHold I gain
description: Integral gain for the FlowHold horizontal position controller.
default_value: 0.1
range: 0.02 1.00
units: 
group: FHLD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold I gain (FHLD_XY_I)

## Description
Corrects for long-term steady-state drift in FlowHold mode, such as that caused by wind or slight sensor bias.