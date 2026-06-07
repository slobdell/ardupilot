---
layout: parameter
name: WPNAV_SPEED_UP
display_name: Waypoint Vertical Speed Up
description: The default vertical climb rate (in cm/s) for autonomous flight modes.
default_value: 250
range: 0 1000
units: cm/s
group: WPNAV
visual_asset_id: waypoint_speed_diagram
investigation_status: complete
---

# Waypoint Vertical Speed Up (WPNAV_SPEED_UP)

## Description
`WPNAV_SPEED_UP` controls how fast the drone climbs when moving between waypoints of different altitudes.

*   **250 (Default):** 2.5 meters per second. 

## Tuning & Behavior
*   **Default Value:** 250 cm/s.
*   **Recommendation:** Keep at or below **250** to avoid overwhelming the vertical controller.
