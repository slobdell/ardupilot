---
layout: parameter
name: EK3_POS_I_GATE
display_name: EKF3 Position Innovation Gate
description: Controls the size of the "rejection gate" for horizontal position measurements. Defines how large a position error can be before the EKF ignores the data as a glitch.
default_value: 500
range: 100 1000
units: 
group: EKF
visual_asset_id: ek3_pos_i_gate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L191
---

# EKF3 Position Innovation Gate (EK3_POS_I_GATE)

## Description
`EK3_POS_I_GATE` is the "glitch detector" for your drone's position. It determines how far the GPS data can disagree with the drone's internal estimate before the EKF3 decides the GPS is lying.

In a Kalman Filter, the difference between the *expected* measurement and the *actual* measurement is called the **Innovation**. If your drone thinks it's at Point A, but the GPS suddenly says it's at Point B (100 meters away), the Innovation is huge. The "Gate" is a mathematical boundary—if the error is inside the gate, it's considered "normal noise" and the EKF updates its position. If it's outside the gate, it's considered a "glitch" and is ignored.

*   **Low Value (e.g. 100):** Very strict. The EKF will reject even small GPS jumps. This is safe but can lead to the EKF "timing out" and losing its position estimate if the GPS is consistently slightly off.
*   **High Value (e.g. 1000):** Very relaxed. The EKF will accept large position jumps. This allows for faster recovery from errors but increases the risk of the drone "darting" toward a fake GPS coordinate.

## The Mathematics
The EKF uses a statistical test (Chi-Squared) to determine if a measurement is valid. The gate ($G$) is applied to the **Normalized Innovation Squared** ($NIS$):

$$ NIS = \vec{y}^T \mathbf{S}^{-1} \vec{y} \leq G^2 $$

Where:
*   $\vec{y}$ is the Innovation vector (Measurement - Prediction).
*   $\mathbf{S}$ is the Innovation Covariance (Total expected uncertainty).
*   $G$ is the value derived from `EK3_POS_I_GATE`.

**Scale:** The value in the GCS (e.g., 500) represents a standard deviation multiplier. A value of 500 corresponds to a "5-sigma" gate, which is extremely statistically unlikely to occur by chance (~0.00006% probability).

## The Engineer's View
This parameter is the `_gpsPosInnovGate` member in `NavEKF3`.

It is checked during the `AP_NavEKF3_PosVelFusion.cpp` loop. If a measurement fails the gate, it is logged as an **EKF Primary Check Failure**. If measurements fail consistently for more than a second, the EKF will trigger a "Reset" or an "EKF Lane Switch," assuming that its internal state (not the sensor) is the one that is wrong.

## Tuning & Behavior
*   **Default Value:** 500 (Standard)
*   **Range:** 100 - 1000
*   **Effect of Increasing:** Faster recovery from large position resets. Better for high-speed flight where position uncertainty is naturally high.
*   **Effect of Decreasing:** Better protection against small GPS multipath jumps. Essential for high-precision autonomous missions near obstacles.

### Use Case Recommendations
*   **Open Field Flight:** **Keep Default (500).**
*   **RTK Precision Survey:** **Decrease to 200.** Since RTK is extremely accurate, any innovation larger than 20cm is almost certainly a sensor error and should be rejected instantly.
*   **Rapid Racing / High G-Force:** **Increase to 800.** High-speed maneuvers create high uncertainty; a wider gate prevents the EKF from "locking out" the GPS during sharp turns.

### Troubleshooting
*   **Scenario:** Drone refuses to enter Loiter, and the GCS shows "EKF Position Variance."
    *   **Diagnosis:** The GPS data is consistently failing the innovation gate.
    *   **Fix:** If the GPS signal is clear, increase `EK3_POS_I_GATE` to 750 to help the EKF re-sync.
*   **Scenario:** Drone "darts" 5 meters to the side before coming back.
    *   **Diagnosis:** `EK3_POS_I_GATE` is too high, allowing the EKF to follow a bad GPS sample.
    *   **Fix:** Reduce to 300.