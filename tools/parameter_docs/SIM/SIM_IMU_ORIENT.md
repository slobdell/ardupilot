---
layout: parameter
name: SIM_IMU_ORIENT
display_name: Simulated IMU Orientation
description: Selects the orientation of the simulated IMUs relative to the vehicle frame.
default_value: 0
range: 0 38
units: 
group: SIM
visual_asset_id: imu_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated IMU Orientation (SIM_IMU_ORIENT)

## Description
`SIM_IMU_ORIENT` sets the physical "Heading" of the virtual sensors.

By default (0), the IMU is aligned with the drone's nose. If you want to test how ArduPilot handles an IMU that is mounted upside down or rotated 90 degrees, you can change this parameter and then verify that you can still calibrate and fly successfully using `AHRS_ORIENTATION`.

## Tuning & Behavior
*   **Default Value:** 0 (None).
*   **Recommendation:** Leave at **0** for standard tests. Use values like **8** (Roll 180) to test an inverted flight controller.