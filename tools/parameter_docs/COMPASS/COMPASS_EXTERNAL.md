---
layout: parameter
name: COMPASS_EXTERNAL
display_name: Compass is attached via an external cable
description: Configure compass so it is attached externally. This is auto-detected on most boards.
default_value: 0
range: 0 2
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Compass is attached via an external cable (COMPASS_EXTERNAL)

## Description
Tells ArduPilot whether the compass is part of the flight controller (Internal) or located on a separate module (External, like a GPS puck).

## Tuning & Behavior
*   **Default Value:** 0 (Internal)
*   **Values:** 0:Internal, 1:External, 2:ForcedExternal
*   **When set to 1 or 2, COMPASS_ORIENT is used instead of the board's global AHRS_ORIENTATION.**
