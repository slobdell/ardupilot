---
layout: parameter
name: PSC_VELXY_D
display_name: Position Control Velocity (XY) D Gain
description: Derivative gain for the velocity controller. Acts as a "damper" or "shock absorber" to reduce overshoot and oscillation when correcting velocity errors.
default_value: 0.5
range: 0.0 1.0
units: 
group: PSC
visual_asset_id: psc_velxy_d_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1066
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_2D.cpp#L34
---

<!-- 
  NOTE: This file is a manually investigated Golden Sample based on Source Code Truth.
-->

# Position Control Velocity (XY) D Gain (PSC_VELXY_D)

## Description
The `PSC_VELXY_D` parameter provides **Damping** to the velocity controller. It reacts to the *rate of change* of the error. If the drone is rapidly approaching the target velocity, the D-term counter-acts the P-term to slow down the reaction, preventing it from shooting past the target.

Think of it as the shock absorbers on a car. Without them (`D=0`), the car bounces (oscillates) after a bump. With them, it settles quickly.

*   **Too Low:** The drone may overshoot the target velocity and "wobble" before settling.
*   **Too High:** The drone amplifies sensor noise (vibrations), causing rapid, high-frequency twitching in the motors and potentially overheating them.

## The Mathematics
This parameter scales the filtered derivative of the error.

$$ \vec{A}_{target} += k_D \cdot \text{Filter}\left( \frac{d(\vec{V}_{error})}{dt} \right) $$

Where:
*   $\frac{d(\vec{V}_{error})}{dt}$ is the rate of change of the velocity error.
*   $\text{Filter}(\dots)$ is a low-pass filter (set by `PSC_VELXY_FLTD`) to remove high-frequency noise.
*   $k_D$ is `PSC_VELXY_D`.

**Significance:** The D-term opposes rapid changes. If the error is decreasing quickly (you are fixing the problem), the derivative is negative, so the D-term subtracts from the output, "braking" the correction to prevent overshoot.

## The Engineer's View
This parameter is the `_kd` member of the `_pid_vel_xy` object in `AC_PosControl`.

It is executed in `AC_PID_2D::update_all()`:

```cpp
// AC_PID_2D.cpp
if (is_positive(dt)) {
    const Vector2f derivative{(_error - error_last) / dt};
    _derivative += (derivative - _derivative) * get_filt_D_alpha(dt);
}
// ...
return ... + _derivative * _kd ...;
```

The derivative calculation relies on a clean `dt` (time step) and is heavily dependent on the input filter frequency (`PSC_VELXY_FLTD`) to be usable on a real flying vehicle.

## Tuning & Behavior
*   **Default Value:** 0.5 (Standard Copter)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** Reduces overshoot, makes stops look "crisper" and more robotic. Increases susceptibility to vibration noise.
*   **Effect of Decreasing:** Softer stops, potential for "bounce-back" or low-frequency wobble.

### Use Case Recommendations
*   **Large Propellers (>15 inch):** **Decrease to 0.1 - 0.3.**
    *   *Why:* Large props have high inertia and slow response times. A high D-term tries to force rapid changes they can't physically achieve, leading to motor overheating.
*   **Small Racers (<5 inch):** **Increase to 0.6 - 0.8.**
    *   *Why:* Low inertia allows for rapid response; high D-term locks the velocity in "on rails".
*   **General:** **Keep Default (0.5).**

### Practical Tuning Tip
Tune `P` first until you see oscillation, then increase `D` to dampen it. If you hear a high-pitched grinding sound from the motors (noise amplification), reduce `D` immediately.

