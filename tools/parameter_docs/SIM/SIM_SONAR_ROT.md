---
layout: parameter
name: SIM_SONAR_ROT
display_name: Simulation Sonar Rotation
description: The rotational orientation of the simulated rangefinder (e.g. facing Down, Forward, etc.).
default_value: 0
range: 0 35
units: 
group: SIM
visual_asset_id: imu_pos_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L119
---

# Simulation Sonar Rotation (SIM_SONAR_ROT)

## Description
`SIM_SONAR_ROT` sets the direction the simulated rangefinder is pointing.

*   **25:** Down (Standard for altimeters).
*   **0:** Forward (Standard for obstacle avoidance).