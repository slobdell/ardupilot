---
layout: parameter
name: SIM_SB_DRAG_SIDE
display_name: Simulation Blimp Lateral Drag
description: The aerodynamic drag coefficient for motion along the blimp's lateral (Y) axis.
default_value: 0.5
range: 0 5.0
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_StratoBlimp.cpp#L66
---

# Simulation Blimp Lateral Drag (SIM_SB_DRAG_SIDE)

## Description
`SIM_SB_DRAG_SIDE` simulates the air resistance the blimp encounters when moving sideways or drifting.

Because blimps are long and cigar-shaped, their side profile (Lateral Area) is much larger than their front profile. This means the drag from the side should be significantly higher than the forward drag. This parameter is critical for modeling how the blimp handles crosswinds.

## Tuning & Behavior
*   **Default:** 0.5.
*   **Physics:** This value is typically 2x to 5x higher than `SIM_SB_DRAG_FWD`.
*   **Effect:** If this value is too low, the simulated blimp will "slide" sideways too easily in turns.