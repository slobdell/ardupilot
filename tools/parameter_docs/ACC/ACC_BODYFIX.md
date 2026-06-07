---
layout: parameter
name: ACC_BODYFIX
display_name: Body-fixed accelerometer
description: The body-fixed accelerometer to be used for trim calculation.
default_value: 2
range: 1 3
units: 
group: ACC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor.cpp
---

# Body-fixed accelerometer (ACC_BODYFIX)

## Description
Specifies which IMU's accelerometer is considered "body-fixed" for the purpose of calculating attitude trims.

## Tuning & Behavior
*   **Default Value:** 2 (IMU 2)
*   **Values:** 1:IMU 1, 2:IMU 2, 3:IMU 3