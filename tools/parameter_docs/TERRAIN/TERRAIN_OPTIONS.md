---
layout: parameter
name: TERRAIN_OPTIONS
display_name: Terrain System Options
description: Bitmask to control advanced terrain lookup behavior.
default_value: 0
range: 0 1
units: 
group: TERRAIN
visual_asset_id: terrain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Terrain/AP_Terrain.cpp#L63
---

# Terrain System Options (TERRAIN_OPTIONS)

## Description
`TERRAIN_OPTIONS` provides fine-grained control over how the terrain database is queried.

*   **Bit 0 (1): Disable Interpolation.** By default, the system smooths out the steps between grid points. Setting this bit forces the system to return the raw grid height, which is faster but "blocky."

## Tuning & Behavior
*   **Default:** 0 (Interpolation enabled).
*   **Recommendation:** Leave at **0** for smoother flight paths.