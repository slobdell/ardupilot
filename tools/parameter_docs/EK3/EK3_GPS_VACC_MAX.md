---
layout: parameter
name: EK3_GPS_VACC_MAX
display_name: GPS vertical accuracy threshold
description: Vertical accuracy threshold for GPS as the altitude source.
default_value: 0.0
range: 0.0 10.0
units: m
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# GPS vertical accuracy threshold (EK3_GPS_VACC_MAX)

## Description
Safety threshold for using GPS for altitude. If the GPS reported vertical accuracy is worse than this value, the EKF will automatically fall back to the barometer.
*   **0 deactivates the threshold check.**
