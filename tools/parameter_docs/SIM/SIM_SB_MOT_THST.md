---
layout: parameter
name: SIM_SB_MOT_THST
display_name: Simulation Blimp Max Motor Thrust
description: The maximum thrust force (in Newtons) produced by one motor at 100% throttle.
default_value: 145
range: 0 1000
units: N
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L56
---

# Simulation Blimp Max Motor Thrust (SIM_SB_MOT_THST)

## Description
`SIM_SB_MOT_THST` defines the "Power" of the simulated propulsion system.

It represents the raw force (in Newtons) that a single motor/propeller unit generates when running at full throttle. This determines the blimp's maximum speed and its ability to fight against simulated wind.

## Tuning & Behavior
*   **Default:** 145 N.
*   **Conversion:** 1 Newton $\approx$ 102 grams of thrust.
*   **Usage:** Measure or calculate the peak thrust of your real motors and enter the equivalent Newtons here.