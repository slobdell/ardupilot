---
layout: parameter
name: Q_WVANE_HGT_MIN
display_name: QuadPlane Weathervane Min Height
description: The minimum altitude (in meters) above home required to activate weathervaning.
default_value: 0
range: 0 50
units: m
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervane Min Height (Q_WVANE_HGT_MIN)

## Description
`Q_WVANE_HGT_MIN` keeps the heading locked during takeoff.

You generally want the drone to launch straight up without twisting. Once it clears the ground obstacles (e.g. 5 meters up), it is safe to turn into the wind.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **2 or 3 meters**.