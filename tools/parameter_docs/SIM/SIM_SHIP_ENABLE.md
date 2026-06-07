---
layout: parameter
name: SIM_SHIP_ENABLE
display_name: Simulated Ship Enable
description: Enables the simulated ship physics model.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Ship.cpp#L25
---

# Simulated Ship Enable (SIM_SHIP_ENABLE)

## Description
`SIM_SHIP_ENABLE` places a large, moving ship in the simulation.

This is primarily used for testing "Ship Landing" logic. The ship has a helipad deck and moves along a pre-defined path or at a constant velocity.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.