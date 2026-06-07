---
layout: parameter
name: AUTO_SWITCH
display_name: GPS Auto Switch
description: Controls how ArduPilot switches between multiple GPS modules.
default_value: 1
range: 0 4
units: 
group: AUTO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# GPS Auto Switch (AUTO_SWITCH)

## Description
Logic for choosing the active GPS sensor when multiple modules are connected. It can prioritize the module with the best "fix" or blend the data from both modules.

## Tuning & Behavior
*   **Default Value:** 1 (Use Best)
*   **Values:** 0:Disabled, 1:Use Best, 2:Blend, 3:Use Primary, 4:Use Secondary