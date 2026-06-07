---
layout: parameter
name: ACRO_RP_EXPO
display_name: ACRO roll and pitch expo
description: Controlled expo to allow faster rotation when stick at edges for roll and pitch.
default_value: 0.3
range: -0.5 1.0
units: 
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AttitudeControl/AC_CommandModel.cpp
---

# ACRO roll and pitch expo (ACRO_RP_EXPO)

## Description
Exponential curve applied to roll and pitch inputs in ACRO mode, providing fine control near the center while maintaining high rates at the stick extremes.

## Tuning & Behavior
*   **Default Value:** 0.3
*   **Range:** -0.5 to 1.0
*   **Higher values make the center of the stick less sensitive.**
