---
layout: parameter
name: SIM_VICON_VGLI_Z
display_name: Simulation Vicon Velocity Glitch Z
description: Adds a constant velocity offset (in m/s) to the simulated Vicon Z velocity reading.
default_value: 0
range: -10 10
units: m/s
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L541
---

# Simulation Vicon Velocity Glitch Z (SIM_VICON_VGLI_Z)

## Description
`SIM_VICON_VGLI_Z` injects a vertical velocity error into the simulated external vision system.
