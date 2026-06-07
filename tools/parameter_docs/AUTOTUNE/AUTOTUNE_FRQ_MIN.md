---
layout: parameter
name: AUTOTUNE_FRQ_MIN
display_name: AutoTune minimum sweep frequency
description: Defines the start frequency for sweeps and dwells during Helicopter AutoTune.
default_value: 10.0
range: 10 30
units: Hz
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Heli.cpp
---

# AutoTune minimum sweep frequency (AUTOTUNE_FRQ_MIN)

## Description
The starting frequency for the automated frequency response testing used in Helicopter AutoTune.

## Tuning & Behavior
*   **Default Value:** 10.0 Hz
*   **Range:** 10 to 30 Hz