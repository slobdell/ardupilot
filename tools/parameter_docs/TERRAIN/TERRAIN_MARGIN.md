---
layout: parameter
name: TERRAIN_MARGIN
display_name: Terrain Data Acceptance Margin
description: The tolerance (in meters) for grid alignment errors when receiving terrain data from the GCS.
default_value: 0.05
range: 0 5.0
units: m
group: TERRAIN
visual_asset_id: terrain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Terrain/AP_Terrain.cpp#L71
---

# Terrain Data Acceptance Margin (TERRAIN_MARGIN)

## Description
`TERRAIN_MARGIN` is a compatibility setting for older terrain databases.

ArduPilot expects terrain grid points to be aligned perfectly to specific latitude/longitude intervals. If the GCS sends data that is slightly shifted (due to floating point rounding errors in older software), this margin allows the autopilot to accept it anyway.

## Tuning & Behavior
*   **Default:** 0.05 m (5 cm).
*   **Recommendation:** Leave at default. Modern Mission Planner and MAVProxy versions do not require adjustment.