---
layout: parameter
title: MAG_ALY
name: Magnetic Anomaly Vector
group: MAG
---

# MAG_ALY: Magnetic Anomaly Vector

## Description
Sets a local magnetic anomaly vector (in Gauss) to be added to the earth's magnetic field in the simulator.

## Values
- **Units:** Gauss
- **Format:** Vector3 (X, Y, Z)
- **Default:** 0, 0, 0

## Description
This parameter allows developers to simulate magnetic interference or local anomalies in the **SITL** environment.

- **X, Y, Z Components:** Represents the anomaly vector added to the base earth magnetic field.
- **Use Case:** Testing compass calibration routines, EKF mag fusion resilience, or simulating flight near large metal structures.
- **Note:** The anomaly strength decays with height based on `MAG_ALY_HGT`.

## Source Code
[ardupilot/libraries/SITL/SITL.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L950)

