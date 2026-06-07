---
layout: parameter
name: SIM_ACC_TRIM
display_name: Simulation Accelerometer Trim
description: Adds a constant tilt offset (in degrees) to the simulated accelerometer to simulate an uncalibrated or misaligned IMU.
default_value: 0
range: -5 5
units: deg
group: SIM
visual_asset_id: imu_pos_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L102
---

# Simulation Accelerometer Trim (SIM_ACC_TRIM)

## Description
`SIM_ACC_TRIM` simulates a drone where the flight controller isn't mounted perfectly level.

It injects a constant tilt into the accelerometer data. This is used to test how robust the EKF and flight controllers are to slight misalignments and to verify that "Accel Calibration" or "AHRS Trim" procedures work correctly in SITL.