---
layout: parameter
name: SIM_SB_HMASS
display_name: Simulation Blimp Helium Mass
description: The mass (in kg) of the lifting gas contained within the blimp envelope.
default_value: 13.54
range: 0 1000
units: kg
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L44
---

# Simulation Blimp Helium Mass (SIM_SB_HMASS)

## Description
`SIM_SB_HMASS` simulates the weight of the lifting gas itself.

While helium is lighter than air, it still has mass. This parameter, combined with the envelope volume (implicit in the simulation's buoyancy logic), allows the physics engine to calculate the net lift and inertia of the airship.

## Tuning & Behavior
*   **Default:** 13.54 kg.
*   **Physics:** A larger mass of helium implies a larger envelope volume, which increases both lift and aerodynamic drag.