---
layout: parameter
name: SIM_TIDE_DIR
display_name: Simulated Tide Direction
description: The direction (in degrees) the simulated water current is coming FROM.
default_value: 0
range: 0 360
units: deg
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Tide Direction (SIM_TIDE_DIR)

## Description
`SIM_TIDE_DIR` sets the compass bearing of the water current.

*   **0:** North current (pushing the boat towards South).
*   **180:** South current.