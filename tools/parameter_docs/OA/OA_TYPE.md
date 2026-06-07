---
layout: parameter
name: OA_TYPE
display_name: Object Avoidance Type
description: Selects the path planning algorithm for autonomous object avoidance.
default_value: 0
range: 0 4
units: 
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OAPathPlanner.cpp#L40
---

# Object Avoidance Type (OA_TYPE)

## Description
`OA_TYPE` activates the "Path Planner," which allows the drone to find its way around obstacles.

While standard avoidance ([AVOID_ENABLE](../AV/AVOID_ENABLE.html)) just stops the drone, the Object Avoidance (OA) system tries to calculate a new route around the obstacle to reach the target.

*   **0: Disabled.**
*   **1: BendyRuler.** A fast, reactive algorithm that "Peeks" left and right to find a gap. (Best for trees and pillars).
*   **2: Dijkstra.** A global planner that uses a pre-mapped "Fence" or "Database" of obstacles to find the shortest clear path. (Best for complex static environments).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Requirements:** Requires a functional proximity sensor (Lidar, Depth Camera) or a pre-loaded obstacle database.
*   **Reboot Required:** Yes.
