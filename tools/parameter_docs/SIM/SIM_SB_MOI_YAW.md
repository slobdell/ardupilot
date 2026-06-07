---
layout: parameter
name: SIM_SB_MOI_YAW
display_name: Simulation Blimp Yaw Inertia
description: The rotational inertia (Moment of Inertia) around the Yaw (Z) axis.
default_value: 2800
range: 100 10000
units: kg*m^2
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L76
---

# Simulation Blimp Yaw Inertia (SIM_SB_MOI_YAW)

## Description
`SIM_SB_MOI_YAW` defines how hard it is to turn the blimp left or right.

Like pitch inertia, yaw inertia is high for blimps because of their length. This parameter simulates the "resistance to turning" that pilot's feel. A high value means the blimp will be slow to start turning, but will also coast through the turn and be slow to stop spinning once the motors are centered.

## Tuning & Behavior
*   **Default:** 2800 $kg \cdot m^2$.
*   **Physics:** This value dictates the responsiveness of the heading control loop.
*   **Effect:** If this value is too high, the blimp will feel "sluggish" and may overshoot its target heading. If too low, it will turn unrealistically fast.