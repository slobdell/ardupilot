---
layout: parameter
name: EK2_FLOW_M_NSE
display_name: Optical flow measurement noise
description: RMS value of noise and errors in optical flow measurements.
default_value: 0.25
range: 0.05 1.0
units: rad/s
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Optical flow measurement noise (EK2_FLOW_M_NSE)

## Description
Specifies the expected noise level in the optical flow data.