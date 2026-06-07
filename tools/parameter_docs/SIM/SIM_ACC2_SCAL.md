---
layout: parameter
name: SIM_ACC2_SCAL
display_name: Simulation Accelerometer 2 Scale
description: Adds a scale factor error to the second simulated accelerometer.
default_value: 0
range: -0.1 0.1
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L126
---

# Simulation Accelerometer 2 Scale (SIM_ACC2_SCAL)

## Description
`SIM_ACC2_SCAL` simulates sensitivity errors on the secondary accelerometer.

See [SIM_ACC1_SCAL](SIM_ACC1_SCAL.html) for details.