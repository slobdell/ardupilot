---
layout: parameter
name: SIM_GYR_FAIL_MSK
display_name: Simulated Gyroscope Failure Mask
description: A bitmask to disable specific gyroscopes during simulation to test redundancy and failure handling.
default_value: 0
range: 0 7
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L160
---

# Simulated Gyroscope Failure Mask (SIM_GYR_FAIL_MSK)

## Description
`SIM_GYR_FAIL_MSK` kills specific gyroscopes in the simulator.

This is critical for testing the "vibration failsafe" and EKF lane switching logic.

*   **Bit 0 (1):** Fail Gyro 1
*   **Bit 1 (2):** Fail Gyro 2
*   **Bit 2 (4):** Fail Gyro 3

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Use in conjunction with `SIM_ACC_FAIL_MSK` to simulate a complete IMU failure.