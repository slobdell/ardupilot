---
layout: parameter
name: INS_ACC_BODYFIX
display_name: Accelerometer Body Fix
description: Applies a fixed rotation to the accelerometer data to correct for mounting misalignment.
default_value: 2
range: 0 2
units: 
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Accelerometer Body Fix (INS_ACC_BODYFIX)

## Description
`INS_ACC_BODYFIX` corrects for physical misalignment of the flight controller.

If your board is mounted slightly crooked, the accelerometers will report a constant error. This parameter enables a correction matrix that rotates the accelerometer vector to match the vehicle's body frame.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Use AHRS Trim.
*   **2:** Use Board Orientation.