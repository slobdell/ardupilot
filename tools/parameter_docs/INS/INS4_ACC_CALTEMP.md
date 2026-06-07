---
layout: parameter
name: INS4_ACC_CALTEMP
display_name: Accelerometer 4 Calibration Temperature
description: The temperature (in degrees Celsius) recorded during the calibration of the 4th IMU accelerometer.
default_value: -300
range: -50 100
units: degC
group: INS
visual_asset_id: imu_cal_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_InertialSensor/AP_InertialSensor.cpp
---

# Accelerometer 4 Calibration Temperature (INS4_ACC_CALTEMP)

## Description
`INS4_ACC_CALTEMP` records the temperature of the 4th IMU when its accelerometer calibration was performed. 

This is part of ArduPilot's support for high-redundancy flight controllers that have 4 or more IMUs. The autopilot uses this value to monitor thermal drift and apply corrections relative to this calibration baseline.