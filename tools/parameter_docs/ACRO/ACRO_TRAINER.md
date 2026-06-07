---
layout: parameter
name: ACRO_TRAINER
display_name: ACRO trainer
description: Levels the aircraft when the pilot releases the sticks in ACRO mode.
default_value: 2
range: 0 2
units: 
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# ACRO trainer (ACRO_TRAINER)

## Description
Assistance mode for ACRO flight, allowing for automatic leveling or angle limiting.

## Tuning & Behavior
*   **Default Value:** 2 (Limited)
*   **Values:** 0:Disabled, 1:Leveling, 2:Limited