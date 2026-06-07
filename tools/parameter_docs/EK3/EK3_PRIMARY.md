---
layout: parameter
name: EK3_PRIMARY
display_name: Primary core number
description: The core number that will be used as the primary EKF core on startup.
default_value: 0
range: 0 2
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Primary core number (EK3_PRIMARY)

## Description
Selects the initial primary EKF core. Lane 0 corresponds to the first IMU enabled in EK3_IMU_MASK.