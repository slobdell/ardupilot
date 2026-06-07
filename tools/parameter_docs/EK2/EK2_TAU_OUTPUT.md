---
layout: parameter
name: EK2_TAU_OUTPUT
display_name: Output complementary filter time constant
description: Sets the time constant of the output complementary filter/predictor in centi-seconds.
default_value: 25
range: 10 50
units: cs
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Output complementary filter time constant (EK2_TAU_OUTPUT)

## Description
Determines the responsiveness of the final estimated output.