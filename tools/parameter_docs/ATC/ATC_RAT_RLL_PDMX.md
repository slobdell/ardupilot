---
layout: parameter
name: ATC_RAT_RLL_RLL_PDMX
display_name: Roll Axis Rate PD Maximum
description: Limits the maximum combined contribution of the Proportional (P) and Derivative (D) terms in the roll rate loop. Prevents extreme momentary motor torque requests.
default_value: 0
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_rat_rll_pdmx_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L73
---

# Roll Axis Rate PD Maximum (ATC_RAT_RLL_PDMX)

## Description
`ATC_RAT_RLL_PDMX` is a safety clamp for the "active" parts of the roll controller. 

In a PID loop, the **P** and **D** terms are responsible for reacting to fast changes and noise. If the drone is hit by a massive gust or experiences an extreme impact, the P and D terms might compute a requested motor power of 300%—which is physically impossible and can cause the control software to behave erratically.

This parameter sets a ceiling on the combined power of P and D. It ensures that no matter how big the mistake is, the *immediate* rotation torque requested by the drone is kept within a reasonable range.

*   **Low Value:** Limits the drone's "snap" or ability to fight hard against extreme turbulence.
*   **High Value:** Allows the drone to use its full motor torque for immediate corrections.
*   **Disabled (0):** The PD sum is unlimited (limited only by the physical constraints of the motors).

## The Mathematics
The P and D terms are summed and then constrained by this value:

$$ \text{PD}_{output} = \text{constrain}(P + D, -\text{PDMX}, \text{PDMX}) $$

Where:
*   $P$ is the proportional contribution ($k_P \cdot \omega_{error}$). 
*   $D$ is the derivative contribution ($k_D \cdot \frac{d}{dt}\omega_{error}$). 
*   $\text{PDMX}$ is `ATC_RAT_RLL_PDMX`.

**Note:** This limit is applied *before* the Integral (I) term and Feed-Forward (FF) are added. This ensures that even if P and D are clamped, the drone can still maintain its long-term attitude through the I-term.

## The Engineer's View
This parameter maps to `_kpdmax` in the `_pid_rate_roll` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(_kpdmax)) {
    float pd_sum = P + D;
    pd_sum = constrain_float(pd_sum, -_kpdmax, _kpdmax);
    // ... use pd_sum ...
}
```

This is particularly useful for very high-performance drones where the D-gain is very aggressive. It prevents a single noisy gyro sample from commanding a full-power motor reversal.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited)
*   **Range:** 0 - 1.0 (0 to 100% motor authority)
*   **Effect of Increasing:** Increases the drone's "recovery authority"—the ability to level itself after a massive disturbance.
*   **Effect of Decreasing:** Makes the flight feel "safer" and less likely to have sudden motor torque transients.

### Use Case Recommendations
*   **Standard Multirotor:** **Keep at 0.**
*   **Large Professional Rig (>10kg):** **Set to 0.5 (50%).** Prevents extreme software-driven torque from snapping a motor arm or stripping a propeller hub during a shock.
*   **Research / Prototype flight:** **Set to 0.3.** A safe setting for testing experimental code where you want to limit how "hard" the controller can kick.

### Troubleshooting
*   **Scenario:** Drone feels sluggish to recover from a steep bank, even though `RAT_RLL_P` is high.
    *   **Diagnosis:** `ATC_RAT_RLL_PDMX` is set too low, capping the controller's authority.
    *   **Fix:** Increase `ATC_RAT_RLL_PDMX` or set it to 0.