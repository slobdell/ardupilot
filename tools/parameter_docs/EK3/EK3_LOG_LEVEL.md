---
layout: parameter
name: EK3_LOG_LEVEL
display_name: Logging Level
description: Determines how verbose the EKF3 streaming logging is.
default_value: 0
range: 0 3
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF3/AP_NavEKF3.cpp
---

# Logging Level (EK3_LOG_LEVEL)

## Description
Controls the verbosity of EKF3 data written to the log.
*   **0: Full logging (standard)**
*   **3: Disables EKF3 streaming logs entirely (to save CPU/bandwidth)**
