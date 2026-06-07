---
layout: parameter
name: SIM_WAVE_DIR
display_name: Simulated Wave Direction
description: The direction (in degrees) the simulated waves are coming FROM.
default_value: 0
range: 0 360
units: deg
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Wave Direction (SIM_WAVE_DIR)

## Description
`SIM_WAVE_DIR` sets the compass bearing of the ocean swell.

*   **0:** North waves (moving towards South).
*   **90:** East waves.