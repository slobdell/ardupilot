---
layout: parameter
name: EK2_ACC_P_NSE
display_name: Accelerometer noise
description: Control disturbance noise controlling the growth of estimated error due to accelerometer measurement errors.
default_value: 0.6
range: 0.01 1.0
units: m/s/s
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Accelerometer noise (EK2_ACC_P_NSE)

## Description
Specifies the expected high-frequency noise level in the accelerometers.