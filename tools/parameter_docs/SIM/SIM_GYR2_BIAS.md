---
layout: parameter
name: SIM_GYR2_BIAS
display_name: Simulation Gyro 2 Bias
description: Adds a constant bias offset (in deg/s) to the second simulated gyroscope.
default_value: 0
range: -5 5
units: deg/s
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L132
---

# Simulation Gyro 2 Bias (SIM_GYR2_BIAS)

## Description
`SIM_GYR2_BIAS` simulates drift on the secondary IMU.

See [SIM_GYR1_BIAS](SIM_GYR1_BIAS.html) for details.