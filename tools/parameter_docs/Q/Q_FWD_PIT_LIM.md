---
layout: parameter
name: Q_FWD_PIT_LIM
display_name: QuadPlane Forward Pitch Limit
description: The maximum pitch down angle (in degrees) allowed when the forward motor is active in VTOL modes.
default_value: 5
range: 0 15
units: deg
group: Q
visual_asset_id: vtol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Forward Pitch Limit (Q_FWD_PIT_LIM)

## Description
`Q_FWD_PIT_LIM` restricts how much the nose can dip when `Q_FWD_THR_USE` is active.

Since the forward motor is doing the work of fighting the wind, the drone doesn't need to tilt much. Keeping the fuselage level (near 0 pitch) reduces drag and makes the drone more stable.

## Tuning & Behavior
*   **Default Value:** 5 degrees.
*   **Recommendation:** Keep small (3-8 degrees).