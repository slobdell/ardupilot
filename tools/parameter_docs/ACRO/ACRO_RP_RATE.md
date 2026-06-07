---
layout: parameter
name: ACRO_RP_RATE
display_name: ACRO roll and pitch rate
description: Sets the maximum roll and pitch rate commanded in ACRO mode.
default_value: 360
range: 1 360
units: deg/s
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AttitudeControl/AC_CommandModel.cpp
---

# ACRO roll and pitch rate (ACRO_RP_RATE)

## Description
Maximum angular velocity achievable in roll and pitch when in ACRO mode.

## Tuning & Behavior
*   **Default Value:** 360 deg/s
*   **Range:** 1 to 360 deg/s