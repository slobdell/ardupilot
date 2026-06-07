---
layout: parameter
name: AVOID_ACCEL_MAX
display_name: Avoidance Max Acceleration
description: The maximum acceleration (in m/s/s) the vehicle will use to stop or slide to avoid an obstacle.
default_value: 3.0
range: 0 10
units: m/s/s
group: AVOID
visual_asset_id: avoid_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L104
---

# Avoidance Max Acceleration (AVOID_ACCEL_MAX)

## Description
`AVOID_ACCEL_MAX` limits how hard the drone brakes when it sees a wall.

If a proximity sensor detects an object within the `AVOID_DIST_MAX` limit, the autopilot commands the drone to stop. This parameter ensures the drone doesn't pitch back so violently that it crashes or destabilizes the payload.

## Tuning & Behavior
*   **Default Value:** 3.0 m/s/s.
*   **Recommendation:** Set to **1.0 or 2.0** for smoother braking on large, heavy cinema drones. Keep at **3.0** for smaller, agile quads.