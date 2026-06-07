---
layout: parameter
name: SIM_TETH_ENABLE
display_name: Simulated Tether Enable
description: Enables the simulated tether physics model.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Tether.cpp#L25
---

# Simulated Tether Enable (SIM_TETH_ENABLE)

## Description
`SIM_TETH_ENABLE` simulates a physical cable attached to the drone.

This is used for testing tethered power systems. The simulator calculates the weight and drag of the cable as the drone flies higher, pulling it down and affecting its stability.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.