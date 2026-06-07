---
layout: parameter
name: EK3_WENC_VERR
display_name: EKF3 Wheel Encoder Velocity Error
description: The expected velocity error (in m/s) of the wheel encoder measurements.
default_value: 0.1
range: 0.05 1.0
units: m/s
group: EK3
visual_asset_id: wheel_encoder_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Wheel Encoder Velocity Error (EK3_WENC_VERR)

## Description
`EK3_WENC_VERR` tells the EKF how accurate the wheel encoders are.

If you are using wheel odometry for non-GPS navigation (e.g., a rover indoors), this parameter sets the trust level.

*   **Low Value:** High trust. The EKF will rely heavily on the wheels to estimate speed.
*   **High Value:** Low trust. The EKF will rely more on the IMU.

## Tuning & Behavior
*   **Default Value:** 0.1 m/s.
*   **Slippery Surface:** Increase to **0.5** if the wheels slip often.