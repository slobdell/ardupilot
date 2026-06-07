---
layout: parameter
name: AUTOTUNE_GN_MAX
display_name: AutoTune maximum response gain
description: Defines the response gain (output/input) to tune towards during Helicopter AutoTune.
default_value: 1.0
range: 1 2.5
units: 
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Heli.cpp
---

# AutoTune maximum response gain (AUTOTUNE_GN_MAX)

## Description
Target closed-loop gain for the Helicopter rate controller during the tuning process.

## Tuning & Behavior
*   **Default Value:** 1.0
*   **Range:** 1.0 to 2.5