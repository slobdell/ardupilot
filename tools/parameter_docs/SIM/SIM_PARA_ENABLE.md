---
layout: parameter
name: SIM_PARA_ENABLE
display_name: Simulated Parachute Enable
description: Enables the simulated parachute release mechanism.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Parachute.cpp#L25
---

# Simulated Parachute Enable (SIM_PARA_ENABLE)

## Description
`SIM_PARA_ENABLE` adds a drag-inducing chute to the physics model.

When the parachute is "deployed" (via `SIM_PARA_PIN`), the drone's drag coefficient increases massively, causing it to drift down slowly rather than crash. This is vital for testing `CHUTE_` parameters and failsafe triggers.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.