---
layout: parameter
name: EK2_POSNE_M_NSE
display_name: GPS horizontal position noise
description: This sets the GPS horizontal position observation noise.
default_value: 1.0
range: 0.1 10.0
units: m
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# GPS horizontal position noise (EK2_POSNE_M_NSE)

## Description
Specifies the expected noise level in the GPS horizontal position data.