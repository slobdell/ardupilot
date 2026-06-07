---
layout: parameter
name: ATC_RAT_PIT_FLTD
display_name: Pitch Axis Rate D-Term Filter
description: Low-pass filter frequency (in Hz) applied specifically to the derivative (D) term of the pitch controller. Protects motors from noise amplification caused by the D-gain.
default_value: 0.0
range: 0 100
units: Hz
group: ATC
visual_asset_id: atc_rat_pit_fltd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L59
---

# Pitch Axis Rate D-Term Filter (ATC_RAT_PIT_FLTD)

## Description
`ATC_RAT_PIT_FLTD` is a specialized safety filter for your drone's pitch damping. In a PID loop, the **Derivative (D)** term is extremely sensitive to noise because it looks at the *rate of change* between gyro samples. High-frequency vibrations from the motors look like massive pitch rotation rates to the D-term.

Without this filter, the D-gain (`ATC_RAT_PIT_D`) would amplify that motor noise, causing the motors to "chirp," get hot, and potentially burn out. This filter specifically cleans up the signal before it gets multiplied by the D-gain, stripping out high-frequency "jitter" while leaving the actual movements of the drone intact.

*   **Higher Frequency (e.g., 40Hz):** Effective damping, prevents "nose-bobbing" at the end of maneuvers, but increases motor heat.
*   **Lower Frequency (e.g., 10Hz):** Safe for older or noisy frames, but the pitch damping will feel "laggy" and may not stop the drone from bouncing after a movement.
*   **Disabled (0):** Defaults to half of the main error filter or a safe internal value.

## The Mathematics
The D-term calculates the derivative of the pitch error and then passes it through a low-pass filter:

$$ D_{filtered} = D_{prev} + \alpha \cdot \left( \frac{E - E_{prev}}{dt} - D_{prev} \right) $$

Where the filter coefficient $\alpha$ is derived from `ATC_RAT_PIT_FLTD` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Engineer's Tip:** In a stable tune, the D-filter frequency is almost always lower than the Error filter frequency (`ATC_RAT_PIT_FLTE`) because the derivative process is naturally "noisier."

## The Engineer's View
This parameter maps to `_filt_D_hz` in the `_pid_rate_pitch` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = _last_derivative + (dt / (_filt_D_hz + dt)) * (derivative - _last_derivative);
}
return ... + _derivative * _kd;
```

Modern ArduPilot versions run these calculations at the full loop rate, allowing for high-precision noise rejection that is specifically tuned for the resonant frequencies of the longitudinal frame.

## Tuning & Behavior
*   **Default Value:** 0.0 (Internal auto-selection)
*   **Range:** 0.0 - 100.0 Hz
*   **Effect of Increasing:** Crisper pitch stops, less "bounce" when you let go of the stick.
*   **Effect of Decreasing:** Quieter motor operation, longer motor life, and less risk of "prop wash" jitters.

### Use Case Recommendations
*   **Clean Cinematic Drone:** **Set to 15.0 - 20.0 Hz.** Provides excellent damping for the horizon without introducing high-frequency noise.
*   **FPV Racing (Rigid Frame):** **Set to 30.0 - 40.0 Hz.** Necessary for the "instant stop" handling required for racing.
*   **Large Professional Rig (>18 inch props):** **Set to 5.0 - 10.0 Hz.** Large props generate significant low-frequency noise; keeping the D-filter low prevents heating.

### Troubleshooting
*   **Scenario:** Motors are getting warm and making a rhythmic "growling" sound specifically during vertical descent.
    *   **Diagnosis:** D-term noise from the pitch axis.
    *   **Fix:** Reduce `ATC_RAT_PIT_FLTD` by 5.0 Hz.