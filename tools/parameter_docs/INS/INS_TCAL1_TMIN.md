---
layout: parameter
name: INS_TCAL1_TMIN
display_name: IMU1 Temperature Calibration Min
description: The minimum temperature (in degrees Celsius) that the calibration is valid for.
default_value: 0
range: -40 85
units: degC
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.cpp#L100
---

# IMU1 Temperature Calibration Min (INS_TCAL1_TMIN)

## Description
`INS_TCAL1_TMIN` records the coldest temperature from the calibration.

## Tuning & Behavior
*   **Default Value:** 0.