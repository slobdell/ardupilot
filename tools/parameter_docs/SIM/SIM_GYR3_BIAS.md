---
layout: parameter
name: SIM_GYR3_BIAS
display_name: Simulation Gyro 3 Bias
description: Adds a constant bias offset (in deg/s) to the third simulated gyroscope.
default_value: 0
range: -5 5
units: deg/s
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L133
---

# Simulation Gyro 3 Bias (SIM_GYR3_BIAS)

## Description
`SIM_GYR3_BIAS` simulates drift on the tertiary IMU.

See [SIM_GYR1_BIAS](SIM_GYR1_BIAS.html) for details.