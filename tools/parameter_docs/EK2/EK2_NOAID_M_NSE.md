---
layout: parameter
name: EK2_NOAID_M_NSE
display_name: Non-GPS position uncertainty
description: Position variation that the EKF allows when operating without external measurements (GPS/Flow).
default_value: 10.0
range: 0.5 50.0
units: m
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Non-GPS position uncertainty (EK2_NOAID_M_NSE)

## Description
Specifies how much "drift" is allowed when the aircraft is flying without a position source (dead-reckoning).