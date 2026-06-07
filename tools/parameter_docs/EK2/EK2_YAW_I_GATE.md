---
layout: parameter
name: EK2_YAW_I_GATE
display_name: Yaw measurement gate size
description: Percentage number of standard deviations applied to the magnetometer yaw measurement innovation consistency check.
default_value: 300
range: 100 1000
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Yaw measurement gate size (EK2_YAW_I_GATE)

## Description
Determines the strictness of the heading (yaw) check.