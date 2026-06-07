---
layout: parameter
name: EK3_POSNE_M_NSE
display_name: GPS horizontal position noise
description: This sets the GPS horizontal position observation noise.
default_value: 0.5
range: 0.1 10.0
units: m
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# GPS horizontal position noise (EK3_POSNE_M_NSE)

## Description
Specifies the expected noise level in the GPS horizontal position data for EKF3.