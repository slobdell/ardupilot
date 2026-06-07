---
layout: parameter
name: EK2_FLOW_USE
display_name: Optical flow use bitmask
description: Controls if the optical flow data is fused into the navigation estimator or terrain estimator.
default_value: 1
range: 0 2
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Optical flow use bitmask (EK2_FLOW_USE)

## Description
Determines how optical flow sensor data is utilized.
*   **1: Navigation (Velocity estimation)**
*   **2: Terrain (Height estimation)**