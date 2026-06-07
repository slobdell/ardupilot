---
layout: parameter
name: AUTOTUNE_VELXY_P
display_name: AutoTune velocity xy P gain
description: Velocity xy P gain used to hold position during Helicopter AutoTune frequency sweeps.
default_value: 0.1
range: 0 1
units: 
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Heli.cpp
---

# AutoTune velocity xy P gain (AUTOTUNE_VELXY_P)

## Description
Proportional gain for the position-hold logic active during Helicopter AutoTune. This helps keep the aircraft from drifting significantly while it is being "twitched" for frequency response analysis.

## Tuning & Behavior
*   **Default Value:** 0.1
*   **Range:** 0 to 1