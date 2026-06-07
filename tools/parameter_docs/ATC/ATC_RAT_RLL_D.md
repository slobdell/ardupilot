---
layout: parameter
name: ATC_RAT_RLL_D
display_name: Roll Axis Rate D Gain
description: Derivative gain for the roll rate controller. Acts as a "damper" to stop rotations quickly and prevent the drone from bouncing back after a sharp turn.
default_value: 0.0036
range: 0.0 0.05
units: 
group: ATC
visual_asset_id: atc_rat_rll_d_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L23
---

# Roll Axis Rate D Gain (ATC_RAT_RLL_D)

## Description
`ATC_RAT_RLL_D` is the vertical "shock absorber" for your drone's rotation. In physics, the **Derivative (D)** term looks at how fast the error is changing. 

If you command a sharp 180-degree roll and then stop the stick, the drone has a massive amount of rotating momentum. Without D-gain, the P-gain would try to stop the drone, but it would shoot past the target angle and then "bounce back." The D-gain "notices" that the drone is rotating very fast toward its target and applies the brakes early to ensure a perfectly smooth, non-bouncing stop.

*   **Low Value:** The drone will "bounce" or "wag" its wings when you stop a roll. It feels loose and imprecise during fast maneuvers.
*   **High Value:** The drone feels extremely rigid and "on rails." Stops are instantaneous.
*   **Too High:** The drone will emit a high-pitched "shriek" from the motors. This is caused by the D-term amplifying tiny sensor vibrations (noise) and trying to correct them hundreds of times per second. This can burn out your motors and ESCs in seconds.

## The Mathematics
The D-term is proportional to the rate of change of the rate error:

$$ \text{Out}_D = k_D \cdot \frac{d(\omega_{target} - \omega_{actual})}{dt} $$

Where:
*   $k_D$ is `ATC_RAT_RLL_D`.
*   The derivative is heavily filtered by `ATC_RAT_RLL_FLTD` to prevent noise amplification.

**Intuition:** If the error is getting smaller very quickly (you are nearly at your target rate), the derivative is negative. This causes the D-term to subtract from the total motor power, "braking" the rotation so you don't overshoot.

## The Engineer's View
This parameter is the `_kd` member of the `_pid_rate_roll` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    // ... filtering happens here ...
    _derivative = filtered_derivative;
}
return ... + _derivative * _kd;
```

Modern ArduPilot versions also feature **D-Term Tapering**, which reduces the D-gain at high throttle to prevent the increased motor noise at high RPM from causing "D-gain blowouts."

## Tuning & Behavior
*   **Default Value:** 0.0036 (Very sensitive!)
*   **Range:** 0.0 - 0.05
*   **Effect of Increasing:** Crisper stops, less bounce-back after flips, "robotic" handling.
*   **Effect of Decreasing:** Softer handling, more "organic" movement, safer for motors on high-vibration frames.

### Use Case Recommendations
*   **FPV Freestyle:** **Increase to 0.005 - 0.008.** Essential for "snappy" flips and rolls where the drone must stop perfectly level.
*   **Large Professional Drones (>15 inch props):** **Keep very low or set to 0.0.** Large props are too slow to react to derivative changes; D-gain here usually just creates heat and "prop wash" oscillations.
*   **Cinematography:** **Keep at Default.** Provides just enough damping for a stable horizon without introducing high-frequency jitters.

### Troubleshooting
*   **Scenario:** You finish a roll, and the drone's wings "wobble" once or twice before settling.
    *   **Diagnosis:** `ATC_RAT_RLL_D` is too low.
    *   **Fix:** Increase `ATC_RAT_RLL_D` by 0.0005.
*   **Scenario:** Motors sound like they are "grinding" or "chirping" even in a hover.
    *   **Diagnosis:** `ATC_RAT_RLL_D` is too high (Vibration amplification).
    *   **Fix:** Reduce `ATC_RAT_RLL_D` immediately.