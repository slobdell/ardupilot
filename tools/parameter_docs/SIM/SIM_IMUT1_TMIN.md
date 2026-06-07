---
layout: parameter
name: SIM_IMUT1_TMIN
display_name: Simulation IMU Temperature Min
description: The minimum temperature (in degrees Celsius) for the IMU temperature calibration model.
default_value: -10
range: -50 80
units: degC
group: SIM
visual_asset_id: imu_temp_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L150
---

# Simulation IMU Temperature Min (SIM_IMUT1_TMIN)

## Description
`SIM_IMUT1_TMIN` defines the lower bound for simulating IMU thermal noise and bias shifts.
