---
layout: parameter
name: SIM_MAG1_DIA
display_name: Simulation Magnetometer 1 Diagonal
description: Adds "Soft Iron" interference to the first simulated magnetometer using diagonal scaling.
default_value: 0
range: -0.2 0.2
units: 
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L107
---

# Simulation Magnetometer 1 Diagonal (SIM_MAG1_DIA)

## Description
`SIM_MAG1_DIA` simulates "Soft Iron" interference.

Soft iron effects are caused by materials that distort magnetic fields but are not themselves magnets (like iron or nickel). This distorts the magnetic "sphere" into an "ellipsoid." ArduPilot's advanced calibration routine calculates these diagonal scaling factors to fix this distortion.