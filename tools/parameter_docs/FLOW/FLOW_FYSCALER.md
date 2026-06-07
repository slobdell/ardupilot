---
layout: parameter
name: FLOW_FYSCALER
display_name: Y axis optical flow scale factor correction
description: This sets the parts per thousand scale factor correction applied to the flow sensor Y axis optical rate. It can be used to correct for variations in effective focal length. Each positive increment of 1 increases the scale factor applied to the Y axis optical flow reading by 0.1%. Negative values reduce the scale factor.
default_value: 0
range: -800 +800
units: 
group: FLOW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpticalFlow/AP_OpticalFlow.cpp
---

# Y axis optical flow scale factor correction (FLOW_FYSCALER)

## Description
Scale factor correction for the Y axis optical flow rate.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** -800 800