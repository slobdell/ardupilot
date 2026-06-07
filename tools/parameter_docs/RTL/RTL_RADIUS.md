---
layout: parameter
name: RTL_RADIUS
display_name: RTL Loiter Radius
description: The radius (in meters) of the loiter circle when the aircraft returns home.
default_value: 0
range: 0 500
units: m
group: RTL
visual_asset_id: plane_loiter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L100
---

# RTL Loiter Radius (RTL_RADIUS)

## Description
`RTL_RADIUS` defines how tight the plane circles when it gets home.

*   **0 (Default):** Use `WP_LOITER_RAD`.
*   **> 0:** Use this specific radius for RTL only.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Keep at **0** to ensure consistent behavior with standard loiter modes.