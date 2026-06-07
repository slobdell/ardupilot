---
layout: parameter
name: ACRO_TURN_RATE
display_name: ACRO mode turn rate
description: The maximum turn rate in degrees per second at full stick deflection in ACRO mode (Plane/Rover).
default_value: 0
range: 10 500
units: deg/s
group: ACRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# ACRO mode turn rate (ACRO_TURN_RATE)

## Description
Maximum rate of heading change in ACRO mode.

## Tuning & Behavior
*   **Default Value:** 0 (Plane), 180 (Rover)
*   **Range:** 10 to 500 deg/s