---
layout: parameter
name: SIM_VICON_VGLI_X
display_name: Simulation Vicon Velocity Glitch X
description: Adds a constant velocity offset (in m/s) to the simulated Vicon velocity reading.
default_value: 0
range: -10 10
units: m/s
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L541
---

# Simulation Vicon Velocity Glitch X (SIM_VICON_VGLI_X)

## Description
`SIM_VICON_VGLI_X` injects a velocity error into the external vision system.

This tests if the EKF can handle a Vicon system that reports a constant drift in speed (e.g. due to lighting changes or high-speed blur).
