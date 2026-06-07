---
layout: parameter
name: SIM_IMUT_END
display_name: Simulated IMU Final Temperature
description: The final steady-state temperature (in degrees Celsius) for the simulated IMU thermal curve.
default_value: 45
range: -40 100
units: degC
group: SIM
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L1101
---

# Simulated IMU Final Temperature (SIM_IMUT_END)

## Description
`SIM_IMUT_END` sets the target temperature that the flight controller will eventually reach after it has been running for a while (due to CPU heat and internal electronics).

## Tuning & Behavior
*   **Default Value:** 45 °C.