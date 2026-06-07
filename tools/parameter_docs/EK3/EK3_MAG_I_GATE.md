---
layout: parameter
name: EK3_MAG_I_GATE
display_name: Compass Innovation Gate
description: Controls the strictness of the compass measurement rejection. Lower values are stricter.
default_value: 300
range: 100 1000
units: 
group: EK3
visual_asset_id: ek3_gate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L262
---

# Compass Innovation Gate (EK3_MAG_I_GATE)

## Description
`EK3_MAG_I_GATE` is the "BS Filter" for the compass. 

The EKF is constantly predicting what the magnetic field *should* be based on its current heading. When it gets a new measurement from the physical compass, it calculates the difference (the "Innovation"). If that difference is too large, the EKF assumes the compass has gone haywire (maybe it's near a magnet) and **rejects the data** to prevent a crash.

*   **Low Value (e.g., 100):** Very strict. If the compass signal is even slightly noisy, the EKF will ignore it. This is safe but can lead to "Compass Unhealthy" warnings.
*   **High Value (e.g., 500):** Very relaxed. The EKF will trust almost anything the compass says. Dangerous if the compass is actually being distorted by interference.

## The Mathematics
The gate uses a **Statistical Distance** (Mahalanobis Distance) check.
The innovation $y = z - H\hat{x}$ is checked against the innovation covariance $S$:
$$ y^T S^{-1} y \leq \text{GATE}^2 $$

If the error squared exceeds the gate threshold, the measurement is discarded.

## The Engineer's View
Used in the measurement update loop of `AP_NavEKF3`.
A value of **300** corresponds to a 3-sigma gate (99.7% confidence interval). Measurements outside this are statistically likely to be errors rather than valid movement.

## Tuning & Behavior
*   **Default Value:** 300
*   **Recommendation:** Keep at **300**.
*   **Troubleshooting:** If you get constant "EKF Compass Innovation" errors but you are sure your compass is well-calibrated and away from metal, you can increase this to **500** to stop the warnings. However, this is usually masking a physical hardware issue (vibration or interference).
