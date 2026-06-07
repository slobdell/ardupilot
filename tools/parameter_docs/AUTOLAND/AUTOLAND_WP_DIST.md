---
layout: parameter
name: AUTOLAND_WP_DIST
display_name: Takeoff mode distance
description: This is the distance from the takeoff location where the plane will loiter. The loiter point will be in the direction of takeoff (the direction the plane is facing when the plane begins takeoff).
default_value: 200
range: 0 500
units: m
group: AUTOLAND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/mode_takeoff.cpp
---

# Takeoff mode distance (AUTOLAND_WP_DIST)

## Description
Defines the horizontal distance from the takeoff point to the designated loiter point where the aircraft will wait after completing the initial climb.

## Tuning & Behavior
*   **Default Value:** 200 m
*   **Range:** 0 to 500 m