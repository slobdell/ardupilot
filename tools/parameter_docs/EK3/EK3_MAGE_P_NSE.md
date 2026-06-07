---
layout: parameter
name: EK3_MAGE_P_NSE
display_name: Earth magnetic field process noise
description: Controls the growth of earth magnetic field state error estimates for EKF3.
default_value: 0.001
range: 0.00001 0.01
units: Gauss/s
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Earth magnetic field process noise (EK3_MAGE_P_NSE)

## Description
Specifies how quickly EKF3 adapts its estimate of the local Earth magnetic field.
