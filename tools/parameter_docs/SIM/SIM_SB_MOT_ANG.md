---
layout: parameter
name: SIM_SB_MOT_ANG
display_name: Simulation Blimp Max Motor Angle
description: The maximum tilt angle (in degrees) for the blimp's vectored motors.
default_value: 20
range: 0 90
units: deg
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L110
---

# Simulation Blimp Max Motor Angle (SIM_SB_MOT_ANG)

## Description
`SIM_SB_MOT_ANG` defines the range of motion for the vectored thrust motors on the simulated **StratoBlimp**.

Unlike a standard drone, many blimps use motors that can tilt up or down to provide vertical lift or horizontal thrust. This parameter sets the maximum mechanical tilt angle that the simulator will model.

## Tuning & Behavior
*   **Default:** 20 degrees.
*   **Usage:** Set this to match the physical tilt range of your blimp's motor mounts.
*   **Physics:** This determines how much of the motor's thrust can be directed vertically for altitude control versus horizontally for forward speed.