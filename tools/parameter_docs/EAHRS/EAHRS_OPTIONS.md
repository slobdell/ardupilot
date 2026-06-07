---
layout: parameter
name: EAHRS_OPTIONS
display_name: External AHRS options
description: External AHRS options bitmask.
default_value: 0
range: 
units: 
group: EAHRS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ExternalAHRS/AP_ExternalAHRS.cpp
---

# External AHRS options (EAHRS_OPTIONS)

## Description
Bitmask for advanced configuration of the external AHRS interface.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   Bit 0: Vector Nav use uncompensated values (direct sensor data)