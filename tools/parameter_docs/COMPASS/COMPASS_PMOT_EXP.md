---
layout: parameter
name: COMPASS_PMOT_EXP
display_name: Per-motor interference exponent
description: Exponent used for per-motor magnetic interference compensation.
default_value: 1.0
range: 
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/Compass_PerMotor.cpp
---

# Per-motor interference exponent (COMPASS_PMOT_EXP)

## Description
Mathematical exponent used to model how magnetic interference scales with individual motor power in advanced compensation modes.
