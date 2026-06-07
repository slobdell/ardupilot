---
layout: parameter
name: SIM_GYR1_SCALE
display_name: Simulation Gyro 1 Scale
description: Adds a scale factor error to the first simulated gyroscope.
default_value: 0
range: -0.1 0.1
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L114
---

# Simulation Gyro 1 Scale (SIM_GYR1_SCALE)

## Description
`SIM_GYR1_SCALE` simulates a sensitivity error on the rotation axis.

If you rotate the drone by exactly 360 degrees, a sensor with a scale error might report 365 or 355 degrees. This is important for verifying high-rate aerobatic performance.