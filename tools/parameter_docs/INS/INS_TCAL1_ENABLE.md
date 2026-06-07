---
layout: parameter
name: INS_TCAL1_ENABLE
display_name: IMU1 Temperature Calibration Enable
description: Enables the use of temperature calibration parameters for the first IMU.
default_value: 0
range: 0 2
units: 
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.cpp#L100
---

# IMU1 Temperature Calibration Enable (INS_TCAL1_ENABLE)

## Description
`INS_TCAL1_ENABLE` turns on the thermal compensation logic.

IMUs drift when they get hot. If you have performed a temperature calibration (heating the flight controller while it is stationary), setting this to **1** will apply the learned corrections.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled (Use learned values).
*   **2:** Learn Calibration (Start learning process).