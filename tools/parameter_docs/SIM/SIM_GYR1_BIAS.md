---
layout: parameter
name: SIM_GYR1_BIAS
display_name: Simulation Gyro 1 Bias
description: Adds a constant bias offset (in deg/s) to the first simulated gyroscope.
default_value: 0
range: -5 5
units: deg/s
group: SIM
visual_asset_id: sim_sensor_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L131
---

# Simulation Gyro 1 Bias (SIM_GYR1_BIAS)

## Description
`SIM_GYR1_BIAS` simulates "Gyro Drift."

Real-world gyroscopes are sensitive to temperature and time. If you leave a drone sitting on a table, the reported rotation rate might not be exactly zero. This drift is the primary cause of "Horizon Tilt" in flight. ArduPilot's EKF is designed to learn and cancel this drift.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Testing:** Set to **1.0** (1 degree per second). You can watch the EKF "innovations" in your logs as the autopilot detects and attempts to compensate for this fake drift.