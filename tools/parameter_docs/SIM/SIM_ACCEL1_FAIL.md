---
layout: parameter
name: SIM_ACCEL1_FAIL
display_name: Simulated Accelerometer 1 Failure
description: Forces a complete failure of the first simulated accelerometer to test EKF lane switching and redundancy.
default_value: 0
range: 0 1
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L160
---

# Simulated Accelerometer 1 Failure (SIM_ACCEL1_FAIL)

## Description
`SIM_ACCEL1_FAIL` allows you to simulate a catastrophic hardware failure of your primary accelerometer.

When set to **1**, the sensor stops providing data. This is used by developers to verify that the "Lane Switching" logic in EKF3 correctly identifies the dead sensor and automatically switches the drone's control to Accelerometer 2 or 3 without crashing.

## The Engineer's View
When this flag is set, the SITL backend for the IMU returns `false` on its `read()` calls or provides static/zero data. This triggers the EKF health monitoring system to mark the lane as unhealthy.

## Tuning & Behavior
*   **Default Value:** 0 (Sensor working normally).
*   **Recommendation:** Only set to **1** while in flight in a safe simulation to verify your drone's redundant systems are working as expected.