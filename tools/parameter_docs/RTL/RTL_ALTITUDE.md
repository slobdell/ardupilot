---
layout: parameter
name: RTL_ALTITUDE
display_name: RTL Altitude
description: The target altitude (in meters above home) the aircraft will climb or descend to during a Return-to-Launch.
default_value: 15
range: -1 500
units: m
group: RTL
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# RTL Altitude (RTL_ALTITUDE)

## Description
`RTL_ALTITUDE` defines your "Safe Return Height." 

When the drone is commanded to Return-to-Launch (RTL), it will first check its current height. If it is below this value, it will climb to this altitude before starting the journey home. This ensures the drone flies over trees, buildings, and power lines instead of through them.

*   **-1:** Maintains the drone's current altitude (No climb or descent).
*   **0:** Drone will fly home at its current altitude.
*   **Value (m):** Target altitude above the takeoff point.

## Tuning & Behavior
*   **Default:** 15 meters.
*   **Recommendation:** Set this to at least **10 meters higher** than the tallest obstacle in your flight area.
*   **Note:** If the drone is already *above* this altitude when RTL is triggered, it will stay at that higher altitude while returning home (unless `RTL_CONE` logic is used).