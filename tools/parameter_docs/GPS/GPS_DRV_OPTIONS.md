---
layout: parameter
name: GPS_DRV_OPTIONS
display_name: driver options
description: Bitmask for additional backend-specific GPS options.
default_value: 0
range: 
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# driver options (GPS_DRV_OPTIONS)

## Description
Advanced configuration for the GPS driver, such as enabling specific UART ports for moving baseline data.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Use UART2 for moving baseline (ublox)
    *   Bit 2: Use baudrate 115200
    *   Bit 4: Use ellipsoid height instead of AMSL
