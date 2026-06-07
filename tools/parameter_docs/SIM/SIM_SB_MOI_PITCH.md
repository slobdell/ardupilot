---
layout: parameter
name: SIM_SB_MOI_PITCH
display_name: Simulation Blimp Pitch Inertia
description: The rotational inertia (Moment of Inertia) around the Pitch (Y) axis.
default_value: 3050
range: 100 10000
units: kg*m^2
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L86
---

# Simulation Blimp Pitch Inertia (SIM_SB_MOI_PITCH)

## Description
`SIM_SB_MOI_PITCH` defines how hard it is to tilt the blimp's nose up or down.

Because blimps are very long, their mass is distributed far from the center of rotation. This results in a very high pitch inertia. This parameter simulates that "heavy" feel, meaning it takes significant thrust to start pitching the nose up, and equally significant thrust to stop it once it's moving.

## Tuning & Behavior
*   **Default:** 3050 $kg \cdot m^2$.
*   **Physics:** This value is typically much higher than the Roll Inertia (`SIM_SB_MOI_ROLL`) due to the elongated shape of the hull.
*   **Effect:** If this value is too low, the simulated blimp will be able to perform impossible aerobatic loops.