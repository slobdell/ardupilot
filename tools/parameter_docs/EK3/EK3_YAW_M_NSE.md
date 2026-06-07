---
layout: parameter
name: EK3_YAW_M_NSE
display_name: Yaw measurement noise
description: RMS value of noise in yaw measurements for EKF3.
default_value: 0.5
range: 0.05 1.0
units: rad
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Yaw measurement noise (EK3_YAW_M_NSE)

## Description
Specifies the expected noise level in the yaw (heading) data.
