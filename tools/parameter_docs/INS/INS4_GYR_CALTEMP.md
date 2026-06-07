---
layout: parameter
name: INS4_GYR_CALTEMP
display_name: Gyroscope 4 Calibration Temperature
description: The temperature (in degrees Celsius) recorded during the calibration of the 4th IMU gyroscope.
default_value: -300
range: -50 100
units: degC
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor.cpp
---

# Gyroscope 4 Calibration Temperature (INS4_GYR_CALTEMP)

## Description
`INS4_GYR_CALTEMP` records the temperature of the 4th IMU when its gyroscope calibration was performed.