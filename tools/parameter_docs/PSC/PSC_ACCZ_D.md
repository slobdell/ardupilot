---
layout: parameter
name: PSC_ACCZ_D
display_name: Position Control Acceleration (Vertical) D Gain
description: Derivative gain for the vertical acceleration loop. Provides damping to prevent rapid vertical oscillations and improves motor response to turbulence.
default_value: 0.0
range: 0.0 0.4
units: 
group: PSC
visual_asset_id: psc_accz_d_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L23
---

# Position Control Acceleration (Vertical) D Gain (PSC_ACCZ_D)

## Description
`PSC_ACCZ_D` is the vertical "shock absorber." It provides damping to the vertical movement by reacting to how fast the vertical acceleration is changing. It is primarily used to stop the drone from "ringing" or bouncing vertically when it hits its target altitude.

In many standard builds, this parameter is set to **0.0** because the air itself provides enough natural damping for the vertical axis. However, for high-performance or very large vehicles, a small amount of D-gain can significantly clean up vertical tracking.

*   **Low Value (0.0):** Standard vertical behavior. Relies on physics and P-gain for stabilization.
*   **High Value:** Stiffens the vertical response. Makes the drone feel "locked" to its height even in turbulent air.
*   **Too High:** Amplifies IMU noise and motor vibrations, causing the motors to "chirp" or heat up rapidly without any visible movement of the drone.

## The Mathematics
This parameter scales the derivative of the acceleration error.

$$ \text{Throttle}_{out} += k_D \cdot \frac{d(\vec{A}_{z\_error})}{dt} $$

Where:
*   $\vec{A}_{z\_error} = \vec{A}_{z\_target} - \vec{A}_{z\_measured}$.
*   $k_D$ is `PSC_ACCZ_D`.

**Filter dependency:** Just like the horizontal D-term, the vertical D-term is extremely sensitive to noise. It is heavily dependent on the `PSC_ACCZ_FLTD` filter to prevent motor damage.

## The Engineer's View
This parameter is the `_kd` member of the `_pid_accel_z` object inside `AC_PosControl`.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float derivative = (error - _last_error) / dt;
    _derivative = _last_derivative + (dt / (_filt_D_hz + dt)) * (derivative - _last_error) / dt;
}
return ... + _derivative * _kd;
```

Note that the derivative is filtered using a low-pass filter defined by `PSC_ACCZ_FLTD`. Without this filter, the D-term would be unusable due to the high vibration levels found in multirotors.

## Tuning & Behavior
*   **Default Value:** 0.0
*   **Range:** 0.0 - 0.4
*   **Effect of Increasing:** Reduces vertical "bounce" at the end of a climb or descent. Better stability in ground effect.
*   **Effect of Decreasing:** Smoother, quieter motor operation.

### Use Case Recommendations
*   **Small High-Performance Drones:** **Increase to 0.05 - 0.1.** Helps the drone stop exactly on its altitude target after aggressive maneuvers.
*   **Heavy Lift / Cinematic:** **Keep at 0.0.** Large props are slow to react; adding D-gain here usually just creates heat without improving tracking.
*   **High Turbulence / High Wind:** **Increase to 0.1.** Provides additional authority to fight vertical gusts.

### Troubleshooting
*   **Scenario:** Vertical height hold is perfect, but motors sound "scratchy" or "grind-y" in Loiter.
    *   **Diagnosis:** `PSC_ACCZ_D` is too high, amplifying IMU noise into the ESCs.
    *   **Fix:** Set `PSC_ACCZ_D` to 0.0.
