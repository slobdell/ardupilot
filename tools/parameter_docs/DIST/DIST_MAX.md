---
layout: parameter
name: DIST_MAX
display_name: Follow distance maximum
description: Maximum distance at which a target will be followed. Targets further than this will be ignored.
default_value: 100
range: 1 1000
units: m
group: DIST
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Follow/AP_Follow.cpp
---

# Follow distance maximum (DIST_MAX)

## Description
Safety limit for Follow mode. If the target moves further away than this distance, the aircraft will stop following and typically enter Loiter or RTL to prevent a runaway scenario.

## Tuning & Behavior
*   **Default Value:** 100 m
*   **Range:** 1 to 1000 m
*   **Ensures the aircraft stays within a reasonable radio or visual range of the target.**