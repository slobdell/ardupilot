---
layout: parameter
name: SIM_ACC3_BIAS
display_name: Simulation Accelerometer 3 Bias
description: Adds a constant bias offset (in m/s/s) to the third simulated accelerometer.
default_value: 0
range: -10 10
units: m/s/s
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L103
---

# Simulation Accelerometer 3 Bias (SIM_ACC3_BIAS)

## Description
`SIM_ACC3_BIAS` simulates drift on the tertiary IMU.

See [SIM_ACC1_BIAS](SIM_ACC1_BIAS.html) for details.