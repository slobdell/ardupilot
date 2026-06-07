---
layout: parameter
title: IMU_SAMPLE_RATE
name: IMU Sample Rate
group: IMU
---

# IMU_SAMPLE_RATE: IMU Sample Rate

## Description
Sets the sample rate for the Inertial Measurement Unit (IMU) on the AP_Periph node.

## Values
- **Range:** 0 to 1000
- **Units:** Hz
- **Default:** 0

## Description
This parameter configures the loop rate of the Inertial Sensor driver on the peripheral.

- **0:** Use the driver's default rate.
- **>0:** Force a specific sample rate in Hz. Higher rates allow for better vibration filtering (if the hardware supports it) but consume more CPU resources on the peripheral microcontroller.

## Source Code
[ardupilot/Tools/AP_Periph/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L733)
