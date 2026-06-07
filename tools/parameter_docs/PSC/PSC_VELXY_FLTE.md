---
layout: parameter
name: PSC_VELXY_FLTE
display_name: Position Control Velocity (XY) Error Filter
description: Low-pass filter frequency (in Hz) applied to the velocity error. Smooths out sensor noise (GPS/EKF) before it reaches the PID controller.
default_value: 5.0
range: 0 100
units: Hz
group: PSC
visual_asset_id: psc_velxy_flte_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1066
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_2D.cpp#L33
---

# Position Control Velocity (XY) Error Filter (PSC_VELXY_FLTE)

## Description
`PSC_VELXY_FLTE` is a "noise cleaner" for the velocity controller. It applies a low-pass filter to the velocity error (the difference between where you want to fly and where the EKF thinks you are flying).

GPS and EKF velocity estimates are never perfectly smooth; they contain high-frequency noise and "jitter." Without this filter, the PID controller would try to react to every tiny jitter, causing the motors to vibrate and the drone to feel "nervous."

*   **Higher Frequency (e.g., 20Hz):** The controller reacts faster to real velocity changes, but is more likely to pass noise to the motors.
*   **Lower Frequency (e.g., 2Hz):** The drone feels much smoother and "heavy," but there is more lag in the control response.
*   **Too Low:** Introduces so much "phase lag" that the drone may become unstable and start to orbit its target (toilet bowling).

## The Mathematics
This parameter defines the Cutoff Frequency ($f_c$) of a single-pole low-pass filter. The filter coefficient ($\alpha$) is calculated as:

$$ \alpha = \frac{dt}{dt + RC} \quad \text{where } RC = \frac{1}{2\pi f_c} $$

The filtered error is then updated every time step:

$$ \vec{V}_{err\_filtered} = \vec{V}_{err\_prev} + \alpha \cdot (\vec{V}_{err\_raw} - \vec{V}_{err\_prev}) $$

Where:
*   $f_c$ is `PSC_VELXY_FLTE`.
*   $\vec{V}_{err\_raw}$ is the unfiltered error ($V_{target} - V_{current}$). 

## The Engineer's View
This parameter maps to `_filt_E_hz` in the `_pid_vel_xy` object.

It is applied in `AC_PID_2D::update_all()`:

```cpp
// AC_PID_2D.cpp
_error += ((_target - measurement) - _error) * get_filt_E_alpha(dt);
```

By filtering the error *before* the P, I, and D calculations, ArduPilot ensures that the entire PID loop operates on a consistent, smooth signal.

## Tuning & Behavior
*   **Default Value:** 5.0 Hz
*   **Range:** 0 - 100 Hz
*   **Effect of Increasing:** Sharper control, better wind rejection, but increases motor noise and heat.
*   **Effect of Decreasing:** Smoother flight, quieter motors, but increases control lag and "drifting" tendency.

### Use Case Recommendations
*   **Standard GPS Drones:** **Keep Default (5.0 Hz).** This is the sweet spot for typical GPS-based navigation.
*   **Optical Flow / Indoor:** **Increase to 10.0 Hz.** Optical flow often provides a cleaner, higher-rate velocity estimate than GPS, allowing for a higher filter cutoff and tighter control.
*   **Large, Flexible Frames:** **Decrease to 3.0 Hz.** If the drone's arms or frame are flexible, they can vibrate at 10-15Hz. Lowering the filter frequency prevents the position controller from exciting these mechanical resonances.

### Troubleshooting
*   **Scenario:** Drone oscillates slowly (1-2 Hz) in Loiter, drawing circles in the air.
    *   **Diagnosis:** `PSC_VELXY_FLTE` is likely too low (Phase Lag instability).
    *   **Fix:** Increase `PSC_VELXY_FLTE` to 7.0 or 10.0.
