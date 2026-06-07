---
layout: parameter
name: AHRS_GPS_USE
display_name: AHRS use GPS for DCM navigation
description: This controls whether to use dead-reckoning or GPS based navigation. If set to 0 then the GPS won't be used for navigation, and only dead reckoning will be used.
default_value: 1
range: 0 2
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# AHRS use GPS for DCM navigation (AHRS_GPS_USE)

## Description
Switch between GPS-aided navigation and pure dead-reckoning.

## Tuning & Behavior
*   **Default Value:** 1 (Use GPS for DCM position)
*   **Values:** 0:Disabled, 1:Use GPS for DCM position, 2:Use GPS for DCM position and height