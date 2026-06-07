---
layout: parameter
name: SIM_WAVE_SPEED
display_name: Simulated Wave Speed
description: The speed (in m/s) at which simulated waves move across the water surface.
default_value: 3
range: 0 20
units: m/s
group: SIM
visual_asset_id: sim_physics_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wave Speed (SIM_WAVE_SPEED)

## Description
`SIM_WAVE_SPEED` defines how fast the wave patterns move. 

## Tuning & Behavior
*   **Default Value:** 3 m/s.