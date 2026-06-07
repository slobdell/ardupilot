---
layout: parameter
name: COMPASS_OFFS_MAX
display_name: Compass maximum offset
description: This sets the maximum allowed compass offset in calibration and arming checks.
default_value: 1800
range: 500 3000
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass maximum offset (COMPASS_OFFS_MAX)

## Description
A safety threshold for magnetometer calibration. If the resulting offsets are larger than this value, the calibration will be rejected as unhealthy.

## Tuning & Behavior
*   **Default Value:** 1800 (Default)
*   **Range:** 500 to 3000
*   **High offsets indicate the compass is too close to significant metal masses or high-current wires.**
