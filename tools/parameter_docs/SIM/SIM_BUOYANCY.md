---
layout: parameter
name: SIM_BUOYANCY
display_name: Simulation Buoyancy
description: The net buoyancy force (in Newtons) acting on the vehicle. Specifically used for Submarine simulations.
default_value: 1
range: -100 100
units: N
group: SIM
visual_asset_id: physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L535
---

# Simulation Buoyancy (SIM_BUOYANCY)

## Description
`SIM_BUOYANCY` defines how much the simulated submarine wants to float or sink.

*   **Positive Value:** Net upwards force (Positive buoyancy). The sub floats to the surface.
*   **Negative Value:** Net downwards force (Negative buoyancy). The sub sinks to the bottom.
*   **0:** Neutral buoyancy. The sub stays at its current depth (Ideal for ROVs).

## Tuning & Behavior
*   **Testing:** Essential for tuning the vertical depth controller on ArduSub.