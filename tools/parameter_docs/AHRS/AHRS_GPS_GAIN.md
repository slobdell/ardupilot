---
layout: parameter
name: AHRS_GPS_GAIN
display_name: AHRS GPS gain
description: This controls how much to use the GPS to correct the attitude. This should never be set to zero for a plane as it would result in the plane losing control in turns. For a plane please use the default value of 1.0.
default_value: 1.0
range: 0.0 1.0
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# AHRS GPS gain (AHRS_GPS_GAIN)

## Description
Weighting of GPS data for correcting the attitude estimate.

## Tuning & Behavior
*   **Default Value:** 1.0
*   **Range:** 0.0 to 1.0
*   **Critical for Plane safety during coordinated turns.**
