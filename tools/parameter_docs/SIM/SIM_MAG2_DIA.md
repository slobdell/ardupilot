---
layout: parameter
name: SIM_MAG2_DIA
display_name: Simulation Magnetometer 2 Diagonal
description: Adds "Soft Iron" interference to the second simulated magnetometer using diagonal scaling.
default_value: 0
range: -0.2 0.2
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L120
---

# Simulation Magnetometer 2 Diagonal (SIM_MAG2_DIA)

## Description
`SIM_MAG2_DIA` simulates a distorted magnetic field on the secondary compass.

See [SIM_MAG1_DIA](SIM_MAG1_DIA.html) for details.