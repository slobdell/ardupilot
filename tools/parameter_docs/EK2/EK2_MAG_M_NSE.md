---
layout: parameter
name: EK2_MAG_M_NSE
display_name: Magnetometer measurement noise
description: RMS value of noise in magnetometer measurements.
default_value: 0.05
range: 0.01 0.5
units: Gauss
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Magnetometer measurement noise (EK2_MAG_M_NSE)

## Description
Specifies the expected noise level in the magnetometer data. Increasing it reduces the weighting of the compass in heading estimation.