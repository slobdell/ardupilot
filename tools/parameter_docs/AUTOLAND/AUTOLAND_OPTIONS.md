---
layout: parameter
name: AUTOLAND_OPTIONS
display_name: Landing options bitmask
description: Bitmask of options to use with landing.
default_value: 0
range: 
units: 
group: AUTOLAND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Landing/AP_Landing.cpp
---

# Landing options bitmask (AUTOLAND_OPTIONS)

## Description
Configuration bitmask for various landing behaviors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   0: honor min throttle during landing flare
    *   1: Increase Target landing airspeed constraint From Trim Airspeed to AIRSPEED_MAX