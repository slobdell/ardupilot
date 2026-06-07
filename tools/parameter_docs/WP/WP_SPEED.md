---
layout: parameter
name: WP_SPEED
display_name: Waypoint Speed (Default)
description: The default speed (in m/s) the vehicle will travel between waypoints during a mission.
default_value: 2.0
range: 0 100
units: m/s
group: WP
visual_asset_id: waypoint_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AR_WPNav/AR_WPNav.cpp#L47
---

# Waypoint Speed (WP_SPEED)

## Description
`WP_SPEED` sets the "Cruise Control" for your vehicle during an autonomous mission. 

It defines how fast the drone or rover attempts to travel between waypoints. Individual waypoints can have their own speed settings in the mission file, but `WP_SPEED` is the value used if no specific speed is provided.

*   **Standard Setting:** 2.0 m/s to 5.0 m/s for Rovers. 5.0 m/s to 15.0 m/s for Multicopters.

## Tuning & Behavior
*   **Default:** 2.0 m/s.
*   **Recommendation:** Set this to a speed that allows your vehicle to maneuver comfortably. If the vehicle "overshoots" waypoints or oscillates at high speed, reduce this value or increase [WP_RADIUS](WP_RADIUS.html).
*   **Dynamic Adjustment:** You can change this speed in real-time during a mission using a MAVLink "Change Speed" command from the GCS.