---
layout: parameter
name: FHLD_FILT_HZ
display_name: FlowHold Filter Frequency
description: Low pass filter frequency for raw optical flow data in FlowHold mode.
default_value: 5
range: 1 100
units: Hz
group: FHLD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/mode_flowhold.cpp
---

# FlowHold Filter Frequency (FHLD_FILT_HZ)

## Description
Smooths the noisy raw data from the optical flow sensor before it is used by the position controller.