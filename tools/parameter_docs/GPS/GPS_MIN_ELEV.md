---
layout: parameter
name: GPS_MIN_ELEV
display_name: Minimum elevation
description: Minimum elevation in degrees of satellites above the horizon for them to be used for navigation.
default_value: -100
range: -100 90
units: deg
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# Minimum elevation (GPS_MIN_ELEV)

## Description
Rejects satellites that are too close to the horizon, where signal multi-pathing and atmospheric distortion are highest. 
*   **-100 uses the GPS module's internal default.**
