---
layout: parameter
title: IMU_POS
name: IMU Offsets
group: IMU
---

# IMU_POS: IMU Offsets

## Description
XYZ position of the IMU accelerometer relative to the body frame origin.

## Values
- **Units:** m
- **Format:** Vector3 (X, Y, Z)
- **Default:** 0, 0, 0

## Description
This parameter is used in **SITL (Software In The Loop) simulation** only. It defines the physical location of the simulated IMU sensor relative to the center of the simulated vehicle.

- **Purpose:** Used to simulate "lever arm" effects. When the vehicle rotates, an IMU not at the center of rotation measures centripetal and tangential acceleration. Setting this parameter allows developers to verify that the EKF (Extended Kalman Filter) correctly compensates for these offsets.
- **X:** Forward offset (positive forward).
- **Y:** Right offset (positive right).
- **Z:** Down offset (positive down).

## Source Code
[ardupilot/libraries/SITL/SITL.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L237)
