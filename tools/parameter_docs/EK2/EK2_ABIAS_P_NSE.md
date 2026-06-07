---
layout: parameter
name: EK2_ABIAS_P_NSE
display_name: Accelerometer bias stability
description: Noise controlling the growth of the vertical accelerometer delta velocity bias state error estimate.
default_value: 5.0E-03
range: 0.00001 0.005
units: m/s/s/s
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Accelerometer bias stability (EK2_ABIAS_P_NSE)

## Description
Controls how quickly the EKF adapts to changes in accelerometer bias.