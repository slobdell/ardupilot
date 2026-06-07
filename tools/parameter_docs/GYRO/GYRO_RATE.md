---
layout: parameter
name: GYRO_RATE
display_name: Gyro sampling rate
description: Rate in Hz that gyro sensors are sampled.
default_value: 0
range: 0 4000
units: Hz
group: GYRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor.cpp
---

# Gyro sampling rate (GYRO_RATE)

## Description
Defines the hardware sampling frequency for the gyroscopes. 
*   **0: Auto-detect (Recommended)**