---
layout: parameter
name: EK2_GBIAS_P_NSE
display_name: Rate gyro bias stability
description: Process noise controlling growth of the gyro delta angle bias state error estimate.
default_value: 1.0E-04
range: 0.00001 0.001
units: rad/s/s
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Rate gyro bias stability (EK2_GBIAS_P_NSE)

## Description
Controls how quickly the EKF adapts to changes in gyro bias (drift). Higher values allow for faster adaptation but result in noisier bias estimates.