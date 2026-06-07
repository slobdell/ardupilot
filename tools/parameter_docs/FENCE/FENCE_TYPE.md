---
layout: parameter
name: FENCE_TYPE
display_name: Fence Type
description: Bitmask of enabled geofence types.
default_value: 7
range: 
units: 
group: FENCE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Fence/AC_Fence.cpp
---

# Fence Type (FENCE_TYPE)

## Description
Defines which boundary types are active. Multiple types can be enabled simultaneously using the bitmask.

## Tuning & Behavior
*   **Default Value:** 7 (Max Alt, Circle, and Polygon)
*   **Bitmask:**
    *   Bit 0: Max Altitude
    *   Bit 1: Circle Centered on Home
    *   Bit 2: Polygon (loaded from SD card or GCS)
    *   Bit 3: Min Altitude (Floor)
