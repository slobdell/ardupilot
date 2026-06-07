---
layout: parameter
name: ACRO_OPTIONS
display_name: Acro mode options
description: A range of options that can be applied to change acro mode behaviour.
default_value: 0
range: 
units: 
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Acro mode options (ACRO_OPTIONS)

## Description
Bitmask for configuring specific Acro mode behaviors like Air-mode.

## Tuning & Behavior
*   **Default Value:** 0
*   **Bitmask:**
    *   0: Air-mode (Enables mixer at all times)
    *   1: Rate Loop Only (Disables angle stabilization completely)
