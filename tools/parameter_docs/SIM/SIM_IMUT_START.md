---
layout: parameter
name: SIM_IMUT_START
display_name: Simulated IMU Start Temperature
description: The starting temperature (in degrees Celsius) for the simulated IMU thermal curve.
default_value: 25
range: -40 100
units: degC
group: SIM
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1101
---

# Simulated IMU Start Temperature (SIM_IMUT_START)

## Description
`SIM_IMUT_START` defines the "Ambient Temperature" when the simulator starts.

SITL can simulate the heating of the flight controller over time. This parameter sets the baseline. If you want to test how your drone handles a sub-zero cold start, you can set this to **-10**.

## Tuning & Behavior
*   **Default Value:** 25 °C.
*   **Usage:** Use this in conjunction with `SIM_IMUT_END` and `SIM_IMUT_TCONST` to create a thermal warm-up profile.