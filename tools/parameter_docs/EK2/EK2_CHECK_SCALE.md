---
layout: parameter
name: EK2_CHECK_SCALE
display_name: GPS accuracy check scaler
description: Scales the thresholds used to check GPS accuracy before it is used by the EKF.
default_value: 100
range: 50 200
units: %
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# GPS accuracy check scaler (EK2_CHECK_SCALE)

## Description
Adjusts the global "strictness" of the pre-flight GPS accuracy checks.