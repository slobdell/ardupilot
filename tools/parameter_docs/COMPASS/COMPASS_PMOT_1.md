---
layout: parameter
name: COMPASS_PMOT_1
display_name: Per-motor interference - Motor 1
description: Interference scaling for Motor 1.
default_value: 0
range: 
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/Compass_PerMotor.cpp
---

# Per-motor interference - Motor 1 (COMPASS_PMOT_1)

## Description
Individual magnetic interference coefficient for the first motor.
*   **Note: Subsequent parameters (PMOT_2, PMOT_3, etc.) exist for each motor.**