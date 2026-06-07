---
layout: parameter
name: COMPASS_AUTO_ROT
display_name: Automatically check orientation
description: When enabled, this will automatically check the orientation of compasses on successful completion of compass calibration.
default_value: 2
range: 0 3
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/AP_Compass.cpp
---

# Automatically check orientation (COMPASS_AUTO_ROT)

## Description
A calibration helper that determines if the user's COMPASS_ORIENT setting matches the physical data collected during calibration.

## Tuning & Behavior
*   **Default Value:** 2 (CheckAndFix)
*   **Values:** 0:Disabled, 1:CheckOnly, 2:CheckAndFix
