---
layout: parameter
name: EK2_FLOW_DELAY
display_name: Optical Flow measurement delay
description: Number of msec that the optical flow measurements lag behind the inertial measurements.
default_value: 10
range: 0 127
units: ms
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Optical Flow measurement delay (EK2_FLOW_DELAY)

## Description
Compensates for the processing delay in the optical flow sensor.