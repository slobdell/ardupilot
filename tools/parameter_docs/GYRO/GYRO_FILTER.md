---
layout: parameter
name: GYRO_FILTER
display_name: Gyro Filter Frequency
description: Filter frequency for gyro data.
default_value: 20
range: 0 250
units: Hz
group: GYRO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor.cpp
---

# Gyro Filter Frequency (GYRO_FILTER)

## Description
The low-pass filter frequency for the gyroscopes. This helps to remove high-frequency noise and vibration from the angular rate data, leading to smoother flight but slightly more latency.
*   **Default Value:** 20 Hz (Typical)