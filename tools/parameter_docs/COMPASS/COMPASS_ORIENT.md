---
layout: parameter
name: COMPASS_ORIENT
display_name: Compass orientation
description: The orientation of the first external compass relative to the vehicle frame.
default_value: 0
range: 
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass orientation (COMPASS_ORIENT)

## Description
Defines the software rotation for the primary compass. This is critical if the compass (often part of the GPS module) is mounted in any direction other than perfectly forward and upright.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Common Values:** 0:None, 8:Roll180 (very common for GPS/Compass modules), 100:Custom