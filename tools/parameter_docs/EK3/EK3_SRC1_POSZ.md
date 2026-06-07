---
layout: parameter
name: EK3_SRC1_POSZ
display_name: Position Vertical Source (Primary)
description: Specifies the primary source for vertical position (altitude) estimation.
default_value: 1
range: 
units: 
group: EK3
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NavEKF/AP_NavEKF_Source.cpp
---

# Position Vertical Source (Primary) (EK3_SRC1_POSZ)

## Description
Defines where the EKF3 algorithm gets its primary altitude data.

## Tuning & Behavior
*   **Default Value:** 1 (Baro)
*   **Values:** 0:None, 1:Baro, 2:RangeFinder, 3:GPS, 4:Beacon, 6:ExternalNav
*   **Baro is standard for most flights.**
