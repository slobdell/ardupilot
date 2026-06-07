---
layout: parameter
name: AUTOTUNE_FRQ_MAX
display_name: AutoTune maximum sweep frequency
description: Defines the end frequency for sweeps and dwells during Helicopter AutoTune.
default_value: 70.0
range: 50 120
units: Hz
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Heli.cpp
---

# AutoTune maximum sweep frequency (AUTOTUNE_FRQ_MAX)

## Description
The ending frequency for the automated frequency response testing used in Helicopter AutoTune.

## Tuning & Behavior
*   **Default Value:** 70.0 Hz
*   **Range:** 50 to 120 Hz