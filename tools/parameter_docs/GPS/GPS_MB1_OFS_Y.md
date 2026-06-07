---
layout: parameter
name: GPS_MB1_OFS_Y
display_name: Moving Base Y Offset (GPS 1)
description: The lateral distance (in meters) from the second GPS antenna to the primary (base) antenna on the first GPS instance.
default_value: 0
range: -5 5
units: m
group: GPS
visual_asset_id: gps_heading_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/MovingBase.cpp#L35
---

# Moving Base Y Offset (GPS_MB1_OFS_Y)

## Description
`GPS_MB1_OFS_Y` defines the lateral (left/right) distance between the two antennas used for GPS-Yaw.

*   **Positive Y:** The Base antenna is to the right of the Rover antenna.
*   **Negative Y:** The Base antenna is to the left of the Rover antenna.
