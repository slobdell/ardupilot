---
layout: parameter
name: EK2_YAW_M_NSE
display_name: Yaw measurement noise
description: RMS value of noise in yaw measurements from the magnetometer.
default_value: 0.5
range: 0.05 1.0
units: rad
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Yaw measurement noise (EK2_YAW_M_NSE)

## Description
Specifies the expected noise level in the yaw (heading) data.