---
layout: parameter
name: CIRCLE_SPEED
display_name: Circle Speed (Rover)
description: Vehicle will move at this speed around the circle. If set to zero WP_SPEED will be used.
default_value: 0
range: 0 10
units: m/s
group: CIRCLE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/mode_circle.cpp
---

# Circle Speed (CIRCLE_SPEED)

## Description
Defines the linear velocity of the Rover while it is circling.
*   **0 uses the global waypoint speed (WP_SPEED).**