---
layout: parameter
name: OA_DB_SIZE
display_name: OADatabase Max Points
description: The maximum number of obstacles that can be stored in the object avoidance database.
default_value: 100
range: 0 10000
units: 
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OADatabase.cpp#L40
---

# OADatabase Max Points (OA_DB_SIZE)

## Description
`OA_DB_SIZE` sets the memory limit for the "Obstacle Memory."

When a drone uses a Lidar or Depth Camera, it sees thousands of points. The database filters these into a smaller list of distinct obstacles. This parameter determines how many of those obstacles the drone can remember at once.

*   **Higher Value:** Better for complex environments (like dense forests), but uses more CPU and RAM.
*   **Lower Value:** Safer for drones with limited processing power.

## Tuning & Behavior
*   **Default Value:** 100.
*   **Reboot Required:** Yes.