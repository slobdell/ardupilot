---
layout: parameter
name: EK3_ABIAS_P_NSE
display_name: EKF3 Accelerometer Bias Process Noise
description: The process noise for the accelerometer bias state estimation.
default_value: 0.002
range: 0.0001 0.01
units: m/s/s/s
group: EK3
visual_asset_id: ekf_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Accelerometer Bias Process Noise (EK3_ABIAS_P_NSE)

## Description
`EK3_ABIAS_P_NSE` tells the EKF how fast it should expect the accelerometer's "zero point" (bias) to drift over time.

Accelerometers drift due to temperature changes and internal stress. The EKF constantly estimates this bias to subtract it.

*   **Higher Value:** The EKF expects the bias to change rapidly. It will adapt quickly to temperature shifts but might be less stable.
*   **Lower Value:** The EKF expects a very stable sensor. It will lock onto a bias value and resist changing it.

## The Engineer's View
Sets the process noise covariance ($Q$) for the accelerometer bias states ($Z$ axis and $X/Y$ axes).
This essentially sets the "bandwidth" of the bias estimation loop.

## Tuning & Behavior
*   **Default Value:** 0.002
*   **Recommendation:** Leave at default unless you are seeing "Z-Accel Bias" warnings on a high-quality IMU, in which case you might lower it slightly.