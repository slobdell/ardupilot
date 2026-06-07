---
layout: parameter
name: Q_WVANE_ENABLE
display_name: QuadPlane Weathervaning Enable
description: Master switch to enable automatic weathervaning (turning into the wind) while hovering.
default_value: 0
range: 0 4
units: 
group: Q
visual_asset_id: vtol_weathervane_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# QuadPlane Weathervaning Enable (Q_WVANE_ENABLE)

## Description
`Q_WVANE_ENABLE` allows the drone to passively turn its nose into the wind while hovering.

Weathervaning reduces the workload on the roll/pitch motors. By pointing into the wind, the drone is more aerodynamic and uses less battery.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Nose into wind (Yaw only).
*   **2:** Nose or Tail into wind (Yaw only).
*   **3:** Nose into wind (Yaw + Roll).
*   **4:** Nose or Tail into wind (Yaw + Roll).

## Recommendation
Use **1** for standard QuadPlanes. Use **0** if you need precise heading control for photography.