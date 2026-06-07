---
layout: parameter
name: ACRO_Y_EXPO
display_name: ACRO yaw expo
description: Controlled expo to allow faster rotation when stick at edges for yaw.
default_value: 0
range: -0.5 1.0
units: 
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AttitudeControl/AC_CommandModel.cpp
---

# ACRO yaw expo (ACRO_Y_EXPO)

## Description
Exponential curve applied to yaw inputs in ACRO mode.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** -0.5 to 1.0
