---
layout: parameter
name: EK3_SRC1_VELXY
display_name: Velocity Horizontal Source (Primary)
description: Specifies the primary source for horizontal velocity estimation.
default_value: 3
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF/AP_NavEKF_Source.cpp
---

# Velocity Horizontal Source (Primary) (EK3_SRC1_VELXY)

## Description
Defines where the EKF3 algorithm gets its primary horizontal speed and direction data.

## Tuning & Behavior
*   **Default Value:** 3 (GPS)
*   **Values:** 0:None, 3:GPS, 4:Beacon, 5:OpticalFlow, 6:ExternalNav, 7:WheelEncoder
