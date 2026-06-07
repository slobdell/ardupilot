---
layout: parameter
name: PSC_VELZ_D
display_name: Position Control Velocity (Vertical) D Gain
description: Derivative gain for the vertical velocity loop. Provides vertical velocity damping to smooth out altitude changes and reduce vertical bobbing.
default_value: 0.0
range: 0.0 1.0
units: 
group: PSC
visual_asset_id: psc_velz_d_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L173
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_Basic.cpp#L36
---

# Position Control Velocity (Vertical) D Gain (PSC_VELZ_D)

## Description
`PSC_VELZ_D` acts as a vertical damper for the drone's climb and descent rates. It works in the middle loop of the altitude controller to smooth out the transition between climbing and hovering.

By looking at how fast the vertical velocity error is changing, the D-term can "predict" when the drone is about to reach its target speed and begin braking early. This prevents the drone from "launching" past its target altitude and then having to correct back down.

*   **Note:** Just like the vertical I-term, this is often set to **0.0** in standard configurations. The natural damping of the propellers and the high-frequency response of the innermost acceleration loop are usually sufficient for vertical stability.
*   **Too Low:** The drone may overshoot its climb rate setpoint, leading to slightly jerky vertical movement.
*   **Too High:** Can introduce high-frequency motor noise and vibration, as the controller over-reacts to tiny vertical speed fluctuations (e.g., from Baro noise).

## The Mathematics
This parameter scales the derivative of the vertical velocity error:

$$ \vec{A}_{z\_target} += k_D \cdot \text{Filter}\left( \frac{d(V_{z\_target} - V_{z\_current})}{dt} \right) $$ 

Where:
*   $k_D$ is `PSC_VELZ_D`.
*   $	ext{Filter}(\dots)$ is a low-pass filter (set by `PSC_VELZ_FLTD`) to clean up the derivative signal.

## The Engineer's View
This parameter is the `_kd` member of the `_pid_vel_z` object inside `AC_PosControl`.

It is executed in `AC_PID_Basic::update_all()`:

```cpp
// AC_PID_Basic.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = _last_derivative + (dt / (_filt_D_hz + dt)) * (derivative - _last_derivative);
}
return ... + _derivative * _kd;
```

Vertical damping is typically handled by the innermost `PSC_ACCZ_D` gain first, with `PSC_VELZ_D` acting as a secondary, slower damping layer.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** Smoother vertical starts and stops. Less "vertical bobbing" during aggressive climbs.
*   **Effect of Decreasing:** Maximum vertical responsiveness, but potential for "bounce" when stopping a climb.

### Use Case Recommendations
*   **Standard Build:** **Keep at 0.0.** Vertical aerodynamics usually provide enough damping.
*   **Large, Low-RPM Propellers:** **Consider 0.05 - 0.1.** Large props have high vertical "surge" and slow response; a small amount of velocity damping can help level them out.
*   **Precision Lifting / Construction:** **Increase to 0.1.** Helps the drone move vertically in a very deliberate, smooth manner.

### Troubleshooting
*   **Scenario:** Drone oscillates vertically at a moderate speed (once every 0.5 seconds) specifically when you let go of the throttle stick.
    *   **Diagnosis:** Inadequate vertical damping.
    *   **Fix:** Increment `PSC_VELZ_D` by 0.02 and see if the settle time improves.
