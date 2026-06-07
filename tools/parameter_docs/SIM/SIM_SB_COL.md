---
layout: parameter
name: SIM_SB_COL
display_name: Simulation Blimp Center of Lift
description: The vertical distance between the center of lift and the center of gravity.
default_value: 2.54
range: 0 10
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L116
---

# Simulation Blimp Center of Lift (SIM_SB_COL)

## Description
`SIM_SB_COL` defines the physical offset between the buoyant center of the blimp's envelope (where it is pulled UP) and its center of gravity (where it is pulled DOWN).

In a stable blimp, the center of lift is usually high above the center of gravity (the gondola). This distance creates a "Pendulum Effect" that naturally keeps the blimp level. Increasing this value makes the blimp more stable but slower to pitch.

## Tuning & Behavior
*   **Default:** 2.54 meters.
*   **Physics:** A larger offset results in a stronger restoring torque when the blimp is tilted.
*   **Warning:** Setting this to 0 will make the blimp neutrally stable in pitch/roll, meaning it will stay at whatever angle it is pushed to.