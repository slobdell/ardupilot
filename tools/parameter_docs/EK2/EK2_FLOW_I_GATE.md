---
layout: parameter
name: EK2_FLOW_I_GATE
display_name: Optical Flow measurement gate size
description: Percentage number of standard deviations applied to the optical flow innovation consistency check.
default_value: 300
range: 100 1000
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Optical Flow measurement gate size (EK2_FLOW_I_GATE)

## Description
Strictness of the optical flow consistency check.