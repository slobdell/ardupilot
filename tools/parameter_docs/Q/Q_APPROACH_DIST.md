---
layout: parameter
name: Q_APPROACH_DIST
display_name: QuadPlane Approach Distance
description: The distance (in meters) from the landing point where the vehicle begins its VTOL approach transition.
default_value: 0
range: 0 1000
units: m
group: Q
visual_asset_id: vtol_land_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Approach Distance (Q_APPROACH_DIST)

## Description
`Q_APPROACH_DIST` sets the "Braking Zone" for autonomous VTOL landings.

As the plane flies towards the landing spot at cruise speed, it needs to slow down and start the VTOL motors. This parameter tells the plane how far out it should start that process.

*   **0 (Default):** The plane uses a calculated distance based on its current speed and `Q_TRANSITION_MS`.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Set to **50-100m** if you want consistent, repeatable landing paths.