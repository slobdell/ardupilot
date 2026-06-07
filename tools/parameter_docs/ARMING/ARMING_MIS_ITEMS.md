---
layout: parameter
name: ARMING_MIS_ITEMS
display_name: Required mission items
description: Bitmask of mission items that are required to be planned in order to arm the aircraft.
default_value: 0
range: 
units: 
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Required mission items (ARMING_MIS_ITEMS)

## Description
Forces the pilot to include specific commands in their mission (e.g., Takeoff or Land) before the aircraft will arm.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   0: Land
    *   1: VTOL Land
    *   2: DO_LAND_START
    *   3: Takeoff
    *   4: VTOL Takeoff
    *   5: Rallypoint
    *   6: RTL