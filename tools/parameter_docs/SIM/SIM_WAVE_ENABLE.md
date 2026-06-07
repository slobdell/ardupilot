---
layout: parameter
name: SIM_WAVE_ENABLE
display_name: Simulated Wave Enable
description: Enables the simulated wave physics model for boats and submarines.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wave Enable (SIM_WAVE_ENABLE)

## Description
`SIM_WAVE_ENABLE` adds "Ocean Swell" to the simulation.

When enabled, virtual boats will pitch and roll as they ride over simulated waves. This is essential for testing "Surface Stability" and verifying that the AHRS/EKF doesn't get disoriented by constant rocking.

## Tuning & Behavior
*   **0:** Disabled (Glassy water).
*   **1:** Enabled.