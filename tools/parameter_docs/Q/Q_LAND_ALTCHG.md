---
layout: parameter
name: Q_LAND_ALTCHG
display_name: QuadPlane Land Altitude Change
description: Allows the vehicle to descend while approaching the landing point in VTOL mode.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Land Altitude Change (Q_LAND_ALTCHG)

## Description
`Q_LAND_ALTCHG` allows the drone to descend *while* it is traveling horizontally toward the landing spot.

*   **0 (Default):** The drone flies at `Q_RTL_ALT` to above the home point, stops, then descends vertically. Safe but slow.
*   **1 (Enabled):** The drone descends on a diagonal path. Faster, but requires clear airspace.

## Tuning & Behavior
*   **Default Value:** 0.