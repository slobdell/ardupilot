---
layout: parameter
name: GPS_RATE_MS
display_name: Desired update rate
description: The period between GPS updates in milliseconds.
default_value: 200
range: 50 200
units: ms
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp
---

# Desired update rate (GPS_RATE_MS)

## Description
The target update period for the GPS receiver.
*   **200ms = 5Hz (Standard)**
*   **100ms = 10Hz (High performance)**