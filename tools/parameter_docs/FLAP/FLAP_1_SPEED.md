---
layout: parameter
name: FLAP_1_SPEED
display_name: Flap 1 Speed
description: The speed in meters per second at which to engage the first stage of flaps.
default_value: 0
range: 0 100
units: m/s
group: FLAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Flap 1 Speed (FLAP_1_SPEED)

## Description
Defines the airspeed threshold for automatically deploying the first stage (FLAP_1_PERCNT) of wing flaps.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Should be set higher than or equal to FLAP_2_SPEED.**