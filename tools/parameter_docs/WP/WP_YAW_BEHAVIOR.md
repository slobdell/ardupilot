---
layout: parameter
name: WP_YAW_BEHAVIOR
display_name: Waypoint Yaw Behavior
description: Determines the vehicle's heading (Yaw) during autonomous mission phases and RTL.
default_value: 1
range: 0 3
units: 
group: WP
visual_asset_id: waypoint_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Waypoint Yaw Behavior (WP_YAW_BEHAVIOR)

## Description
`WP_YAW_BEHAVIOR` tells the drone where to "Look" while it's flying a mission.

*   **0: Never Change.** The drone maintains whatever heading it had when the mission started.
*   **1: Face Next Waypoint (Default).** The drone always points its nose toward the destination waypoint. (Most natural for FPV and forward-flight performance).
*   **2: Face Next Waypoint except RTL.** Same as 1, but when returning home, the drone maintains its current heading.
*   **3: Face Along GPS Track.** The drone points in the direction it is physically moving.

## Tuning & Behavior
*   **Default:** 1.
*   **Recommendation:** Use **1 (Face Next Waypoint)** for most missions. If you are performing a mapping mission and want the camera to stay oriented in one direction regardless of the flight path, use **0 (Never Change)**.