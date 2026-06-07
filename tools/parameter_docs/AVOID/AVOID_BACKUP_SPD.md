---
layout: parameter
name: AVOID_BACKUP_SPD
display_name: Avoidance Backup Speed
description: The maximum speed (in m/s) the vehicle will reverse to retreat from an obstacle.
default_value: 0.75
range: 0 2
units: m/s
group: AVOID
visual_asset_id: avoid_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L98
---

# Avoidance Backup Speed (AVOID_BACKUP_SPD)

## Description
`AVOID_BACKUP_SPD` controls how fast the drone retreats.

If an obstacle moves towards the drone (or the drone drifts into it), the autopilot can actively fly backwards to maintain the `AVOID_DIST_MAX` clearance.

## Tuning & Behavior
*   **Default Value:** 0.75 m/s.
*   **Recommendation:** Keep low (0.5 - 1.0 m/s). You don't want the drone to bolt backwards into *another* obstacle that its rear sensors haven't seen yet.