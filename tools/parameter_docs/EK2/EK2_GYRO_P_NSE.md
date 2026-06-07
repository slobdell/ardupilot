---
layout: parameter
name: EK2_GYRO_P_NSE
display_name: Rate gyro noise
description: Control disturbance noise controlling the growth of estimated error due to gyro measurement errors.
default_value: 3.0E-02
range: 0.0001 0.1
units: rad/s
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Rate gyro noise (EK2_GYRO_P_NSE)

## Description
Specifies the expected high-frequency noise level in the gyroscopes. Higher values make the EKF trust the gyros less and rely more on other sensors (like compass and GPS).