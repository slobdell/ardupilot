---
layout: parameter
name: SIM_SB_FLR
display_name: Simulation Blimp Free Lift Rate
description: The ratio of excess lift provided by the helper balloon relative to neutral buoyancy.
default_value: 0.12
range: 0 1.0
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L127
---

# Simulation Blimp Free Lift Rate (SIM_SB_FLR)

## Description
`SIM_SB_FLR` simulates the "Positive Buoyancy Bias" often used in stratospheric balloon missions.

Many high-altitude airships are designed to be slightly lighter than air so they naturally ascend without using motor power. This parameter defines how much extra lift is available.

*   **0.0:** Perfectly neutrally buoyant (will float at current altitude).
*   **0.12 (Default):** 12% excess lift. The blimp will ascend automatically.

## Tuning & Behavior
*   **Default:** 0.12.
*   **Physics:** This excess lift must be counteracted by downward thrust from the motors if the blimp needs to hold altitude or descend.