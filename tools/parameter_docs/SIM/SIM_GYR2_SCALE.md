---
layout: parameter
name: SIM_GYR2_SCALE
display_name: Simulation Gyro 2 Scale
description: Adds a scale factor error to the second simulated gyroscope.
default_value: 0
range: -0.1 0.1
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L115
---

# Simulation Gyro 2 Scale (SIM_GYR2_SCALE)

## Description
`SIM_GYR2_SCALE` simulates sensitivity errors on the secondary IMU.

See [SIM_GYR1_SCALE](SIM_GYR1_SCALE.html) for details.