---
layout: parameter
name: ACRO_Y_RATE
display_name: ACRO yaw rate
description: Sets the maximum yaw rate commanded in ACRO mode.
default_value: 200
range: 1 360
units: deg/s
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_AttitudeControl/AC_CommandModel.cpp
---

# ACRO yaw rate (ACRO_Y_RATE)

## Description
Maximum angular velocity achievable in yaw when in ACRO mode.

## Tuning & Behavior
*   **Default Value:** 200 deg/s
*   **Range:** 1 to 360 deg/s
