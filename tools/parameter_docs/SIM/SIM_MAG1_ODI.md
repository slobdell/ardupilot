---
layout: parameter
name: SIM_MAG1_ODI
display_name: Simulation Magnetometer 1 Off-Diagonal
description: Adds complex "Soft Iron" interference to the first simulated magnetometer using off-diagonal terms.
default_value: 0
range: -0.2 0.2
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L108
---

# Simulation Magnetometer 1 Off-Diagonal (SIM_MAG1_ODI)

## Description
`SIM_MAG1_ODI` simulates complex magnetic distortions.

While `SIM_MAG1_DIA` scales the X, Y, and Z axes independently, `ODI` (Off-Diagonal) terms simulate how a magnetic field in one axis (e.g. X) can bleed into another axis (e.g. Y). This represents a highly non-linear or asymmetric magnetic environment.