---
layout: parameter
name: EK3_SRC1_YAW
display_name: Yaw Source (Primary)
description: Specifies the primary source for heading (yaw) estimation.
default_value: 1
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF/AP_NavEKF_Source.cpp
---

# Yaw Source (Primary) (EK3_SRC1_YAW)

## Description
Defines where the EKF3 algorithm gets its primary heading (yaw) data.

## Tuning & Behavior
*   **Default Value:** 1 (Compass)
*   **Values:** 0:None, 1:Compass, 2:GPS, 3:GPS with Compass Fallback, 6:ExternalNav, 8:GSF
*   **Option 2 (GPS) refers to "moving baseline" dual-antenna GPS yaw.**
