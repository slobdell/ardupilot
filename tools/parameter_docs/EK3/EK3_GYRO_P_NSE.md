---
layout: parameter
name: EK3_GYRO_P_NSE
display_name: Rate gyro noise
description: Control disturbance noise controlling the growth of estimated error due to gyro measurement errors.
default_value: 0.015
range: 0.0001 0.1
units: rad/s
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Rate gyro noise (EK3_GYRO_P_NSE)

## Description
Specifies the expected noise level in the gyroscopes for EKF3.
