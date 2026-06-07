---
layout: parameter
name: SIM_BARO_DRIFT
display_name: Simulated Barometer Drift
description: The rate at which the simulated barometer altitude drifts over time (in meters per second).
default_value: 0
range: 0 1.0
units: m/s
group: SIM
visual_asset_id: sim_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated Barometer Drift (SIM_BARO_DRIFT)

## Description
`SIM_BARO_DRIFT` simulates a barometer that is slowly losing calibration or being affected by changing weather pressure.

Real barometers drift as the weather changes (e.g., a storm front moving in). This parameter adds a constant vertical velocity error to the sensor.

## Tuning & Behavior
*   **Default Value:** 0 m/s.
*   **Recommendation:** Set to **0.1 m/s** to test if the EKF can use GPS vertical velocity to correct the baro drift.