---
layout: parameter
name: GLIDE_SLOPE_MIN
display_name: Glide Slope Minimum Altitude
description: The minimum altitude difference between waypoints required to trigger a calculated glide slope.
default_value: 15
range: 0 1000
units: m
group: GLIDE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L98
---

# Glide Slope Minimum Altitude (GLIDE_SLOPE_MIN)

## Description
`GLIDE_SLOPE_MIN` controls how "Smoothly" your plane changes altitude between mission waypoints.

If you have two waypoints with a very small altitude difference (e.g. 5 meters), it might be better to just climb instantly rather than calculating a long, shallow glide slope. This parameter sets that cutoff point.

*   **0:** Glide slope logic is always used (or disabled, depending on vehicle).
*   **15 (Default):** If the altitude change is less than 15 meters, the plane will try to reach the new altitude as quickly as possible. If it's more than 15 meters, it will calculate a straight line (slope) between the points and follow it precisely.

## Tuning & Behavior
*   **Usage:** Increase this value if you find your plane "hunting" for altitude during slight variations in terrain-following or waypoint missions.