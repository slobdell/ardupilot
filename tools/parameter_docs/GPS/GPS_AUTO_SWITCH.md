---
layout: parameter
name: GPS_AUTO_SWITCH
display_name: Automatic Switchover Setting
description: Controls how ArduPilot switches between multiple GPS modules.
default_value: 1
range: 0 4
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# Automatic Switchover Setting (GPS_AUTO_SWITCH)

## Description
Defines the logic for selecting which GPS receiver's data is sent to the EKF when two or more modules are active.

## Tuning & Behavior
*   **Default Value:** 1 (UseBest)
*   **Values:** 
    *   0: Use Primary (Strictly use GPS_PRIMARY)
    *   1: UseBest (Select based on highest fix status and sat count)
    *   2: Blend (Mathematically combine data from all receivers)
    *   4: Use primary if 3D fix or better
