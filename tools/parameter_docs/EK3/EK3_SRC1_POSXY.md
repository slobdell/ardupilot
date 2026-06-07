---
layout: parameter
name: EK3_SRC1_POSXY
display_name: Position Horizontal Source (Primary)
description: Specifies the primary source for horizontal position estimation.
default_value: 3
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF/AP_NavEKF_Source.cpp
---

# Position Horizontal Source (Primary) (EK3_SRC1_POSXY)

## Description
Defines where the EKF3 algorithm gets its primary horizontal (latitude/longitude) position data.

## Tuning & Behavior
*   **Default Value:** 3 (GPS)
*   **Values:** 0:None, 3:GPS, 4:Beacon, 6:ExternalNav
*   **Most common setting is GPS.**
