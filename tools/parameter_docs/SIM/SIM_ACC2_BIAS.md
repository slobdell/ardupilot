---
layout: parameter
name: SIM_ACC2_BIAS
display_name: Simulation Accelerometer 2 Bias
description: Adds a constant bias offset (in m/s/s) to the second simulated accelerometer.
default_value: 0
range: -10 10
units: m/s/s
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L102
---

# Simulation Accelerometer 2 Bias (SIM_ACC2_BIAS)

## Description
`SIM_ACC2_BIAS` simulates drift on the secondary accelerometer.

See [SIM_ACC1_BIAS](SIM_ACC1_BIAS.html) for details.