---
layout: parameter
name: PSC_ACCZ_PDMX
display_name: Position Control Acceleration (Vertical) PD Maximum
description: Limits the maximum combined contribution of the Proportional (P) and Derivative (D) terms in the vertical acceleration loop. Prevents extreme momentary throttle requests.
default_value: 0
range: 0 1000
units: d%
group: PSC
visual_asset_id: psc_accz_pdmx_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L73
---

# Position Control Acceleration (Vertical) PD Maximum (PSC_ACCZ_PDMX)

## Description
`PSC_ACCZ_PDMX` is a safety clamp for the "active" parts of the vertical controller. In a PID loop, the **P** and **D** terms are responsible for reacting to noise and sudden changes. If the drone is hit by a massive vertical gust, the P and D terms might compute a requested throttle change of 200%—which is physically impossible and can cause the control loop to behave erratically.

This parameter sets a ceiling on the combined power of P and D. It ensures that no matter how big the vertical error is, the *immediate* correction requested by the drone is kept within a reasonable range.

*   **Low Value:** Limits the drone's "snap" or ability to fight hard against turbulence.
*   **High Value:** Allows the drone to use its full motor power for immediate corrections.
*   **Disabled (0):** The PD sum is unlimited (limited only by the physical constraints of the motors).

## The Mathematics
The P and D terms are summed and then constrained by this value:

$$ \text{PD}_{output} = \text{constrain}(P + D, -\text{PDMX}, \text{PDMX}) $$

Where:
*   $P$ is the proportional contribution ($k_P \cdot \text{error}$).
*   $D$ is the derivative contribution ($k_D \cdot \frac{d}{dt}\text{error}$).
*   $\text{PDMX}$ is `PSC_ACCZ_PDMX`.

**Note:** This limit is applied *before* the Integral (I) term and Feed-Forward (FF) are added. This ensures that even if P and D are clamped, the drone can still achieve its full lift via the I-term.

## The Engineer's View
This parameter maps to `_kpdmax` in the `_pid_accel_z` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(_kpdmax)) {
    float pd_sum = P + D;
    pd_sum = constrain_float(pd_sum, -_kpdmax, _kpdmax);
    // ... use pd_sum ...
}
```

This is particularly useful in high-vibration environments where the D-term might otherwise produce extreme, unnecessary throttle spikes.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited)
*   **Range:** 0 - 1000 (0 to 100% throttle authority)
*   **Effect of Increasing:** Increases the drone's ability to "punch" out of a vertical drop.
*   **Effect of Decreasing:** Makes the altitude hold safer and smoother, but less capable of handling extreme vertical wind.

### Use Case Recommendations
*   **Standard Drone:** **Keep at 0.** Most modern builds don't need this clamp.
*   **Large-Scale VTOL / Passenger Drones:** **Set to 500 (50%).** Ensures that no software glitch or sensor spike can command more than half-throttle correction instantly, providing a smoother ride.
*   **Indoor / Research Drones:** **Set to 300 (30%).** A safe setting for testing new code where you want to limit how much the drone can "jump" if a sensor fails.

### Troubleshooting
*   **Scenario:** Drone is very slow to recover from a vertical drop, even though `PSC_ACCZ_P` is high.
    *   **Diagnosis:** `PSC_ACCZ_PDMX` might be set too low, capping the controller's authority.
    *   **Fix:** Increase `PSC_ACCZ_PDMX` or set it to 0.
