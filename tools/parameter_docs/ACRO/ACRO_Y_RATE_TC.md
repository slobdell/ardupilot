---
layout: parameter
name: ACRO_Y_RATE_TC
display_name: ACRO yaw rate time constant
description: Rate control input time constant for yaw. Low numbers lead to sharper response, higher numbers to softer response.
default_value: 0.1
range: 0 1
units: s
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AttitudeControl/AC_CommandModel.cpp
---

# ACRO yaw rate time constant (ACRO_Y_RATE_TC)

## Description
Smoothing factor for yaw rate commands in ACRO mode.

## Tuning & Behavior
*   **Default Value:** 0.1 s
*   **Range:** 0 to 1 s
*   **Values:** 0.5:Very Soft, 0.2:Soft, 0.15:Medium, 0.1:Crisp, 0.05:Very Crisp