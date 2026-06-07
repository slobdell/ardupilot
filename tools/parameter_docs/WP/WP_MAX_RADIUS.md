---
layout: parameter
name: WP_MAX_RADIUS
display_name: Waypoint Maximum Radius
description: Defines the maximum distance from a waypoint that the aircraft can be before it will skip to the next waypoint. This is useful for avoiding situations where the aircraft spends too much time trying to reach a waypoint that it is unable to reach due to wind or other factors. A value of zero disables this feature.
default_value: 0
range: 0 1000
units: m
group: WP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Waypoint Maximum Radius (WP_MAX_RADIUS)

## Description
Safety limit to prevent the aircraft from indefinitely circling a waypoint it cannot reach.

## Tuning & Behavior
*   **Default Value:** 0 m (Disabled)
*   **Range:** 0 1000 m