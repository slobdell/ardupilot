---
layout: parameter
name: OA_BR_CONT_ANGLE
display_name: BendyRuler Continuity Angle
description: The maximum change in bearing (in degrees) that is allowed without checking the continuity ratio.
default_value: 75
range: 0 180
units: deg
group: OA
visual_asset_id: avoid_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AP_OABendyRuler.cpp#L102
---

# BendyRuler Continuity Angle (OA_BR_CONT_ANGLE)

## Description
`OA_BR_CONT_ANGLE` defines a "Trust Zone" for small maneuvers.

If the path planner suggests a turn smaller than this angle, the drone will take it immediately. If the suggested turn is larger than this angle (e.g. a sharp 90-degree turn), the drone will only commit if the new path is significantly clearer (as defined by [OA_BR_CONT_RATIO](OA_BR_CONT_RATIO.html)). This keeps the drone's flight paths smooth and predictable.