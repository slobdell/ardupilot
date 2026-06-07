---
layout: parameter
name: GPS_MB1_OFS_X
display_name: Moving Base X Offset (GPS 1)
description: The horizontal distance (in meters) from the second GPS antenna to the primary (base) antenna on the first GPS instance.
default_value: 0
range: -5 5
units: m
group: GPS
visual_asset_id: gps_heading_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/MovingBase.cpp#L35
---

# Moving Base X Offset (GPS_MB1_OFS_X)

## Description
`GPS_MB1_OFS_X` is the critical measurement for GPS-based yaw (heading).

When using two GPS units for heading (Moving Baseline), the autopilot calculates the drone's orientation by comparing the position of the "Rover" antenna to the "Base" antenna. To do this accurately, it must know the exact physical distance between them in the body frame.

*   **Positive X:** The Base antenna is in front of the Rover antenna.
*   **Negative X:** The Base antenna is behind the Rover antenna.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Accuracy:** This measurement must be accurate to within **1-2 centimeters** for the heading to be reliable. Use a tape measure or calipers.
*   **Orientation:** This is the offset *relative to the other antenna*, not relative to the center of gravity.
