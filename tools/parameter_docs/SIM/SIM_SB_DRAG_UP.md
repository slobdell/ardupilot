---
layout: parameter
name: SIM_SB_DRAG_UP
display_name: Simulation Blimp Vertical Drag
description: The aerodynamic drag coefficient for motion along the blimp's vertical (Z) axis.
default_value: 0.4
range: 0 5.0
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L71
---

# Simulation Blimp Vertical Drag (SIM_SB_DRAG_UP)

## Description
`SIM_SB_DRAG_UP` simulates the air resistance the blimp encounters when climbing or descending.

Because of the large horizontal surface area of a blimp's envelope (top and bottom), vertical drag is substantial. This parameter determines the terminal velocity for ascent (due to buoyancy) and descent.

## Tuning & Behavior
*   **Default:** 0.4.
*   **Physics:** This value balances against `SIM_SB_FLR` (Free Lift Rate). A higher drag coefficient means the blimp will ascend slower for the same amount of positive buoyancy.