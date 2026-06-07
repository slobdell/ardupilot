---
layout: parameter
name: BLEND_MASK
display_name: GPS Blending Mask
description: Bitmask of GPS instances to blend together.
default_value: 5
range: 
units: 
group: BLEND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# GPS Blending Mask (BLEND_MASK)

## Description
Defines which GPS receivers are included in the multi-GPS "blending" logic.

## Tuning & Behavior
*   **Default Value:** 5 (GPS1 and GPS2)
*   **Bitmask:**
    *   Bit 0: GPS1
    *   Bit 1: GPS2
    *   Bit 2: GPS3