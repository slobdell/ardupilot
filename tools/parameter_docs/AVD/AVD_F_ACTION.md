---
layout: parameter
name: AVD_F_ACTION
display_name: Collision Avoidance Behavior (Fail)
description: Specifies aircraft behaviour when a collision is imminent (Fail threat level).
default_value: 1
range: 0 6
units: 
group: AVD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Avoidance/AP_Avoidance.cpp
---

# Collision Avoidance Behavior (AVD_F_ACTION)

## Description
Defines the automatic maneuver the aircraft will perform when it determines that a collision is likely within the F_TIME horizon.

## Tuning & Behavior
*   **Default Value:** 1 (Report)
*   **Values:** 0:None, 1:Report, 2:Climb Or Descend, 3:Move Horizontally, 4:Move Perpendicularly in 3D, 5:RTL, 6:Hover
