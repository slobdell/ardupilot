---
layout: parameter
name: SIM_SB_YAW_RT
display_name: Simulation Blimp Max Yaw Rate
description: The maximum rotation rate (in deg/s) for the blimp's yaw axis.
default_value: 60
range: 0 360
units: deg/s
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L104
---

# Simulation Blimp Max Yaw Rate (SIM_SB_YAW_RT)

## Description
`SIM_SB_YAW_RT` sets the "Turning Speed" limit for the simulated **StratoBlimp**.

It defines how many degrees per second the blimp will rotate when the motor outputs are fully differential (full left/right stick). This allows developers to simulate the sluggish turning characteristics of large blimps or the highly maneuverable response of small electric airships.

## Tuning & Behavior
*   **Default:** 60 deg/s.
*   **Physics:** This parameter determines the effective yaw torque produced by the motors in the simulator's physics model.