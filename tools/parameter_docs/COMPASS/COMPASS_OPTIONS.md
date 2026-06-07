---
layout: parameter
name: COMPASS_OPTIONS
display_name: Compass options
description: Bitmask of options to change the behaviour of the compass.
default_value: 0
range: 
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass options (COMPASS_OPTIONS)

## Description
Advanced configuration for the compass library.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: CalRequireGPS (Force GPS lock for calibration)
    *   Bit 1: Allow DroneCAN replacement
