---
layout: parameter
name: SIM_SHOVE_Y
display_name: Simulation Shove Y
description: Applies a lateral force (in m/s/s or equivalent force units) to the vehicle to simulate a push or impact.
default_value: 0
range: -100 100
units: m/s/s
group: SIM
visual_asset_id: physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L235
---

# Simulation Shove Y (SIM_SHOVE_Y)

## Description
`SIM_SHOVE_Y` hits the drone from the side.

Unlike `SIM_WIND`, which is an aerodynamic force, `SHOVE` is a direct acceleration/force applied to the body.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **10** for 1 second, then back to **0**. This tests the drone's ability to recover from a hard collision or extreme gust.
