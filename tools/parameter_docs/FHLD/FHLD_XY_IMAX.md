---
layout: parameter
name: FHLD_XY_IMAX
display_name: FlowHold Integrator Max
description: Maximum value for the FlowHold horizontal position integrator.
default_value: 1000
range: 0 4500
units: cdeg
group: FHLD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold Integrator Max (FHLD_XY_IMAX)

## Description
Limits the maximum authority of the I-term to prevent "wind-up" and excessive tilt.