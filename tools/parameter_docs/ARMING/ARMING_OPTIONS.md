---
layout: parameter
name: ARMING_OPTIONS
display_name: Arming options
description: Options that can be applied to change arming behaviour.
default_value: 0
range: 
units: 
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Arming options (ARMING_OPTIONS)

## Description
Bitmask for miscellaneous arming-related behaviors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   0: Disable prearm display
    *   1: Do not send status text on state change
    *   2: Skip IMU consistency checks when ICE motor running
