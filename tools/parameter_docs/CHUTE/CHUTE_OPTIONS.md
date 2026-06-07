---
layout: parameter
name: CHUTE_OPTIONS
display_name: Parachute options
description: Optional behaviour for parachute.
default_value: 0
range: 
units: 
group: CHUTE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Parachute/AP_Parachute.cpp
---

# Parachute options (CHUTE_OPTIONS)

## Description
Bitmask for advanced parachute behaviors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Hold open forever after release
    *   Bit 1: Skip disarm before parachute release