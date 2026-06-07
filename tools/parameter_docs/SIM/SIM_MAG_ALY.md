---
layout: parameter
name: SIM_MAG_ALY
display_name: Simulation Magnetic Anomaly
description: Simulates a local magnetic disturbance (anomaly) in the environment.
default_value: 0
range: -100 100
units: mGauss
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L105
---

# Simulation Magnetic Anomaly (SIM_MAG_ALY)

## Description
`SIM_MAG_ALY` simulates flying over a large iron object (like a bridge or underground pipe).

Unlike `MAG_OFS`, which is attached to the drone, `MAG_ALY` is a disturbance in the "World" that only affects the drone when it is in a specific location. Useful for testing the EKF's resilience to sudden, external heading shifts.