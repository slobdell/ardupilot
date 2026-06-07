---
layout: parameter
name: PSC_ACCZ_FLTD
display_name: Position Control Acceleration (Vertical) D-Term Filter
description: Low-pass filter frequency (in Hz) applied to the derivative term of the vertical acceleration loop. Protects motors from noise amplification caused by the vertical D-gain.
default_value: 0.0
range: 0 100
units: Hz
group: PSC
visual_asset_id: psc_accz_fltd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L59
---

# Position Control Acceleration (Vertical) D-Term Filter (PSC_ACCZ_FLTD)

## Description
`PSC_ACCZ_FLTD` is the specific filter for the vertical **Derivative (D) gain**.

In the altitude controller, the D-gain (`PSC_ACCZ_D`) acts as a damper to stop the drone from bouncing. However, the derivative calculation (which looks at the rate of change) is extremely sensitive to motor vibration. Without a filter, even a tiny D-gain would amplify IMU noise so much that the motors would oscillate at hundreds of Hertz, potentially causing fire or mechanical failure.

*   **Standard Build:** If `PSC_ACCZ_D` is 0, this parameter does nothing.
*   **High Performance:** If you use D-gain to stabilize a heavy or high-power vehicle, you *must* set this filter to a sensible value (e.g. 10-20Hz).
*   **Default (0):** The filter is effectively disabled or follows the main error filter.

## The Mathematics
The D-term calculates the derivative of the error, then passes it through this low-pass filter:

$$ \vec{D}_{filtered} = \vec{D}_{prev} + \alpha \cdot \left( \frac{d(\vec{A}_{err})}{dt} - \vec{D}_{prev} \right) $$

Where the filter coefficient $\alpha$ is calculated from `PSC_ACCZ_FLTD` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

## The Engineer's View
This parameter maps to `_filt_D_hz` in the `_pid_accel_z` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = _last_derivative + (dt / (_filt_D_hz + dt)) * (derivative - _last_derivative);
}
```

The frequency is typically set lower than the main error filter because the derivative calculation inherently "creates" noise by looking at infinitesimal changes between samples.

## Tuning & Behavior
*   **Default Value:** 0.0 Hz (Disabled/Auto)
*   **Range:** 0.0 - 100.0 Hz
*   **Effect of Increasing:** Allows the D-term to react faster to "thumps" or turbulence, but increases motor heating.
*   **Effect of Decreasing:** Smoother vertical behavior, but the D-term becomes less effective at stopping vertical bounces.

### Use Case Recommendations
*   **Most Multirotors:** **Keep at 0.0.** Unless you are manually tuning `PSC_ACCZ_D`, this filter is not needed.
*   **Heavy Industrial Drones:** **Set to 10.0 Hz (if using D-gain).** Provides a clean signal for the damper to work without excites frame resonances.
*   **Autonomous Landing on Ships/Moving Targets:** **Set to 20.0 Hz.** Allows for the high-authority damping needed when the drone must "snap" to a height target as the platform moves beneath it.

### Troubleshooting
*   **Scenario:** You increased `PSC_ACCZ_D` and now the motors are making a high-pitched "singing" noise.
    *   **Diagnosis:** High-frequency derivative noise.
    *   **Fix:** Decrease `PSC_ACCZ_FLTD` to 5.0 or 7.0 Hz.
