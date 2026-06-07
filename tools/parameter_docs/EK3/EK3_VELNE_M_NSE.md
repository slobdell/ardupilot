---
layout: parameter
name: EK3_VELNE_M_NSE
display_name: GPS horizontal velocity noise
description: Lower limit on the speed accuracy reported by the GPS receiver for horizontal velocity.
default_value: 0.5
range: 0.05 5.0
units: m/s
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# GPS horizontal velocity noise (EK3_VELNE_M_NSE)

## Description
Specifies the expected noise level in the GPS horizontal velocity data for EKF3.