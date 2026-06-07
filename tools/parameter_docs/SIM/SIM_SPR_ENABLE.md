---
layout: parameter
name: SIM_SPR_ENABLE
display_name: Simulated Sprayer Enable
description: Enables the simulated crop sprayer physics (fluid mass reduction).
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Sprayer.cpp#L25
---

# Simulated Sprayer Enable (SIM_SPR_ENABLE)

## Description
`SIM_SPR_ENABLE` adds a liquid tank to the drone.

When the sprayer is active, the simulator slowly decreases the total mass of the drone, mimicking the fluid being pumped out. This allows you to test if your tuning holds up as the payload weight changes.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.