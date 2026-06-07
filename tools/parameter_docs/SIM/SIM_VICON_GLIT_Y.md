---
layout: parameter
name: SIM_VICON_GLIT_Y
display_name: Simulation Vicon Position Glitch Y
description: Adds a constant position offset (in meters) to the simulated Vicon Y position.
default_value: 0
range: -100 100
units: m
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L536
---

# Simulation Vicon Position Glitch Y (SIM_VICON_GLIT_Y)

## Description
`SIM_VICON_GLIT_Y` injects a lateral position error into the simulated external vision system.

See [SIM_VICON_GLIT_X](SIM_VICON_GLIT_X.html) for details.
