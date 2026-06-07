---
layout: parameter
name: EK2_HGT_I_GATE
display_name: Height measurement gate size
description: Percentage number of standard deviations applied to the height measurement innovation consistency check.
default_value: 500
range: 100 1000
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Height measurement gate size (EK2_HGT_I_GATE)

## Description
Determines the strictness of the altitude check.