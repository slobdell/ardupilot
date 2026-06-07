---
layout: parameter
name: SIM_SAIL_TYPE
display_name: Simulation Sailboat Type
description: Selects the rigging and hull configuration for the simulated sailboat.
default_value: 0
range: 0 5
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Sailboat.cpp#L25
---

# Simulation Sailboat Type (SIM_SAIL_TYPE)

## Description
`SIM_SAIL_TYPE` tells the physics engine which kind of wind-powered boat to simulate.

*   **0: Mono-hull.** Standard sailboat.
*   **1: Catamaran.**
*   **2: Wingsail.** High-efficiency rigid sail.