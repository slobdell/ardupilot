---
layout: parameter
name: CHUTE_ALT_MIN
display_name: Parachute min altitude
description: Parachute min altitude above home. Parachute will not be released below this altitude.
default_value: 10
range: 0 32000
units: m
group: CHUTE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Parachute/AP_Parachute.cpp
---

# Parachute min altitude (CHUTE_ALT_MIN)

## Description
Safety floor for parachute release. To prevent injury to people on the ground or damage to the aircraft from a low-altitude deployment, the parachute will only trigger if the vehicle is above this altitude.
*   **0 disables the altitude check.**
