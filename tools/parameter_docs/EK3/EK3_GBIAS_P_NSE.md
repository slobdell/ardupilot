---
layout: parameter
name: EK3_GBIAS_P_NSE
display_name: EKF3 Gyroscope Bias Process Noise
description: The process noise for the gyroscope bias state estimation.
default_value: 0.0001
range: 0.00001 0.001
units: rad/s/s
group: EK3
visual_asset_id: ekf_noise_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Gyroscope Bias Process Noise (EK3_GBIAS_P_NSE)

## Description
`EK3_GBIAS_P_NSE` controls how aggressively the EKF estimates the gyroscope's drift.

Gyro drift is the slow rotation reported by the sensor even when the drone is still.

## The Engineer's View
Sets the process noise for the 3-axis gyro bias states.
$$ \dot{b}_g = \mathcal{N}(0, \text{EK3\_GBIAS\_P\_NSE}) $$

## Tuning & Behavior
*   **Default Value:** 1E-04 (0.0001)
*   **Recommendation:** Leave at default. If using very cheap gyros that drift wildly with temperature, increase this.