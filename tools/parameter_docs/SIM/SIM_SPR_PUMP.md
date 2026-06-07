---
layout: parameter
name: SIM_SPR_PUMP
display_name: Simulated Sprayer Pump Rate
description: The rate (in liters/second or kg/s) at which the sprayer pump depletes the payload.
default_value: 0
range: 0 10
units: L/s
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SIM_Sprayer.cpp#L25
---

# Simulated Sprayer Pump Rate (SIM_SPR_PUMP)

## Description
`SIM_SPR_PUMP` sets how fast the tank empties.

## Tuning & Behavior
*   **Default Value:** 0.