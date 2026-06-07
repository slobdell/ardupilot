---
layout: parameter
name: GROUND_STEER_ALT
display_name: Ground steer altitude
description: Altitude at which to stop using ground steering (Plane).
default_value: 0
range: -100 100
units: m
group: GROUND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Ground steer altitude (GROUND_STEER_ALT)

## Description
Defines the altitude threshold during takeoff at which the aircraft transitions from ground-based steering (nose wheel or tail wheel) to aerodynamic steering (rudder and ailerons). 
*   **0 (default) disables the altitude-based cutoff.**