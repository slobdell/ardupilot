---
layout: parameter
name: OA_MARGIN_MAX
display_name: Object Avoidance Margin
description: The minimum distance (in meters) the drone must maintain from any detected obstacle during path planning.
default_value: 2.0
range: 0.1 10.0
units: m
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OAPathPlanner.cpp#L41
---

# Object Avoidance Margin (OA_MARGIN_MAX)

## Description
`OA_MARGIN_MAX` defines the "Safety Buffer" around obstacles.

When the path planner calculates a route around a tree or building, it will ensure that the drone never comes closer than this many meters to the object.

*   **Higher Value:** Safer, but the drone might refuse to fly through narrow gaps (like a doorway).
*   **Lower Value:** The drone will fly much closer to objects, allowing for tighter maneuvers.

## Tuning & Behavior
*   **Default Value:** 2.0m.
*   **Recommendation:** Set this to at least **2 times** the radius of your drone (including propellers) for safety.
