---
layout: parameter
name: EK3_ALT_M_NSE
display_name: Altitude measurement noise
description: RMS value of noise in the altitude measurement for EKF3.
default_value: 2.0
range: 0.1 100.0
units: m
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Altitude measurement noise (EK3_ALT_M_NSE)

## Description
Specifies the expected noise level in the altitude data (Baro/GPS).