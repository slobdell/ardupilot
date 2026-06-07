---
layout: parameter
name: EK3_ACC_BIAS_LIM
display_name: EKF3 Accelerometer Bias Limit
description: The maximum accelerometer bias (in m/s/s) that the EKF is allowed to learn.
default_value: 1.0
range: 0.1 2.5
units: m/s/s
group: EK3
visual_asset_id: ekf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Accelerometer Bias Limit (EK3_ACC_BIAS_LIM)

## Description
`EK3_ACC_BIAS_LIM` is a safety "Sanity Check" for your IMU.

Accelerometers are not perfect; they often have a small constant error (bias). The EKF tries to "Learn" and subtract this error during flight. However, if the IMU is failing or vibrating excessively, the learned bias might become huge and incorrect. This parameter limits how much bias the EKF is allowed to compensate for. If the limit is reached, the EKF will stop trusting that IMU.

## The Mathematics
The EKF state vector includes a bias term $b_{acc}$. This parameter enforces a hard constraint:

$$ |b_{acc}| \le \text{EK3\_ACC\_BIAS\_LIM} $$

If the filter's internal estimate exceeds this value, it indicates a hardware issue or a significant environmental disturbance.

## Tuning & Behavior
*   **Default Value:** 1.0 m/s/s.
*   **High Vibration:** On very noisy gas-powered helicopters, you might need to increase this to **1.5** to prevent premature EKF lane switching.
*   **Health Warning:** If your logs show the bias consistently hitting this limit, your flight controller likely has a physical mounting issue or a dying sensor.