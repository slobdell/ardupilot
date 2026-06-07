---
layout: parameter
name: COMPASS_DISBLMSK
display_name: Compass disable driver type mask
description: Bitmask of driver types to disable at startup.
default_value: 0
range: 
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass disable driver type mask (COMPASS_DISBLMSK)

## Description
Prevents ArduPilot from probing for specific magnetometer hardware types. Useful for speeding up boot times or avoiding hardware conflicts.

## Tuning & Behavior
*   **Default Value:** 0 (Probe everything)
*   **Bitmask Examples:**
    *   Bit 0: HMC5883
    *   Bit 11: DroneCAN
    *   Bit 16: RM3100
