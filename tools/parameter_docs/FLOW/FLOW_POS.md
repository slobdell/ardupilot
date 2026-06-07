---
layout: parameter
name: FLOW_POS
display_name: Position offset
description: Position of the optical flow sensor focal point in body frame.
default_value: 0
range: -5 5
units: m
group: FLOW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpticalFlow/AP_OpticalFlow.cpp
---

# Position offset (FLOW_POS)

## Description
XYZ position of the optical flow sensor focal point in body frame. Note: In the codebase this is split into _POS_X, _POS_Y, _POS_Z but exposed as a vector parameter.

## Tuning & Behavior
*   **Default Value:** 0 0 0 m
*   **Range:** -5 5