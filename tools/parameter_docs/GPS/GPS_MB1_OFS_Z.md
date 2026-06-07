---
layout: parameter
name: GPS_MB1_OFS_Z
display_name: Moving Base Z Offset (GPS 1)
description: The vertical distance (in meters) from the second GPS antenna to the primary (base) antenna on the first GPS instance.
default_value: 0
range: -5 5
units: m
group: GPS
visual_asset_id: gps_heading_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/MovingBase.cpp#L35
---

# Moving Base Z Offset (GPS_MB1_OFS_Z)

## Description
`GPS_MB1_OFS_Z` defines the vertical distance between the two GPS antennas.

*   **Positive Z:** The Base antenna is lower than the Rover antenna.
*   **Negative Z:** The Base antenna is higher than the Rover antenna.
