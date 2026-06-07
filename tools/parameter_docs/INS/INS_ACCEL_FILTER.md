---
layout: parameter
name: INS_ACCEL_FILTER
display_name: Accelerometer Low Pass Filter
description: The cutoff frequency (in Hz) for the accelerometer low-pass filter.
default_value: 10
range: 0 250
units: Hz
group: INS
visual_asset_id: filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Accelerometer Low Pass Filter (INS_ACCEL_FILTER)

## Description
`INS_ACCEL_FILTER` removes vibration noise from the accelerometer data. 

Unlike the Gyro (which is for attitude), the Accelerometer is primarily for position and climb rate. It is very sensitive to motor vibration. 

## The Engineer's View
Defined in `AP_InertialSensor.cpp`. 
The filtered accelerometer data is used by the EKF to calculate velocity and position increments. 

## Tuning & Behavior
*   **Default Value:** 10 Hz.
*   **Recommendation:** Usually leave at **10-20 Hz**. Setting it higher may improve position hold in high winds, but only if your frame is exceptionally clean (low vibration).
