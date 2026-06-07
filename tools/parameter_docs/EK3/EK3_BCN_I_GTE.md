---
layout: parameter
name: EK3_BCN_I_GTE
display_name: EKF3 Beacon Innovation Gate
description: The number of standard deviations allowed before a range beacon measurement is rejected.
default_value: 500
range: 100 1000
units: '%'
group: EK3
visual_asset_id: ek3_gate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L512
---

# EKF3 Beacon Innovation Gate (EK3_BCN_I_GTE)

## Description
`EK3_BCN_I_GTE` controls the strictness of the "Glitch Filter" for indoor positioning beacons (like Pozyx or Marvelmind).

When the EKF receives a distance measurement from a beacon, it compares it to where it *thinks* the drone is. If the difference (Innovation) is too large, the EKF assumes the measurement is a "multipath" reflection or error and rejects it.

*   **Low Value (e.g. 300):** Strict. Rejects noisy data easily. Good for high-precision flight in clean environments.
*   **High Value (e.g. 800):** Relaxed. Accepts jumpy data. Use if your beacons are noisy but you trust them more than the IMU.

## The Mathematics
The gate check uses the Normalized Innovation Squared (NIS):
$$ \frac{(z_{meas} - z_{pred})^2}{S} < \left(\frac{\text{GATE}}{100}\right)^2 $$

Where:
*   $z$ is the range measurement.
*   $S$ is the innovation covariance (expected uncertainty).
*   **500** represents 5 Standard Deviations ($\sigma$).

## The Engineer's View
Defined in `AP_NavEKF3`.
This parameter only applies when `EK3_SRC1_POSXY` is set to **Beacon (4)**.
Unlike GPS gating (which has separate velocity and position gates), beacon gating is applied to the raw range measurement from each anchor.

## Tuning & Behavior
*   **Default Value:** 500 (5-Sigma).
*   **Recommendation:**
    *   **Standard Indoor:** Keep at **500**.
    *   **Metal Building (Reflections):** Decrease to **300** to reject multipath spikes.
    *   **Fast Flight:** Increase to **800** if the drone moves faster than the beacons can update, causing false rejections due to lag.
