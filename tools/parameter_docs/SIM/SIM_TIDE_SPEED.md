---
layout: parameter
name: SIM_TIDE_SPEED
display_name: Simulated Tide Speed
description: The speed (in m/s) of the simulated water current (tide).
default_value: 0
range: 0 5
units: m/s
group: SIM
visual_asset_id: sim_wind_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Tide Speed (SIM_TIDE_SPEED)

## Description
`SIM_TIDE_SPEED` simulates the "Wind of the Water."

For ArduRover (Boats) and ArduSub, this parameter adds a constant water current that pushes the vehicle in a specific direction. This is the primary way to test "Position Hold" and navigation robustness against currents.

## Tuning & Behavior
*   **Default Value:** 0 m/s.