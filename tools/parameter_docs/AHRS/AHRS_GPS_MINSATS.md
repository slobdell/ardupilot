---
layout: parameter
name: AHRS_GPS_MINSATS
display_name: AHRS GPS Minimum satellites
description: Minimum number of satellites visible to use GPS for velocity based corrections attitude correction. This defaults to 6, which is about the point at which the velocity numbers from a GPS become too unreliable for accurate correction of the accelerometers.
default_value: 6
range: 0 10
units: 
group: AHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_AHRS/AP_AHRS.cpp
---

# AHRS GPS Minimum satellites (AHRS_GPS_MINSATS)

## Description
Threshold for GPS satellite count required for velocity-based attitude correction.

## Tuning & Behavior
*   **Default Value:** 6
*   **Range:** 0 to 10
