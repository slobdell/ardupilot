---
layout: parameter
name: FLOW_HGT_OVR
display_name: Height override of sensor above ground
description: This is used in rover vehicles, where the sensor is a fixed height above the ground.
default_value: 0
range: 0 2
units: m
group: FLOW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpticalFlow/AP_OpticalFlow.cpp
---

# Height override of sensor above ground (FLOW_HGT_OVR)

## Description
Fixed height override for rover vehicles.

## Tuning & Behavior
*   **Default Value:** 0 m
*   **Range:** 0 2