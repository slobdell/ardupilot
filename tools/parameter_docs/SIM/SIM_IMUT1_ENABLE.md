---
layout: parameter
name: SIM_IMUT1_ENABLE
display_name: Simulated IMU 1 Thermal Enable
description: Enables the simulated thermal drift for the first IMU.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1101
---

# Simulated IMU 1 Thermal Enable (SIM_IMUT1_ENABLE)

## Description
`SIM_IMUT1_ENABLE` activates the simulated heat-up process for the first IMU.

When enabled, the IMU's reported temperature will follow the curve defined by `SIM_IMUT_START`, `END`, and `TCONST`. This is useful for verifying that your `INS_TCAL1_` parameters (learned during a real temp cal) correctly remove the bias drift in the simulator.

## Tuning & Behavior
*   **0:** Disabled (IMU stays at constant temperature).
*   **1:** Enabled.