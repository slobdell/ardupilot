---
layout: parameter
name: EK2_ALT_M_NSE
display_name: Altitude measurement noise
description: RMS value of noise in the altitude measurement.
default_value: 3.0
range: 0.1 10.0
units: m
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Altitude measurement noise (EK2_ALT_M_NSE)

## Description
Specifies the expected noise level in the altitude data (typically Baro). Increasing this value reduces the weighting of altitude measurements, making the filter respond more slowly to altitude changes.