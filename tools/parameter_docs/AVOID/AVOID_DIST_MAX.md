---
layout: parameter
name: AVOID_DIST_MAX
display_name: Avoidance Max Distance
description: The distance (in meters) from an obstacle at which the vehicle will start braking to ensure it stops before hitting the AVOID_MARGIN.
default_value: 5
range: 1 20
units: m
group: AVOID
visual_asset_id: avoid_logic_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L92
---

# Avoidance Max Distance (AVOID_DIST_MAX)

## Description
`AVOID_DIST_MAX` defines the "Reaction Zone."

When an object is further away than this, the drone ignores it. Once it enters this range, the drone starts calculating if it needs to brake. This is effectively the range of your sensor that you *trust* for avoidance logic.

## Tuning & Behavior
*   **Default Value:** 5 meters.
*   **Recommendation:** Set to **80%** of your Lidar's reliable range.
    *   **TFmini:** 4m.
    *   **LIDAR-Lite:** 10m.
    *   **Lightware SF40:** 20m.