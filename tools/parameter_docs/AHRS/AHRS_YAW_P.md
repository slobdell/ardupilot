---
layout: parameter
name: AHRS_YAW_P
display_name: Yaw P
description: This controls the weight the compass or GPS has on the heading. A higher value means the heading will track the yaw source (GPS or compass) more rapidly.
default_value: 0.2
range: 0.1 0.4
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# Yaw P (AHRS_YAW_P)

## Description
Proportional gain for heading correction using compass or GPS data.

## Tuning & Behavior
*   **Default Value:** 0.2
*   **Range:** 0.1 to 0.4
*   **Higher values track heading sources more aggressively.**