---
layout: parameter
name: EK3_VEL_I_GATE
display_name: EKF3 Velocity Innovation Gate
description: Controls the size of the "rejection gate" for velocity (speed) measurements. Defines how large a velocity error can be before the EKF ignores the data as a sensor glitch.
default_value: 300
range: 100 1000
units: 
group: EKF
visual_asset_id: ek3_vel_i_gate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L174
---

# EKF3 Velocity Innovation Gate (EK3_VEL_I_GATE)

## Description
`EK3_VEL_I_GATE` is the "speed trap" for your drone's sensors. It determines how much a sensor's reported speed can disagree with the drone's internal math before the data is rejected as a glitch.

If your drone thinks it's stationary, but the GPS suddenly reports a speed of 50 m/s (common in poor signal conditions), the **Innovation** (error) is massive. `EK3_VEL_I_GATE` sets the threshold for this error. If the reported speed is outside this gate, the EKF ignores it, assuming the GPS is having a momentary glitch.

*   **Low Value (e.g. 100):** Very strict. Prevents the drone from jerking or twitching if the GPS speed jumps, but can cause the EKF to lose sync if the drone is actually maneuvering aggressively.
*   **High Value (e.g. 800):** Very relaxed. The EKF will follow even large jumps in speed data.
*   **Default (300):** A balanced 3-sigma gate that is robust for standard flight.

## The Mathematics
The gate ($G$) is part of the Chi-Squared consistency check:

$$ \vec{y}_v^T \mathbf{S}_v^{-1} \vec{y}_v \leq G^2 $$

Where:
*   $\vec{y}_v$ is the Velocity Innovation ($V_{sensor} - V_{predicted}$).
*   $\mathbf{S}_v$ is the Innovation Covariance matrix for velocity.
*   $G$ is derived from `EK3_VEL_I_GATE`.

**Scaling:** The value (300) represents a percentage of the standard deviation. 300 means a "3-sigma" threshold, which covers 99.7% of all expected sensor variations. Anything beyond this is statistically "impossible" and likely a glitch.

## The Engineer's View
This parameter is the `_gpsVelInnovGate` member in `NavEKF3`.

It is applied in `AP_NavEKF3_PosVelFusion.cpp`. Velocity gating is more critical than position gating for **Flight Damping**. If a bad velocity sample passes the gate, it instantly creates a massive acceleration demand in the PID loops, causing a violent "jerk." Keeping this gate tight (e.g. 300) is what makes ArduPilot feel smooth even in noisy GPS environments.

## Tuning & Behavior
*   **Default Value:** 300
*   **Range:** 100 - 1000
*   **Effect of Increasing:** The drone is less likely to lose "EKF Health" during extreme 3D maneuvers or high-speed racing.
*   **Effect of Decreasing:** Smoother flight; more aggressive rejection of GPS speed spikes.

### Use Case Recommendations
*   **Standard Multirotor:** **Keep Default (300).** 
*   **High-Speed Racing Drone:** **Increase to 500 - 600.** High-G turns create large velocity innovations that can exceed 3-sigma; a wider gate prevents the EKF from "locking out" the sensors during the turn.
*   **Precision Docking / Automation:** **Decrease to 150.** In slow, precision movements, you want to reject any speed noise immediately to prevent the drone from "twitching" near the docking target.

### Troubleshooting
*   **Scenario:** GCS reports "EKF Velocity Variance" every time I perform a sharp turn.
    *   **Diagnosis:** The maneuvers are so aggressive that the EKF's prediction is lagging behind the sensor, causing the error to hit the gate limit.
    *   **Fix:** Increase `EK3_VEL_I_GATE` to 500.
*   **Scenario:** Drone "lunges" forward randomly for a fraction of a second.
    *   **Diagnosis:** `EK3_VEL_I_GATE` is too high, letting a bad GPS velocity sample corrupt the filter.
    *   **Fix:** Reduce to 200.