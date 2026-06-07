---
layout: parameter
name: ATC_RAT_PIT_D
display_name: Pitch Axis Rate D Gain
description: Derivative gain for the pitch rate controller. Dampens forward/backward rotation to prevent overshoot and bouncing.
default_value: 0.0036
range: 0.0 0.05
units: 
group: ATC
visual_asset_id: atc_rat_pit_d_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L23
---

# Pitch Axis Rate D Gain (ATC_RAT_PIT_D)

## Description
`ATC_RAT_PIT_D` is the vertical "damper" for your drone's nose. In physics, the **Derivative (D)** term acts like a brake that only activates when the drone is moving too fast toward its target.

If you command the drone to level out after a fast forward dash, it has a lot of pitch momentum. Without D-gain, the nose would swing back up, shoot past the level point, and then "bob" (oscillate) several times before settling. The D-gain "senses" this rapid swing and adds pre-emptive resistance, ensuring the drone stops perfectly level on the first try.

*   **Low Value:** The drone will "bob its head" like a toy when you stop pitching. It feels loose and bouncy in the air.
*   **High Value:** The drone feels extremely stable and "robotic." Flips stop exactly where you want them.
*   **Too High:** The drone will emit a high-pitched "growl" or motor shriek. This is dangerous as it can overheat the motors and ESCs within seconds.

## The Mathematics
The D-term is proportional to how fast the pitch error is changing:

$$ \text{Out}_D = k_D \cdot \frac{d(\omega_{target} - \omega_{actual})}{dt} $$

Where:
*   $k_D$ is `ATC_RAT_PIT_D`.
*   The signal is passed through the `ATC_RAT_PIT_FLTD` filter to remove noise.

**Intuition:** The D-term opposes the *speed* of the rotation. If you are rotating too fast toward the target, the D-term pushes *against* the movement to slow it down before you overshoot.

## The Engineer's View
This parameter is the `_kd` member of the `_pid_rate_pitch` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = filtered_derivative;
}
return ... + _derivative * _kd;
```

In multirotors, the Pitch axis often needs slightly different D-gain than the Roll axis because the weight of the drone (battery and camera) is usually distributed along the longitudinal axis, creating a different moment of inertia.

## Tuning & Behavior
*   **Default Value:** 0.0036 (Highly sensitive)
*   **Range:** 0.0 - 0.05
*   **Effect of Increasing:** Crisper stops after forward flight. Less vertical altitude loss during hard braking.
*   **Effect of Decreasing:** Smoother, "softer" flight feel. Safer for older motors or low-quality propellers.

### Use Case Recommendations
*   **Large Professional Multirotors:** **Keep very low or set to 0.0.** Large props cannot physically react fast enough for D-gain to be effective; it usually just causes wasted heat.
*   **FPV Racing / Cinema Whoops:** **Increase to 0.006 - 0.008.** High performance depends on the drone stopping its pitch exactly on command to maintain the correct forward speed.
*   **Long-Range Mapping:** **Keep at Default.** Provides a stable platform without motor stress.

### Troubleshooting
*   **Scenario:** Drone nose "bobs" up and down 2-3 times every time you release the pitch stick.
    *   **Diagnosis:** `ATC_RAT_PIT_D` is too low (Underdamped).
    *   **Fix:** Increase `ATC_RAT_PIT_D` by 0.0005.
*   **Scenario:** Motors sound like they are "grinding" only when you are hovering in wind.
    *   **Diagnosis:** `ATC_RAT_PIT_D` is too high, amplifying turbulence noise.
    *   **Fix:** Reduce `ATC_RAT_PIT_D` immediately.