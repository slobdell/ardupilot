---
layout: parameter
name: INS_ACCOFFS
display_name: Accelerometer Z Offset
description: The calibrated zero-bias offset for the accelerometer Z-axis.
default_value: 0
range: -3.5 3.5
units: m/s/s
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_Params.cpp#L66
---

# Accelerometer Z Offset (INS_ACCOFFS)

## Description
`INS_ACCOFFS` is the result of the accelerometer calibration.

It represents the constant error (bias) in the Z-axis measurement. The flight controller subtracts this value from the raw sensor reading to get the true acceleration.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Usage:** Do not edit manually. Updated by the `AccelCal` routine.