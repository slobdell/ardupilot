---
layout: parameter
name: CRUISE_SPEED
display_name: Target Cruise Speed
description: The target ground speed (in m/s) for the vehicle during autonomous missions and RTL.
default_value: 2.0
range: 0 100.0
units: m/s
group: CRUISE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp#L90
---

# Target Cruise Speed (CRUISE_SPEED)

## Description
`CRUISE_SPEED` is the "Default Speed Limit" for your Rover or Boat.

When you start an **Auto** mission or trigger a **Return to Launch (RTL)**, the autopilot will attempt to maintain this speed while navigating between waypoints. It acts as the primary velocity target for the cruise control system.

## Tuning & Behavior
*   **Default:** 2.0 m/s (approx 7.2 km/h).
*   **Recommendation:** Set this to a speed where your vehicle can still turn reliably and safely. 
*   **Physics:** This works in combination with [CRUISE_THROTTLE](CRUISE_THROTTLE.html) to establish the initial power level for the propulsion system.