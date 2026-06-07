---
layout: parameter
name: GPS_GNSS_MODE
display_name: GNSS constellation mask
description: Bitmask of GNSS constellations to use.
default_value: 0
range: 
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp
---

# GNSS constellation mask (GPS_GNSS_MODE)

## Description
Specifies which global satellite systems the receiver should use (e.g., GPS, GLONASS, Galileo, BeiDou).
*   **A value of 0 usually allows the receiver to use all supported constellations.**