---
layout: parameter
name: COMPASS_CAL_FIT
display_name: Compass calibration fitness
description: Controls the fitness level required for a successful compass calibration.
default_value: 16
range: 4 32
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass calibration fitness (COMPASS_CAL_FIT)

## Description
Determines the "pass/fail" strictness of the compass calibration algorithm.

## Tuning & Behavior
*   **Default Value:** 16
*   **Lower values (e.g., 4) are stricter and harder to pass, but result in better heading accuracy.**
*   **Higher values (e.g., 32) are more relaxed and useful if you are in a location with high local magnetic interference.**
