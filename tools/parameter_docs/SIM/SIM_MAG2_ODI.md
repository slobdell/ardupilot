---
layout: parameter
name: SIM_MAG2_ODI
display_name: Simulation Magnetometer 2 Off-Diagonal
description: Adds complex "Soft Iron" interference to the second simulated magnetometer using off-diagonal terms.
default_value: 0
range: -0.2 0.2
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L121
---

# Simulation Magnetometer 2 Off-Diagonal (SIM_MAG2_ODI)

## Description
`SIM_MAG2_ODI` simulates complex magnetic twisting on the secondary compass.

See [SIM_MAG1_ODI](SIM_MAG1_ODI.html) for details.