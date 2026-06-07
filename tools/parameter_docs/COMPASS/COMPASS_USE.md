---
layout: parameter
name: COMPASS_USE
display_name: Use compass for yaw
description: Enable or disable the use of the compass (instead of the GPS) for determining heading.
default_value: 1
range: 0 1
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Use compass for yaw (COMPASS_USE)

## Description
Determines if the primary compass data is actually used by the EKF (Extended Kalman Filter) to calculate the vehicle's heading (yaw).

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **If disabled, the vehicle must rely on GPS-based yaw (GHY) or other heading sources.**
