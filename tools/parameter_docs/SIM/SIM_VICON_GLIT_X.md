---
layout: parameter
name: SIM_VICON_GLIT_X
display_name: Simulation Vicon Position Glitch X
description: Adds a constant position offset (in meters) to the simulated Vicon X position.
default_value: 0
range: -100 100
units: m
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L536
---

# Simulation Vicon Position Glitch X (SIM_VICON_GLIT_X)

## Description
`SIM_VICON_GLIT_X` injects a position error into the external vision system.

This is useful for testing how robust your indoor navigation is to sudden jumps in reported position (e.g. if the Vicon cameras lose calibration or the subject marker is partially occluded).
