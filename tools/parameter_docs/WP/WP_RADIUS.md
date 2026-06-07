---
layout: parameter
name: WP_RADIUS
display_name: Waypoint Radius
description: Defines the maximum distance from a waypoint that when crossed indicates the waypoint may be complete. To avoid the aircraft looping around the waypoint in case it misses by more than the WP_RADIUS an additional check is made to see if the aircraft has crossed a "finish line" passing through the waypoint and perpendicular to the flight path from the previous waypoint.
default_value: 90
range: 1 12700
units: m
group: WP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Waypoint Radius (WP_RADIUS)

## Description
Defines the distance from a waypoint at which the aircraft considers the waypoint reached and transitions to the next leg of the mission.

## Tuning & Behavior
*   **Default Value:** 90 m (Plane), 200 cm (Copter - internal WPNAV_RADIUS)
*   **Range:** 1 to 12700 m
*   **A larger WP_RADIUS usually leads to smoother turns and better tracking in windy conditions.**