---
layout: parameter
name: SIM_WIND_SPD
display_name: Simulation Wind Speed
description: The base wind speed (in m/s) simulated in the environment.
default_value: 0
range: 0 50
units: m/s
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulation Wind Speed (SIM_WIND_SPD)

## Description
`SIM_WIND_SPD` adds a constant wind to the simulation.

*   **0:** Calm day.
*   **10:** 10 m/s (22 mph) wind.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Essential for tuning `WPNAV_SPEED` and checking if your drone can hold position in high winds.