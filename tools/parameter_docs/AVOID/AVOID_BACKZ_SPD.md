---
layout: parameter
name: AVOID_BACKZ_SPD
display_name: Avoidance Backup Vertical Speed
description: The maximum vertical speed (in m/s) the vehicle will use to retreat vertically from an obstacle (e.g. ceiling or floor).
default_value: 0.75
range: 0 2
units: m/s
group: AVOID
visual_asset_id: avoid_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L107
---

# Avoidance Backup Vertical Speed (AVOID_BACKZ_SPD)

## Description
`AVOID_BACKZ_SPD` is the same as `AVOID_BACKUP_SPD` but for up/down movement.

If you fly too close to the ceiling (with an upward facing Lidar), this controls how fast the drone descends to regain clearance.

## Tuning & Behavior
*   **Default Value:** 0.75 m/s.
*   **Recommendation:** Keep conservative.