---
layout: parameter
name: ACRO_PITCH_RATE
display_name: ACRO mode pitch rate
description: The maximum pitch rate at full stick deflection in ACRO mode (ArduPlane).
default_value: 180
range: 10 500
units: deg/s
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# ACRO mode pitch rate (ACRO_PITCH_RATE)

## Description
Maximum angular velocity for pitch in Plane ACRO mode.

## Tuning & Behavior
*   **Default Value:** 180 deg/s
*   **Range:** 10 to 500 deg/s