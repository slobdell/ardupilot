---
layout: parameter
name: SIM_SB_MOI_ROLL
display_name: Simulation Blimp Roll Inertia
description: The rotational inertia (Moment of Inertia) around the Roll (X) axis.
default_value: 1400
range: 100 10000
units: kg*m^2
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L81
---

# Simulation Blimp Roll Inertia (SIM_SB_MOI_ROLL)

## Description
`SIM_SB_MOI_ROLL` defines how hard it is to tilt the blimp side-to-side.

A blimp with a high roll inertia is very stable and resists being rocked by turbulence, but it takes a lot of force to bank into a turn. A low roll inertia makes the blimp feel "twitchy" and unstable.

## Tuning & Behavior
*   **Default:** 1400 $kg \cdot m^2$.
*   **Physics:** This value is derived from the mass distribution of the envelope and gondola. Since most of the mass is concentrated low (in the gondola), the roll inertia is typically lower than the pitch or yaw inertia.