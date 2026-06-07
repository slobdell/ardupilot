---
layout: parameter
name: DOCK_SPEED
display_name: Dock Mode Speed Limit
description: The maximum allowed speed for the vehicle during the autonomous docking sequence.
default_value: 0
range: 0 100
units: m/s
group: DOCK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/mode_dock.cpp#L13
---

# Dock Mode Speed Limit (DOCK_SPEED)

## Description
`DOCK_SPEED` sets the "Approach Velocity" for autonomous docking.

In **Dock** mode (used for Rovers and Boats), the vehicle navigates to a precise coordinate or a MAVLink beacon to dock for charging or recovery. Because this requires high precision and safety, this parameter caps the speed to ensure the vehicle doesn't "over-shoot" the dock or cause a collision.

## Tuning & Behavior
*   **Default:** 0 (Uses the vehicle's standard cruise speed).
*   **Recommendation:** Set to a very low value (e.g. **0.5 m/s** or **1.0 m/s**) to ensure a safe and controlled approach.
*   **Significance:** Slower speeds allow the position control loops more time to react to external disturbances (like currents or uneven ground) as the drone enters the final docking phase.