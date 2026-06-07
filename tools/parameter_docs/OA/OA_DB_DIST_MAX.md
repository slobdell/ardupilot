---
layout: parameter
name: OA_DB_DIST_MAX
display_name: OADatabase Max Distance
description: The maximum distance (in meters) to track obstacles. Any detected objects beyond this distance are ignored.
default_value: 0
range: 0 100
units: m
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OADatabase.cpp#L93
---

# OADatabase Max Distance (OA_DB_DIST_MAX)

## Description
`OA_DB_DIST_MAX` sets the "Horizon" for obstacle avoidance.

Detection sensors often have long ranges, but their accuracy decreases with distance. By setting a max distance (e.g. 10m), you ensure that the autopilot only maneuvers for obstacles that are close enough to be accurately positioned and pose a real threat.

*   **0 (Default):** No limit. All detected points are added to the database.