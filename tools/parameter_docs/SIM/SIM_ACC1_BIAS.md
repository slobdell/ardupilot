---
layout: parameter
name: SIM_ACC1_BIAS
display_name: Simulation Accelerometer 1 Bias
description: Adds a constant bias offset (in m/s/s) to the first simulated accelerometer.
default_value: 0
range: -10 10
units: m/s/s
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L101
---

# Simulation Accelerometer 1 Bias (SIM_ACC1_BIAS)

## Description
`SIM_ACC1_BIAS` allows you to test how ArduPilot handles a "Drifty" sensor.

Real accelerometers always have a slight offset (e.g. they might report 0.1 m/s/s even when sitting perfectly level). ArduPilot calibrates this out during the "Accel Cal" process. By setting this parameter in SITL, you can intentionally introduce an error to verify that your calibration process or the EKF can handle it.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **0.5**. If you haven't performed an Accel Cal in the simulation, the drone will think it is tilted and try to roll away.