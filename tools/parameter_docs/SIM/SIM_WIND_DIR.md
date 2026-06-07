---
layout: parameter
name: SIM_WIND_DIR
display_name: Simulation Wind Direction
description: The direction the wind is coming from (in degrees).
default_value: 180
range: 0 360
units: deg
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L101
---

# Simulation Wind Direction (SIM_WIND_DIR)

## Description
`SIM_WIND_DIR` sets the wind bearing.

*   **0:** North wind (Blows South).
*   **90:** East wind (Blows West).

## Tuning & Behavior
*   **Default Value:** 180 (South wind).
