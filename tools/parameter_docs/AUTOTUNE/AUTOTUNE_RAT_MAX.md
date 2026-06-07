---
layout: parameter
name: AUTOTUNE_RAT_MAX
display_name: Autotune maximum allowable angular rate
description: Maximum angular rate in deg/s allowed during autotune maneuvers (Helicopter).
default_value: 0
range: 0 500
units: deg/s
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Heli.cpp
---

# Autotune maximum allowable angular rate (AUTOTUNE_RAT_MAX)

## Description
Limits the maximum angular velocity reached during the Helicopter AutoTune process.

## Tuning & Behavior
*   **Default Value:** 0 (Calculated automatically)
*   **Range:** 0 to 500 deg/s