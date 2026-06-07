---
layout: parameter
name: SIM_SB_WVANE
display_name: Simulation Blimp Weathervane Offset
description: The distance (in meters) from the center of gravity to the center of lateral drag.
default_value: 0.3
range: -10 10
units: m
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L122
---

# Simulation Blimp Weathervane Offset (SIM_SB_WVANE)

## Description
`SIM_SB_WVANE` determines how strongly the **StratoBlimp** naturally points into the wind.

It represents the horizontal distance between the Center of Gravity (CoG) and the Center of Pressure (CoP) for side winds. 

*   **Positive Value:** Center of Drag is behind the Center of Mass. The blimp is stable and will naturally turn its nose into the wind (like a weather vane).
*   **Negative Value:** Center of Drag is in front of the Center of Mass. The blimp is unstable and will try to fly tail-first.

## Tuning & Behavior
*   **Default:** 0.3 meters.
*   **Physics:** A larger positive value means stronger directional stability but makes it harder for the motors to turn the blimp out of the wind.