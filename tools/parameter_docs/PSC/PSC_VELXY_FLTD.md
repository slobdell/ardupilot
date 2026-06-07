---
layout: parameter
name: PSC_VELXY_FLTD
display_name: Position Control Velocity (XY) D-Term Filter
description: Low-pass filter frequency (in Hz) applied to the derivative term of the velocity controller. Protects motors from high-frequency vibrations amplified by the D-gain.
default_value: 5.0
range: 0 100
units: Hz
group: PSC
visual_asset_id: psc_velxy_fltd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1066
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_2D.cpp#L34
---

# Position Control Velocity (XY) D-Term Filter (PSC_VELXY_FLTD)

## Description
`PSC_VELXY_FLTD` is the "heat shield" for your motors. In a PID loop, the **Derivative (D) term** is extremely sensitive to noise. Because the D-term looks at the *rate of change* of error, small, high-frequency vibrations in the IMU (noise) look like massive velocity changes to the math, leading to "noisy" motor outputs.

This filter specifically targets the D-term calculation, stripping away the high-frequency vibration before it gets amplified by `PSC_VELXY_D`. 

*   **Low Frequency (e.g. 2Hz):** Very smooth, but makes the D-term laggy. This may lead to overshoot because the "damping" effect happens too late.
*   **High Frequency (e.g. 20Hz):** Instant damping, but carries a high risk of "motor chirping" or overheating as vibration noise passes through.
*   **Disabled (0):** The D-term will likely be unusable on any real aircraft due to vibration.

## The Mathematics
The filter is a single-pole low-pass filter applied specifically to the derivative calculation:

$$ \vec{D}_{filtered} = \vec{D}_{prev} + \alpha \cdot \left( \frac{\vec{V}_{err} - \vec{V}_{err\_prev}}{dt} - \vec{D}_{prev} \right) $$

Where the filter coefficient $\alpha$ is derived from `PSC_VELXY_FLTD` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

## The Engineer's View
This parameter maps to `_filt_D_hz` in the `_pid_vel_xy` object.

It is applied in `AC_PID_2D::update_all()`:

```cpp
// AC_PID_2D.cpp
if (is_positive(dt)) {
    const Vector2f derivative{(_error - error_last) / dt};
    _derivative += (derivative - _derivative) * get_filt_D_alpha(dt);
}
```

The output of this filtered derivative is then multiplied by the D-gain: `_derivative * _kd`.

## Tuning & Behavior
*   **Default Value:** 5.0 Hz
*   **Range:** 0 - 100 Hz
*   **Effect of Increasing:** crisper "stops" and tighter damping, at the cost of motor heat/vibration.
*   **Effect of Decreasing:** smoother vertical/horizontal behavior, but may introduce vertical bobbing or "bounce" when stopping.

### Use Case Recommendations
*   **Clean, Low-Vibration Frames:** **Increase to 10.0 Hz.** If you have high-quality motors and excellent balancing, a higher D-filter allows for a more effective D-gain, leading to a "locked-in" feel.
*   **Large, Noisy Vehicles:** **Keep at 5.0 Hz or decrease to 3.0 Hz.** Large props generate significant low-frequency noise that can easily saturate the D-term.
*   **Racing Drones:** **Increase to 15.0 - 20.0 Hz.** Speed is everything; racer pilots accept some motor noise for the sake of instant damping.

### Troubleshooting
*   **Scenario:** Motors are coming down hot after a flight in Loiter, but the tune feels good.
    *   **Diagnosis:** High-frequency vibration is leaking through the D-term.
    *   **Fix:** Decrease `PSC_VELXY_FLTD` to 4.0 or 3.0.
