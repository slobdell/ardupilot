---
layout: parameter
name: AROT_HS_P
display_name: P gain for head speed controller
description: Increase value to increase sensitivity of head speed controller during autonomous autorotation.
default_value: 0.7
range: 0.3 1
units: 
group: AROT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Autorotation/AC_Autorotation.cpp
---

# P gain for head speed controller (AROT_HS_P)

## Description
Proportional gain for the rotor RPM (head speed) controller during autorotation.

## Tuning & Behavior
*   **Default Value:** 0.7
*   **Range:** 0.3 to 1
*   **A higher value makes the controller more aggressive in maintaining target head speed.**
