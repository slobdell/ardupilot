---
layout: parameter
name: WPNAV_SPEED_DN
display_name: Waypoint Vertical Speed Down
description: The default vertical descent rate (in cm/s) for autonomous flight modes.
default_value: 150
range: 0 500
units: cm/s
group: WPNAV
visual_asset_id: waypoint_speed_diagram
investigation_status: complete
---

# Waypoint Vertical Speed Down (WPNAV_SPEED_DN)

## Description
`WPNAV_SPEED_DN` controls how fast the drone drops when moving between waypoints.

*   **150 (Default):** 1.5 meters per second. 

## Tuning & Behavior
*   **Default Value:** 150 cm/s.
*   **Recommendation:** Keep lower than `WPNAV_SPEED_UP` to prevent the drone from falling into its own propwash (vortex ring state).
