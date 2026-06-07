---
layout: parameter
name: EK3_WIND_P_NSE
display_name: Wind velocity process noise
description: State process noise controlling the growth of wind state error estimates.
default_value: 0.1
range: 0.01 2.0
units: m/s/s
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Wind velocity process noise (EK3_WIND_P_NSE)

## Description
Controls how quickly EKF3 adapts to changing wind conditions.
