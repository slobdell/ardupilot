---
layout: parameter
name: FLAP_2_SPEED
display_name: Flap 2 Speed
description: The speed in meters per second at which to engage the second stage of flaps.
default_value: 0
range: 0 100
units: m/s
group: FLAP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Flap 2 Speed (FLAP_2_SPEED)

## Description
Defines the airspeed threshold for automatically deploying the second stage (FLAP_2_PERCNT) of wing flaps.