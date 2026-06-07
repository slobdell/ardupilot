---
layout: parameter
name: SIM_VICON_YAW
display_name: Simulation Vicon Yaw Angle
description: The yaw angle (in degrees) reported by the simulated Vicon system.
default_value: 0
range: 0 360
units: deg
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L538
---

# Simulation Vicon Yaw Angle (SIM_VICON_YAW)

## Description
`SIM_VICON_YAW` defines the simulated orientation of the external position source. Useful for testing if the flight controller correctly integrates absolute heading data from a motion capture system.
