---
layout: parameter
name: AUTOTUNE_MIN_D
display_name: AutoTune minimum D
description: Defines the minimum D gain allowed during autotune.
default_value: 0.0005
range: 0.0001 0.005
units: 
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AutoTune/AC_AutoTune_Multi.cpp
---

# AutoTune minimum D (AUTOTUNE_MIN_D)

## Description
A safety floor for the Rate D gain. AutoTune will not lower the D gain below this value, even if the physics of the aircraft suggest it.

## Tuning & Behavior
*   **Default Value:** 0.0005
*   **Range:** 0.0001 to 0.005
