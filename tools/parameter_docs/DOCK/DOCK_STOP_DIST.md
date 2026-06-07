---
layout: parameter
name: DOCK_STOP_DIST
display_name: Docking Target Stop Distance
description: The distance (in meters) from the target at which the vehicle begins to brake and come to a complete halt.
default_value: 0.3
range: 0 2.0
units: m
group: DOCK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/mode_dock.cpp#L46
---

# Docking Target Stop Distance (DOCK_STOP_DIST)

## Description
`DOCK_STOP_DIST` defines the "Final Proximity" for a successful dock.

This parameter tells the autopilot exactly when to call the mission "Complete" and shut down the motors. Because real-world vehicles have momentum, this sets the point at which the braking logic triggers to ensure the vehicle stops exactly at the target.

## Tuning & Behavior
*   **Default:** 0.3 meters (30 cm).
*   **Calibration:** If your rover consistently hits the docking station too hard, increase this value. If it stops too far away and fails to engage the charging pins, decrease it.
*   **Accuracy:** This requires a highly accurate position estimate (e.g. RTK GPS or a specialized docking beacon).