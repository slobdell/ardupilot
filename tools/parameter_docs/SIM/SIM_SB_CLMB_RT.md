---
layout: parameter
name: SIM_SB_CLMB_RT
display_name: Simulation Blimp Target Climb Rate
description: The target vertical speed for the blimp during ascent.
default_value: 5
range: 0 50
units: m/s
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L98
---

# Simulation Blimp Target Climb Rate (SIM_SB_CLMB_RT)

## Description
`SIM_SB_CLMB_RT` defines the vertical speed the simulated **StratoBlimp** attempts to maintain while climbing toward its target altitude.

This parameter simulates the buoyancy-to-drag balance of the blimp's envelope. A higher value means the blimp has more lift or less aerodynamic drag in the vertical axis.

## Tuning & Behavior
*   **Default:** 5 m/s.
*   **Physics:** This value is used by the simulator's simplified physics model to calculate the vertical force needed to achieve the target rate.