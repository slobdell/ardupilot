---
layout: parameter
name: OA_BR_LOOKAHEAD
display_name: BendyRuler Lookahead
description: The distance (in meters) the BendyRuler algorithm looks ahead to find paths and obstacles.
default_value: 5.0
range: 1 20
units: m
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OABendyRuler.cpp#L100
---

# BendyRuler Lookahead (OA_BR_LOOKAHEAD)

## Description
`OA_BR_LOOKAHEAD` defines the "Vision Range" of the reactive path planner.

BendyRuler peeks ahead of the drone to see if the current path is blocked. If it sees an obstacle within this distance, it starts checking alternative "Probes" (slightly left, slightly right) to see if there's a clear gap.

*   **Higher Value:** Earlier reactions to obstacles. Better for high-speed flight.
*   **Lower Value:** Later reactions. Allows the drone to get closer to objects before maneuvering.