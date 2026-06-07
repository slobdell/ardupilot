---
layout: parameter
name: COMPASS_PMOT_EN
display_name: Per-motor interference enable
description: Enables per-motor magnetic interference compensation.
default_value: 0
range: 0 1
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/Compass_PerMotor.cpp
---

# Per-motor interference enable (COMPASS_PMOT_EN)

## Description
Enables an advanced version of CompassMot that tracks and compensates for the magnetic interference of each individual motor, rather than the aircraft's total power draw.
