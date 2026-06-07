---
layout: parameter
name: AUTOTUNE_ACC_MAX
display_name: AutoTune maximum allowable angular acceleration
description: Maximum angular acceleration in deg/s/s allowed during autotune maneuvers (Helicopter).
default_value: 0
range: 1 4000
units: deg/s/s
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Heli.cpp
---

# AutoTune maximum allowable angular acceleration (AUTOTUNE_ACC_MAX)

## Description
Limits the intensity of the "twitches" used by the Helicopter AutoTune process by capping the maximum angular acceleration.

## Tuning & Behavior
*   **Default Value:** 0 (Calculated automatically)
*   **Range:** 1 to 4000 deg/s/s