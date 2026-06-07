---
layout: parameter
name: EK2_GPS_TYPE
display_name: GPS mode control
description: Controls the use of GPS measurements in EKF2.
default_value: 0
range: 0 3
units: 
group: EK2
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF2/AP_NavEKF2.cpp
---

# GPS mode control (EK2_GPS_TYPE)

## Description
Determines how the EKF incorporates GPS data (velocity and position) into its estimation.

## Tuning & Behavior
*   **Default Value:** 0 (GPS 3D Vel and 2D Pos)
*   **Values:** 0:GPS 3D Vel and 2D Pos, 1:GPS 2D vel and 2D pos, 2:GPS 2D pos, 3:No GPS
*   **Option 3 is useful for indoor flight with optical flow.**
