---
layout: parameter
name: H_FLYBAR_MODE
display_name: Flybar Mode Selector
description: Specifies if the helicopter airframe has a mechanical flybar.
default_value: 0
range: 0 1
units: 
group: H
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsHeli_Single.cpp
---

# Flybar Mode Selector (H_FLYBAR_MODE)

## Description
Tells the attitude controller if the aircraft has a physical flybar. 
*   **0: NoFlybar (Modern digital FBL system)**
*   **1: Flybar (Legacy mechanical stabilization)**