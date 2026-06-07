---
layout: parameter
name: SIM_IMUT_FIXED
display_name: Simulated IMU Fixed Temperature
description: Sets a fixed, constant temperature (in degrees Celsius) for the simulated IMU.
default_value: 0
range: -40 100
units: degC
group: SIM
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L440
---

# Simulated IMU Fixed Temperature (SIM_IMUT_FIXED)

## Description
`SIM_IMUT_FIXED` forces the virtual IMU to stay at a specific temperature.

If set to a non-zero value, the IMU temperature will not follow the curve defined by `SIM_IMUT_START` and `SIM_IMUT_END`. This is useful for testing sensor bias at a specific operating point without waiting for the heat-up cycle.

## Tuning & Behavior
*   **0:** Disabled (Use dynamic thermal curve).
*   **Non-Zero:** Fixed temperature in Celsius.