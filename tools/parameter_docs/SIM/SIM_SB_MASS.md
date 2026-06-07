---
layout: parameter
name: SIM_SB_MASS
display_name: Simulation Blimp Mass
description: The total mass (in kilograms) of the simulated StratoBlimp aircraft.
default_value: 80
range: 1 500
units: kg
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_StratoBlimp.cpp#L10
---

# Simulation Blimp Mass (SIM_SB_MASS)

## Description
`SIM_SB_MASS` defines the weight of the virtual blimp used in the **StratoBlimp** simulation.

This parameter directly affects the physics engine, influencing how much buoyancy (Helium) is needed to stay airborne and how the blimp reacts to motor thrust and wind.
