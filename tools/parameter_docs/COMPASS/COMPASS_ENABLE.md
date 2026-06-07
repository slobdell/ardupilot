---
layout: parameter
name: COMPASS_ENABLE
display_name: Enable Compass
description: Setting this to Enabled(1) will enable the compass. Setting this to Disabled(0) will disable the compass. Note that this is separate from COMPASS_USE.
default_value: 1
range: 0 1
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Enable Compass (COMPASS_ENABLE)

## Description
Master power switch for the magnetometer library.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Values:** 0:Disabled, 1:Enabled
*   **Must be enabled to collect magnetometer data or perform a compass calibration.**
