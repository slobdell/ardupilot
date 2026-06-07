---
layout: parameter
name: SIM_MAG3_OFS
display_name: Simulation Magnetometer 3 Offset
description: Adds a constant bias offset to the third simulated magnetometer.
default_value: 0
range: -100 100
units: mGauss
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L123
---

# Simulation Magnetometer 3 Offset (SIM_MAG3_OFS)

## Description
`SIM_MAG3_OFS` simulates hard-iron interference on the third compass.

See [SIM_MAG1_OFS](SIM_MAG1_OFS.html) for details.