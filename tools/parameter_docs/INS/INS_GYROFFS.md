---
layout: parameter
name: INS_GYROFFS
display_name: Gyroscope Z Offset
description: The calibrated zero-bias offset for the gyroscope Z-axis.
default_value: 0
range: -0.1 0.1
units: rad/s
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor_Params.cpp#L129
---

# Gyroscope Z Offset (INS_GYROFFS)

## Description
`INS_GYROFFS` is the result of the gyro calibration.

When you boot the drone, it must sit perfectly still for a few seconds. During this time, the flight controller averages the gyro readings to find the "Zero" point. This value is stored here to correct for sensor drift.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Usage:** Updated automatically on every boot. Do not change manually.