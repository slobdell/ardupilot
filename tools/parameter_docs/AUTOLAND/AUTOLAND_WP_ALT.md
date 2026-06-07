---
layout: parameter
name: AUTOLAND_WP_ALT
display_name: Takeoff mode altitude
description: This is the target altitude for TAKEOFF mode.
default_value: 50
range: 0 200
units: m
group: AUTOLAND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/mode_takeoff.cpp
---

# Takeoff mode altitude (AUTOLAND_WP_ALT)

## Description
Defines the target altitude for the aircraft to reach when in "Takeoff" mode.

## Tuning & Behavior
*   **Default Value:** 50 m
*   **Range:** 0 to 200 m