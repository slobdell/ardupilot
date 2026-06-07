---
layout: parameter
name: SIM_OPOS_LNG
display_name: Simulated Original Position (Longitude)
description: The starting longitude (in degrees) for the vehicle in the simulator.
default_value: 149.165230
range: -180 180
units: deg
group: SIM
visual_asset_id: sim_gps_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Original Position (Longitude) (SIM_OPOS_LNG)

## Description
`SIM_OPOS_LNG` sets the starting longitude for the simulation.

## Tuning & Behavior
*   **Default Value:** 149.165230 (Canberra).