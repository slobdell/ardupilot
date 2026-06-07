---
layout: parameter
name: INS_STILL_THRESH
display_name: INS Stillness Threshold
description: The accelerometer variance threshold (in m/s/s) below which the vehicle is considered stationary.
default_value: 0.1
range: 0.05 0.5
units: m/s/s
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# INS Stillness Threshold (INS_STILL_THRESH)

## Description
`INS_STILL_THRESH` defines "Motionless."

When calibrating gyroscopes or performing pre-arm checks, the autopilot needs to know if the drone is sitting still. If the accelerometer variance is below this threshold, the system is assumed to be stationary.

## Tuning & Behavior
*   **Default Value:** 0.1 m/s/s.
*   **Increase:** If you are on a boat or a swaying platform.
*   **Decrease:** For laboratory precision calibration.