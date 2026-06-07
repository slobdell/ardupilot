---
layout: parameter
name: ATC_RAT_PIT_PDMX
display_name: Pitch Axis Rate PD Maximum
description: Limits the maximum combined contribution of the Proportional (P) and Derivative (D) terms in the pitch rate loop. Prevents extreme momentary motor torque requests in forward/backward flight.
default_value: 0
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_rat_pit_pdmx_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L73
---

# Pitch Axis Rate PD Maximum (ATC_RAT_PIT_PDMX)

## Description
`ATC_RAT_PIT_PDMX` is a safety clamp for your drone's longitudinal rotation authority.

In a pitch controller, the **P** and **D** terms are responsible for reacting to fast disturbances. If you hit an object or experience a massive headwind gust, the PD math might command an instantaneous motor power jump that exceeds the frame's mechanical limits. 

This parameter sets a ceiling on the combined power of P and D. It ensures that the drone's *immediate* reaction to a pitch error is kept within a safe range, preventing extreme torque spikes that could damage ESCs or frame components.

*   **Low Value:** Limits the drone's "recovery snap" during extreme maneuvers.
*   **High Value:** Allows the drone to use its full potential motor torque for immediate pitch corrections.
*   **Disabled (0):** The PD sum is unlimited (limited only by the physical capabilities of the battery and motors).

## The Mathematics
The P and D terms are summed and then constrained by this value:

$$ \text{PD}_{output} = \text{constrain}(P + D, -\text{PDMX}, \text{PDMX}) $$

Where:
*   $P = k_P \cdot \omega_{pitch\_error}$
*   $D = k_D \cdot \frac{d}{dt}\omega_{pitch\_error}$
*   $\text{PDMX}$ is `ATC_RAT_PIT_PDMX`.

**Note:** The Integral (I) and Feed-Forward (FF) terms are added *after* this clamp. This is critical because it means the drone can still achieve full tilt authority via the I-term, but it won't react with a violent "kick" to high-frequency noise.

## The Engineer's View
This parameter maps to `_kpdmax` in the `_pid_rate_pitch` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(_kpdmax)) {
    float pd_sum = P + D;
    pd_sum = constrain_float(pd_sum, -_kpdmax, _kpdmax);
}
```

By capping the PD sum, ArduPilot allows you to use very high D-gains (for tight damping) without the risk of those high gains creating destructive motor pulses if a sensor glitch occurs.

## Tuning & Behavior
*   **Default Value:** 0 (Unlimited)
*   **Range:** 0 - 1.0 (0 to 100% motor authority)
*   **Effect of Increasing:** Better longitudinal recovery. The drone fights harder to stay level in turbulent air.
*   **Effect of Decreasing:** Smoother, safer pitch behavior. Limits the mechanical "mechanical shock" of the drone's reactions.

### Use Case Recommendations
*   **Large Professional Rig (>10kg):** **Set to 0.5.** Protects the expensive long-arm structure from extreme torsional shocks during abrupt stops.
*   **Cinematography Drone:** **Set to 0.4.** Ensures that any software glitches or sensor spikes produce a limited "kick," keeping the video footage cleaner.
*   **FPV Racing Quad:** **Keep at 0.** You want every available ounce of motor torque for recovery during high-speed gate navigation.

### Troubleshooting
*   **Scenario:** Drone is slow to level its nose after a fast dive, even with high P-gain.
    *   **Diagnosis:** `ATC_RAT_PIT_PDMX` is set too low.
    *   **Fix:** Increase `ATC_RAT_PIT_PDMX` or set it to 0.