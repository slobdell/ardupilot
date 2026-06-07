---
layout: parameter
name: CIRCLE_DIR
display_name: Circle Direction (Rover)
description: Specifies the direction of rotation for Rover Circle mode.
default_value: 0
range: 0 1
units: 
group: CIRCLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/mode_circle.cpp
---

# Circle Direction (CIRCLE_DIR)

## Description
Selects clockwise or counter-clockwise movement for Rover vehicles in Circle mode.

## Tuning & Behavior
*   **Default Value:** 0 (Clockwise)
*   **Values:** 0:Clockwise, 1:Counter-Clockwise