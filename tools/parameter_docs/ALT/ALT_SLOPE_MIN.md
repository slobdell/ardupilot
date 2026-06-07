---
layout: parameter
name: ALT_SLOPE_MIN
display_name: Glide slope minimum
description: This controls the minimum altitude change for a waypoint before a glide slope will be used instead of an immediate altitude change.
default_value: 15
range: 
units: m
group: ALT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Glide slope minimum (ALT_SLOPE_MIN)

## Description
Defines the minimum vertical distance required between waypoints to trigger a linear glide slope (gradual climb/descent). For smaller changes, the aircraft may attempt an immediate altitude change.

## Tuning & Behavior
*   **Default Value:** 15 m
*   **A value of 0 disables glide slope calculations, leading to immediate altitude setpoint changes.**