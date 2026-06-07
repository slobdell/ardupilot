---
layout: parameter
name: GPS_MB1_TYPE
display_name: Moving Base Type (GPS 1)
description: Controls the type of moving base used for GPS-based yaw calculation on the first GPS instance.
default_value: 0
range: 0 1
units: 
group: GPS
visual_asset_id: gps_heading_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_GPS/MovingBase.cpp#L10
---

# Moving Base Type (GPS_MB1_TYPE)

## Description
`GPS_MB1_TYPE` enables GPS-based yaw (heading) without a compass.

This is part of the **Moving Baseline** feature, where two GPS receivers (one "Base" and one "Rover") are mounted on the drone. By calculating the precise vector between them, ArduPilot can determine the drone's heading with extreme accuracy, regardless of magnetic interference.

*   **0: Relative to alternate GPS instance (Default).** The two GPS units on the drone talk to each other to find the heading.
*   **1: Relative to Custom Base.** Used for more complex setups with external base stations.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Requirement:** Requires two RTK-capable GPS modules (like u-blox F9P).
*   **Configuration:** You must also set the offsets between the two antennas using `GPS_MB1_OFS_X/Y/Z`.
