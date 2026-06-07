---
layout: parameter
name: INS_TCAL_GYR1
display_name: Gyroscope 1 Temp Coeff
description: The 1st-order linear temperature compensation coefficient for Gyro 1.
default_value: 0
range: -10 10
units: 
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_tempcal.cpp#L95
---

# Gyroscope 1 Temp Coeff (INS_TCAL_GYR1)

## Description
`INS_TCAL_GYR1` is the thermal slope for the gyroscope.

Similar to `INS_TCAL_ACC1`, this value allows the EKF to predict and remove gyro drift caused by temperature changes, improving attitude estimation accuracy during long flights where the board temperature varies.

## Tuning & Behavior
*   **Default Value:** 0.