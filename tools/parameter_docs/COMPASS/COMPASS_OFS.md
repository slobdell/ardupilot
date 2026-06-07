---
layout: parameter
name: COMPASS_OFS
display_name: Compass offsets (X, Y, Z)
description: Stored calibration offsets for the first compass.
default_value: 0
range: -400 400
units: mGauss
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass offsets (COMPASS_OFS)

## Description
The fundamental hard-iron calibration values for the primary magnetometer. These represent static magnetic fields within the aircraft itself.

## Tuning & Behavior
*   **Default Value:** 0 0 0
*   **Usually set automatically during the "Compass Calibration" process.**
*   **Note: In the codebase, this is stored as separate X, Y, Z parameters but often presented as a vector.**
