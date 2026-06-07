---
layout: parameter
name: Q_WVANE_TAKEOFF
display_name: QuadPlane Weathervane Takeoff
description: Enables weathervaning during the takeoff phase (Q_LOITER takeoff or AUTO takeoff).
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervane Takeoff (Q_WVANE_TAKEOFF)

## Description
`Q_WVANE_TAKEOFF` allows the drone to yaw into the wind *while* it is climbing out.

*   **0:** Disabled (Heading locked until takeoff complete).
*   **1:** Enabled.

## Tuning & Behavior
*   **Default Value:** 0.