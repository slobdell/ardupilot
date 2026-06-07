---
layout: parameter
name: ACRO_ROLL_RATE
display_name: ACRO mode roll rate
description: The maximum roll rate at full stick deflection in ACRO mode (ArduPlane).
default_value: 180
range: 10 500
units: deg/s
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# ACRO mode roll rate (ACRO_ROLL_RATE)

## Description
Maximum angular velocity for roll in Plane ACRO mode.

## Tuning & Behavior
*   **Default Value:** 180 deg/s
*   **Range:** 10 to 500 deg/s