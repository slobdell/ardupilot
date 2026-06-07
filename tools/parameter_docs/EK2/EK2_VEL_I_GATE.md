---
layout: parameter
name: EK2_VEL_I_GATE
display_name: GPS velocity innovation gate size
description: Percentage number of standard deviations applied to the GPS velocity measurement innovation consistency check.
default_value: 500
range: 100 1000
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# GPS velocity innovation gate size (EK2_VEL_I_GATE)

## Description
Determines the "strictness" of the GPS velocity check. Decreasing it makes the EKF more likely to reject GPS data that seems slightly inconsistent with other sensors. Increasing it makes the EKF more tolerant but risks accepting bad GPS data.