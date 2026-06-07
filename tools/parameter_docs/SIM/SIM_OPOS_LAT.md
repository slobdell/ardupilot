---
layout: parameter
name: SIM_OPOS_LAT
display_name: Simulated Original Position (Latitude)
description: The starting latitude (in degrees) for the vehicle in the simulator.
default_value: -35.363261
range: -90 90
units: deg
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Original Position (Latitude) (SIM_OPOS_LAT)

## Description
`SIM_OPOS_LAT` sets the home location where your drone spawns in the simulator.

*   **Default:** CMAC (Canberra Model Aircraft Club) in Australia.
*   **Usage:** Change this to your local flying field's coordinates to test missions in a familiar environment.

## Tuning & Behavior
*   **Default Value:** -35.363261 (Canberra).
*   **Recommendation:** Use a tool like Mission Planner's "Set Home" feature, which updates this parameter automatically.