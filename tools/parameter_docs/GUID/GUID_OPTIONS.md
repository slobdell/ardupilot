---
layout: parameter
name: GUID_OPTIONS
display_name: Guided mode options
description: Bitmask of options that can be applied to change guided mode behaviour.
default_value: 0
range: 
units: 
group: GUID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Guided mode options (GUID_OPTIONS)

## Description
Configuration bitmask for specific behaviors in Guided mode (Copter).

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Allow Arming (in Guided)
    *   Bit 1: Allow Takeoff
    *   Bit 2: Ignore pilot yaw
    *   Bit 3: SCurve for Waypoints