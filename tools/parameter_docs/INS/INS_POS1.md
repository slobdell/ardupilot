---
layout: parameter
name: INS_POS1
display_name: IMU 1 Position Offset
description: The XYZ position (in meters) of the first IMU relative to the body frame origin (usually CoG).
default_value: 0 0 0
range: -5 5
units: m
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# IMU 1 Position Offset (INS_POS1)

## Description
`INS_POS1` defines the physical location of the primary accelerometer.

The EKF assumes the IMU is at the center of the vehicle. If the flight controller is mounted far from the Center of Gravity (CoG), rotation can be misinterpreted as acceleration (centripetal force). This parameter allows the EKF to correct for that lever-arm effect.

## Tuning & Behavior
*   **Default Value:** 0,0,0.
*   **Usage:** Measure the distance from the CoG to the center of the flight controller in meters.
*   **X:** Positive Forward.
*   **Y:** Positive Right.
*   **Z:** Positive Down.