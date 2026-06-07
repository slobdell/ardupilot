---
layout: parameter
name: SIM_SB_DRAG_FWD
display_name: Simulation Blimp Forward Drag
description: The aerodynamic drag coefficient for motion along the blimp's longitudinal (X) axis.
default_value: 0.27
range: 0 5.0
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L61
---

# Simulation Blimp Forward Drag (SIM_SB_DRAG_FWD)

## Description
`SIM_SB_DRAG_FWD` defines how "Slippery" the blimp is when flying straight ahead.

A lower value means the blimp is more streamlined and will reach a higher top speed for a given motor thrust. A higher value simulates a blunter shape or more surface friction.

## Tuning & Behavior
*   **Default:** 0.27.
*   **Physics:** Drag force is calculated as $F_d = \frac{1}{2} \rho v^2 C_d A$. This parameter represents the combined $C_d A$ term (Coefficient of Drag $\times$ Frontal Area) for the forward direction.