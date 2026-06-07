---
layout: parameter
name: SIM_IMU_COUNT
display_name: Simulated IMU Count
description: The number of simulated IMUs (Accelerometer + Gyroscope sets) to instantiate.
default_value: 2
range: 1 3
units: 
group: SIM
visual_asset_id: imu_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L100
---

# Simulated IMU Count (SIM_IMU_COUNT)

## Description
`SIM_IMU_COUNT` sets the number of virtual internal sensors.

Modern flight controllers often have 2 or 3 IMUs for safety. This parameter allows SITL to mimic that redundancy. You can then use `SIM_ACCELx_FAIL` to kill one sensor and see how the autopilot handles it.

## Tuning & Behavior
*   **Default Value:** 2.
*   **Recommendation:** Set to **2 or 3** to test EKF lane switching logic.
*   **Reboot Required:** Yes.