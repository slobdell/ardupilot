---
layout: parameter
name: EK3_GSF_RUN_MASK
display_name: Bitmask of which EKF-GSF yaw estimators run
description: Bitmask of which EKF3 instances run an independent EKF-GSF yaw estimator.
default_value: 3
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Bitmask of which EKF-GSF yaw estimators run (EK3_GSF_RUN_MASK)

## Description
Enables the Gaussian Sum Filter (GSF) yaw estimator for specific EKF3 cores. GSF provides a yaw estimate derived from IMU and GPS velocity data, serving as a backup if the magnetometer is compromised.
