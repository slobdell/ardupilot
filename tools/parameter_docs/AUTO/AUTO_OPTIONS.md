---
layout: parameter
name: AUTO_OPTIONS
display_name: Auto mode options
description: Bitmask of options that can be applied to change auto mode behaviour.
default_value: 0
range: 
units: 
group: AUTO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Auto mode options (AUTO_OPTIONS)

## Description
Configuration bitmask for specific autonomous flight behaviors.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask Examples:**
    *   0: Allow Arming (in Auto)
    *   1: Allow Takeoff Without Raising Throttle
    *   2: Ignore pilot yaw
    *   7: Allow weathervaning