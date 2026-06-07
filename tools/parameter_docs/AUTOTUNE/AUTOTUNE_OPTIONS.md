---
layout: parameter
name: AUTOTUNE_OPTIONS
display_name: AutoTune options
description: Bitmask of options that can be applied to change AutoTune behaviour.
default_value: 0
range: 
units: 
group: AUTOTUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# AutoTune options (AUTOTUNE_OPTIONS)

## Description
Bitmask for configuring specific AutoTune behaviors, such as whether to automatically save gains upon completion or use specific tuning logic.

## Tuning & Behavior
*   **Default Value:** 0