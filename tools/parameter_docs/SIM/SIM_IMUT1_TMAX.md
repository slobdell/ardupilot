---
layout: parameter
name: SIM_IMUT1_TMAX
display_name: Simulation IMU Temperature Max
description: The maximum temperature (in degrees Celsius) for the IMU temperature calibration model.
default_value: 80
range: -50 80
units: degC
group: SIM
visual_asset_id: imu_temp_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L151
---

# Simulation IMU Temperature Max (SIM_IMUT1_TMAX)

## Description
`SIM_IMUT1_TMAX` defines the upper bound for the IMU thermal model.
