---
layout: parameter
name: PSC_VELZ_FLTD
display_name: Position Control Velocity (Vertical) D-Term Filter
description: Low-pass filter frequency (in Hz) applied to the derivative term of the vertical velocity loop. Prevents motor noise when using vertical velocity damping.
default_value: 5.0
range: 0 100
units: Hz
group: PSC
visual_asset_id: psc_velz_fltd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L173
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_Basic.cpp#L38
---

# Position Control Velocity (Vertical) D-Term Filter (PSC_VELZ_FLTD)

## Description
`PSC_VELZ_FLTD` is the specific filter for the vertical **Derivative (D) gain** in the velocity loop. 

Because the D-term (`PSC_VELZ_D`) reacts to the *acceleration* of vertical errors, it is extremely sensitive to sensor noise and air turbulence. Without this filter, the D-term would amplify tiny "jitters" in the barometer signal into large, rapid throttle changes. This filter strips away those high-frequency jitters, ensuring that the damping effect only applies to the real vertical movements of the drone.

*   **Note:** If `PSC_VELZ_D` is 0 (the default), this parameter does nothing.
*   **Safety:** If you do enable vertical velocity damping, you *must* have this filter set to a reasonable value (5-10Hz) to protect your ESCs from noise spikes.

## The Mathematics
The filter is a single-pole low-pass filter applied specifically to the vertical velocity derivative calculation:

$$ \vec{D}_{z\_filtered} = \vec{D}_{z\_prev} + \alpha \cdot \left( \frac{d(V_{z\_err})}{dt} - \vec{D}_{z\_prev} \right) $$

Where the filter coefficient $\alpha$ is derived from `PSC_VELZ_FLTD` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

## The Engineer's View
This parameter maps to `_filt_D_hz` in the `_pid_vel_z` object.

It is applied in `AC_PID_Basic::update_all()`:

```cpp
// AC_PID_Basic.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = _last_derivative + (dt / (_filt_D_hz + dt)) * (derivative - _last_derivative);
}
```

This filter provides a "cushion" for the vertical damping logic, preventing the drone from having an aggressive vertical "bark" when it encounters turbulence.

## Tuning & Behavior
*   **Default Value:** 5.0 Hz
*   **Range:** 0 - 100 Hz
*   **Effect of Increasing:** Allows for higher vertical D-gains with less lag, but risk of motor heat.
*   **Effect of Decreasing:** Smoother vertical damping, but the D-term may become too laggy to stop altitude bobbing.

### Use Case Recommendations
*   **Standard Build:** **Keep at 5.0 Hz.** (If `PSC_VELZ_D` is used).
*   **Large, Low-Frequency Propellers:** **Decrease to 3.0 Hz.** Large props create low-frequency "chuffing" that can easily trigger a noisy D-term.
*   **High-End Autonomy:** **Increase to 10.0 Hz.** Provides the fast vertical damping needed for precision tasks like lidar-based power line inspection.

### Troubleshooting
*   **Scenario:** Motors are getting warm and making a rhythmic "pulsing" sound during vertical descents.
    *   **Diagnosis:** D-term noise from the vertical velocity loop.
    *   **Fix:** Decrease `PSC_VELZ_FLTD` to 4.0 or 3.0 Hz, or reduce `PSC_VELZ_D`.
