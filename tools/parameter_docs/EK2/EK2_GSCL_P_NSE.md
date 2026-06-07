---
layout: parameter
name: EK2_GSCL_P_NSE
display_name: EKF2 Gyro Scale Factor Process Noise
description: Controls the rate of gyro scale factor learning.
default_value: 0.00001
range: 0.000001 0.001
units: Hz
group: EK2
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF2/AP_NavEKF2.cpp#L377
---

# EKF2 Gyro Scale Factor Process Noise (EK2_GSCL_P_NSE)

## Description
`EK2_GSCL_P_NSE` determines how fast the EKF2 learns the scale factor errors of the gyroscopes.

Gyroscopes are not perfectly linear; they might report 101 degrees/sec when the drone actually rotated 100 degrees. This parameter allows the EKF to identify and correct that "Scale Error" over time.

## Tuning & Behavior
*   **Default Value:** 0.00001 Hz.
*   **Higher Value:** Faster learning, but heading might become unstable during aggressive maneuvers.
*   **Lower Value:** Slower, more stable learning.