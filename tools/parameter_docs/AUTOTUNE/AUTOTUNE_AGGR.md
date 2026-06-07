---
layout: parameter
name: AUTOTUNE_AGGR
display_name: Autotune aggressiveness
description: Autotune aggressiveness. Defines the bounce back used to detect size of the D term.
default_value: 0.075
range: 0.05 0.10
units: 
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Multi.cpp
---

# Autotune aggressiveness (AUTOTUNE_AGGR)

## Description
Determines how "sharp" the resulting PID gains will be. Higher aggressiveness results in a more responsive aircraft but increases the risk of oscillation.

## Tuning & Behavior
*   **Default Value:** 0.075
*   **Range:** 0.05 to 0.10 (Typical)
*   **Lower values (e.g., 0.05) produce a "softer" tune suitable for cinematic flight.**
*   **Higher values (e.g., 0.10) produce a "stiffer" tune suitable for racing or high-precision flight.**
