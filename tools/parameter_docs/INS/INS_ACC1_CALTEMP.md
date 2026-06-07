---
layout: parameter
name: INS_ACC1_CALTEMP
display_name: Accelerometer 1 Calibration Temperature
description: The temperature (in degrees Celsius) recorded during the accelerometer calibration.
default_value: -300
range: -50 100
units: degC
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Accelerometer 1 Calibration Temperature (INS_ACC1_CALTEMP)

## Description
`INS_ACC1_CALTEMP` records the temperature of the flight controller when you performed the 6-point accelerometer calibration.

The EKF uses this as a reference point. If the current temperature deviates significantly from this value, the system may apply thermal compensation corrections (if `INS_TCAL` is enabled) to maintain accuracy.

## Tuning & Behavior
*   **Default Value:** -300 (Uncalibrated).
*   **Usage:** Do not edit manually. This is updated automatically when you run the calibration routine.