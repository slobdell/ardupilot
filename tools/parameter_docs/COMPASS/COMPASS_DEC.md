---
layout: parameter
name: COMPASS_DEC
display_name: Compass declination
description: An angle to compensate between the true north and magnetic north.
default_value: 0
range: -3.142 3.142
units: rad
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass declination (COMPASS_DEC)

## Description
Manual offset to correct for the difference between Magnetic North and True North at your current location.

## Tuning & Behavior
*   **Default Value:** 0 rad
*   **Range:** -3.142 to 3.142 rad
*   **Usually set automatically if COMPASS_AUTODEC is enabled.**
