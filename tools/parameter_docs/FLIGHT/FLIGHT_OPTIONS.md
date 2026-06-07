---
layout: parameter
name: FLIGHT_OPTIONS
display_name: Flight options
description: Bitmask of miscellaneous flight options (Plane).
default_value: 0
range: 
units: 
group: FLIGHT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Flight options (FLIGHT_OPTIONS)

## Description
Configuration bitmask for various aircraft-specific flight behaviors in ArduPlane.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask Examples:**
    *   Bit 3: CENTER_THROTTLE_TRIM
    *   Bit 6: ENABLE_UNIT_SENSORS
    *   Bit 10: DISARM_LANDED_AUTO