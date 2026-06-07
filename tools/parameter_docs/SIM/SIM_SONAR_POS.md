---
layout: parameter
name: SIM_SONAR_POS
display_name: Simulation Sonar Position
description: The physical offset (in meters) of the rangefinder (sonar/lidar) from the vehicle's center of gravity in the simulation.
default_value: 0
range: 0 5
units: m
group: SIM
visual_asset_id: imu_pos_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L118
---

# Simulation Sonar Position (SIM_SONAR_POS)

## Description
`SIM_SONAR_POS` defines the mounting location of the simulated rangefinder. Useful for testing terrain following and precise landing algorithms.