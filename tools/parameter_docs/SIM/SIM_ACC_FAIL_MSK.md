---
layout: parameter
name: SIM_ACC_FAIL_MSK
display_name: Simulated Accelerometer Failure Mask
description: A bitmask to disable specific accelerometers during simulation to test redundancy and failure handling.
default_value: 0
range: 0 7
units: 
group: SIM
visual_asset_id: sim_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SITL/SITL.cpp#L160
---

# Simulated Accelerometer Failure Mask (SIM_ACC_FAIL_MSK)

## Description
`SIM_ACC_FAIL_MSK` allows you to "kill" specific accelerometers in the simulator.

ArduPilot typically runs 3 IMUs (Inertial Measurement Units). By disabling one or two, you can verify that the EKF (Extended Kalman Filter) correctly switches to the remaining healthy sensors.

*   **Bit 0 (1):** Fail Accel 1
*   **Bit 1 (2):** Fail Accel 2
*   **Bit 2 (4):** Fail Accel 3

## Tuning & Behavior
*   **Default Value:** 0 (All sensors active).
*   **Testing:** Set to **1** to kill Accel 1. Watch the `EKF3.Lane` messages in the GCS console to see the switch occur.