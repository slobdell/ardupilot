---
layout: parameter
name: FHLD_XY_FILT_HZ
display_name: FlowHold filter frequency
description: Filter frequency for the FlowHold horizontal position controller input.
default_value: 5
range: 0 100
units: Hz
group: FHLD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold filter frequency (FHLD_XY_FILT_HZ)

## Description
Smoothing filter for the input to the FlowHold PI controller.