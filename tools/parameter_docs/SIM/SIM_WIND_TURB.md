---
layout: parameter
name: SIM_WIND_TURB
display_name: Simulation Wind Turbulence
description: The amount of random turbulence added to the wind.
default_value: 0
range: 0 50
units: m/s
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L102
---

# Simulation Wind Turbulence (SIM_WIND_TURB)

## Description
`SIM_WIND_TURB` makes the wind gusty.

*   **0:** Steady laminar flow.
*   **5:** Gusts +/- 5 m/s.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Use this to tune your Rate D-Term and Position Controller responsiveness.