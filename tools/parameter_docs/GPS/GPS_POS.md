---
layout: parameter
name: GPS_POS
display_name: GPS Antenna Offset
description: Position of the GPS antenna relative to the vehicle's center of gravity.
default_value: 0
range: 
units: m
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp
---

# GPS Antenna Offset (GPS_POS)

## Description
Specifies the physical location of the GPS antenna in body-frame coordinates (X:Forward, Y:Right, Z:Down). Providing accurate offsets improves position and velocity estimation, especially during aggressive maneuvers.
