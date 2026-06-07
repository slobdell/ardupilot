---
layout: parameter
name: FHLD_XY_P
display_name: FlowHold P gain
description: Proportional gain for the FlowHold horizontal position controller.
default_value: 0.2
range: 0.1 6.0
units: 
group: FHLD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold P gain (FHLD_XY_P)

## Description
Determines the immediate corrective response to position drift in FlowHold mode.