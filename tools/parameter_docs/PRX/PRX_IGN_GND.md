---
layout: parameter
name: PRX_IGN_GND
display_name: Proximity Ignore Ground
description: Enables logic to ignore proximity data that is within 1 meter of the ground, preventing false obstacle detections during takeoff and landing.
default_value: 0
range: 0 1
units: 
group: PRX
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Proximity/AP_Proximity.cpp#L40
---

# Proximity Ignore Ground (PRX_IGN_GND)

## Description
`PRX_IGN_GND` prevents the drone from being "Scared" of the floor.

When a drone is close to the ground, its Lidar often sees reflections from the dirt, grass, or landing pad as "Obstacles." This can prevent the drone from landing or cause it to jump away during takeoff. When enabled, this feature uses a downward rangefinder to determine exactly where the ground is and ignores any proximity data that is too close to that surface.
