---
layout: parameter
name: DRV_OPTIONS
display_name: GPS Driver Options
description: Bitmask of options for the GPS driver.
default_value: 0
range: 
units: 
group: DRV
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# GPS Driver Options (DRV_OPTIONS)

## Description
Bitmask for configuring driver-specific GPS behaviors, such as enabling specific NMEA sentences or handling hardware-level timing.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask Examples:**
    *   Bit 0: Use GPS_DRV_OPTIONS bit 0 (varies by backend)