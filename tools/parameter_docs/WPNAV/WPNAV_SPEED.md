---
layout: parameter
name: WPNAV_SPEED
display_name: Waypoint Horizontal Speed
description: The default horizontal velocity (in cm/s) for autonomous flight modes (AUTO, GUIDED, RTL).
default_value: 500
range: 0 2000
units: cm/s
group: WPNAV
visual_asset_id: waypoint_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L100
---

# Waypoint Horizontal Speed (WPNAV_SPEED)

## Description
`WPNAV_SPEED` sets the "Cruise Speed" for your autonomous missions.

*   **500 (Default):** 5 meters per second (11 mph). Good for stable surveying.
*   **1000:** 10 m/s (22 mph). Faster transit.

## Tuning & Behavior
*   **Default Value:** 500 cm/s.
*   **Recommendation:** Set based on your drone's power and the requirements of your mission.
