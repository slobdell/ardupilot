---
layout: parameter
name: SIM_ENGINE_MUL
display_name: Simulation Engine Multiplier
description: A multiplier applied to the thrust of a specific motor to simulate power loss or failure.
default_value: 1.0
range: 0 1.0
units: 
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L128
---

# Simulation Engine Multiplier (SIM_ENGINE_MUL)

## Description
`SIM_ENGINE_MUL` allows you to kill or weaken a motor in flight.

This is the primary tool for testing multirotor motor redundancy (e.g. Octocopter failure) or plane engine-out handling.

*   **1.0 (Default):** Full power.
*   **0.0:** Complete motor failure.
*   **0.5:** 50% power loss (damaged prop or ESC).

## Tuning & Behavior
*   **Usage:** You must also set `SIM_ENGINE_FAIL` to the motor number (0-indexed) you want to affect.
