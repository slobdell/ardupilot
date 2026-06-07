---
layout: parameter
name: ATC_RAT_RLL_FLTD
display_name: Roll Axis Rate D-Term Filter
description: Low-pass filter frequency (in Hz) applied specifically to the derivative (D) term of the roll controller. Essential for preventing motor overheating on frames with vibration.
default_value: 0.0
range: 0 100
units: Hz
group: ATC
visual_asset_id: atc_rat_rll_fltd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L59
---

# Roll Axis Rate D-Term Filter (ATC_RAT_RLL_FLTD)

## Description
`ATC_RAT_RLL_FLTD` is arguably the most important safety filter on your drone. In a PID loop, the **Derivative (D)** term is exceptionally sensitive to noise because it looks at the *rate of change* between samples. Small high-frequency vibrations that the P-term ignores look like massive rotation rates to the D-term.

Without this filter, the D-gain would amplify motor noise so aggressively that your motors would "chirp," get hot, and potentially burn out within seconds of taking off. This filter specifically targets the signal used for D-gain, stripping out high-frequency "jitter" while leaving the drone's actual movements intact.

*   **Higher Frequency (e.g., 40Hz):** Effective damping, stops flips instantly, but high risk of motor heat.
*   **Lower Frequency (e.g., 10Hz):** Safe for noisy frames, but the D-gain will feel "laggy" and may not stop the drone from bouncing after a maneuver.
*   **Disabled (0):** Defaults to half of the main error filter or a safe internal value.

## The Mathematics
The D-term calculates the derivative of the error, then passes it through a single-pole low-pass filter:

$$ D_{filtered} = D_{prev} + \alpha \cdot \left( \frac{E - E_{prev}}{dt} - D_{prev} \right) $$

Where the filter coefficient $\alpha$ is derived from `ATC_RAT_RLL_FLTD` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Engineer's Tip:** The D-filter frequency should almost always be lower than (or equal to) the Error filter frequency (`ATC_RAT_RLL_FLTE`) because the derivative process itself creates high-frequency noise.

## The Engineer's View
This parameter maps to `_filt_D_hz` in the `_pid_rate_roll` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = _last_derivative + (dt / (_filt_D_hz + dt)) * (derivative - _last_derivative);
}
return ... + _derivative * _kd;
```

Modern ArduPilot versions run these filters at the loop rate (e.g., 400Hz), which allows for very precise noise rejection without introducing excessive control lag.

## Tuning & Behavior
*   **Default Value:** 0.0 (Internal auto-selection, usually 20-30Hz)
*   **Range:** 0.0 - 100.0 Hz
*   **Effect of Increasing:** Better "snap" at the end of maneuvers. Tighter control.
*   **Effect of Decreasing:** Quieter motors, longer motor life, less susceptible to prop-wash oscillation.

### Use Case Recommendations
*   **FPV Racing (Rigid Frame):** **Set to 30.0 - 50.0 Hz.** High performance requires a high D-cutoff to stop rotations instantly.
*   **10-inch Multirotor (Gimbal):** **Set to 15.0 - 20.0 Hz.** Provides a smooth, non-vibrating base for photography.
*   **Large Heavy Lift (>22 inch props):** **Set to 5.0 - 10.0 Hz.** Low frequencies are required to avoid exciting the resonant "ringing" of long carbon fiber arms.

### Troubleshooting
*   **Scenario:** Motors are making a high-pitched "grinding" sound and coming down hot to the touch.
    *   **Diagnosis:** D-term noise amplification.
    *   **Fix:** Reduce `ATC_RAT_RLL_FLTD` by 5.0 Hz increments until the motors are cool.