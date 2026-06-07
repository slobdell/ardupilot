---
layout: parameter
name: DOCK_DIR
display_name: Docking Approach Direction
description: The compass heading (in degrees) from which the vehicle must approach the docking target.
default_value: -1
range: 0 360
units: deg
group: DOCK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/mode_dock.cpp#L22
---

# Docking Approach Direction (DOCK_DIR)

## Description
`DOCK_DIR` specifies the "Entry Vector" for autonomous docking.

Many docking stations (like a boat ramp or a specialized charging garage) can only be entered from one specific direction. If the rover approached from the wrong side, it would hit a wall or miss the latch. This parameter defines the required compass heading for the final approach leg.

*   **-1:** Unset / No specific direction required.
*   **0-360:** Compass heading (e.g. 90 = East).

## Tuning & Behavior
*   **Default:** -1.
*   **Usage:** Align your docking station and use a compass to find the required approach heading. The drone will automatically maneuver to line itself up with this vector before starting the final approach.