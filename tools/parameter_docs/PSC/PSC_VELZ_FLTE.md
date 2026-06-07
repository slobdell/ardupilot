---
layout: parameter
name: PSC_VELZ_FLTE
display_name: Position Control Velocity (Vertical) Error Filter
description: Low-pass filter frequency (in Hz) applied to the vertical velocity error. Smooths out sensor noise (Baro/EKF) before it reaches the climb rate controller.
default_value: 5.0
range: 0 100
units: Hz
group: PSC
visual_asset_id: psc_velz_flte_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L173
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_Basic.cpp#L31
---

# Position Control Velocity (Vertical) Error Filter (PSC_VELZ_FLTE)

## Description
`PSC_VELZ_FLTE` smooths the drone's vertical performance by cleaning up noise in the climb/descent speed measurement. 

Vertical velocity is primarily estimated using a combination of the Barometer and Accelerometers. Barometers are notoriously noisy—they are affected by wind gusts blowing into the drone's frame and even by the drone's own propeller wash. Without this filter, the vertical PID controller would try to react to every tiny "pop" in the pressure sensor, causing the motors to stutter and the drone to sound uneven.

*   **Higher Frequency (e.g. 10Hz):** Faster response to real climb rate changes, but more likely to make the motors sound "jittery."
*   **Lower Frequency (e.g. 2Hz):** Extremely smooth vertical flight, but makes the drone slow to react to changes in terrain.
*   **Default (5Hz):** Optimal for most Baro-based altitude hold systems.

## The Mathematics
This parameter defines the Cutoff Frequency ($f_c$) for a low-pass filter:

$$ \vec{V}_{z\_err\_filtered} = \vec{V}_{z\_err\_prev} + \alpha \cdot (\vec{V}_{z\_err\_raw} - \vec{V}_{z\_err\_prev}) $$

Where the smoothing factor $\alpha$ is:
$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

A lower `PSC_VELZ_FLTE` value creates a smaller $\alpha$, meaning the drone trusts its previous state more than the new (potentially noisy) measurement.

## The Engineer's View
This parameter maps to `_filt_E_hz` in the `_pid_vel_z` object.

It is applied in `AC_PID_Basic::update_all()`:

```cpp
// AC_PID_Basic.cpp
_error += ((target - measurement) - _error) * get_filt_E_alpha(dt);
```

By filtering the vertical error here, ArduPilot ensures that the "Velocity P-Gain" (`PSC_VELZ_P`) acts on a smooth signal, preventing high-frequency throttle oscillations while maintaining a precise hover.

## Tuning & Behavior
*   **Default Value:** 5.0 Hz
*   **Range:** 0.0 - 100.0 Hz
*   **Effect of Increasing:** Snappier throttle response, drone stops its vertical movement more accurately at the cost of motor noise.
*   **Effect of Decreasing:** Quieter, smoother flight; great for cinematography.

### Use Case Recommendations
*   **Standard Build:** **Keep at 5.0 Hz.** This provides excellent results for most users.
*   **Rangefinder-Only Flight (Indoor):** **Increase to 10.0 Hz.** Rangefinders are much cleaner than barometers; you can afford a higher filter frequency to get tighter vertical control.
*   **Large-Scale Survey Drones:** **Keep Default.** Smoothness is more important than millisecond-level vertical accuracy for mapping.

### Troubleshooting
*   **Scenario:** Drone hovers at the right height, but the motors sound like they are "pulsing" or "surging" rapidly.
    *   **Diagnosis:** Baro noise is passing through the filter.
    *   **Fix:** Decrease `PSC_VELZ_FLTE` to 3.0 Hz.
