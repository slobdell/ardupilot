---
layout: parameter
name: EK2_HGT_DELAY
display_name: Height measurement delay
description: Number of milliseconds that the Height measurements lag behind the inertial measurements.
default_value: 60
range: 0 250
units: ms
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# Height measurement delay (EK2_HGT_DELAY)

## Description
Compensates for the processing and transmission time delay inherent in the altitude sensor (usually the barometer).