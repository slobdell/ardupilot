---
layout: parameter
name: PSC_ACCZ_FLTT
display_name: Position Control Acceleration (Vertical) Target Filter
description: Low-pass filter frequency (in Hz) applied to the vertical acceleration target. Smooths out sudden "steps" in the commanded throttle.
default_value: 0.0
range: 0 50
units: Hz
group: PSC
visual_asset_id: psc_accz_fltt_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L47
---

# Position Control Acceleration (Vertical) Target Filter (PSC_ACCZ_FLTT)

## Description
`PSC_ACCZ_FLTT` smooths the "command" signal before it reaches the vertical acceleration loop. 

While other filters (like `PSC_ACCZ_FLTE`) deal with *noise* from the sensors, this filter deals with *jumps* in the code. Because the altitude controller is a cascade of loops, a sudden change in the target altitude (a "step" input) can result in a sudden jump in the requested acceleration. This filter rounds off those sharp edges, ensuring the motors increase their RPM smoothly rather than with a violent "kick."

*   **Low Frequency (e.g. 5Hz):** Very smooth vertical transitions. The drone "wafts" into its movements.
*   **High Frequency (e.g. 40Hz):** Immediate response to target changes. The drone reacts "instantly" to stick inputs.
*   **Default (0):** The filter is typically disabled or follows the main loop rate.

## The Mathematics
This is a low-pass filter applied to the target acceleration ($\vec{A}_{target}$):

$$ \vec{A}_{target\_filtered} = \vec{A}_{target\_prev} + \alpha \cdot (\vec{A}_{target\_raw} - \vec{A}_{target\_prev}) $$

Where $\alpha$ is derived from `PSC_ACCZ_FLTT`:

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Effect:** This effectively acts as a "Time Constant" for the vertical command. A 10Hz filter means the command will reach 63% of its target value in about 16ms.

## The Engineer's View
This parameter maps to `_filt_T_hz` in the `_pid_accel_z` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_target += (target - _target) * get_filt_T_alpha(dt);
```

By filtering the target *at the entry point* of the innermost loop, ArduPilot ensures that the entire acceleration/throttle PID is protected from discontinuous jumps in the software's setpoints.

## Tuning & Behavior
*   **Default Value:** 0.0 Hz (Disabled)
*   **Range:** 0.0 - 50.0 Hz
*   **Effect of Increasing:** Snappier, more "connected" feel to the throttle stick.
*   **Effect of Decreasing:** Smoother, more professional cinematic vertical movement.

### Use Case Recommendations
*   **Standard FPV / General Flying:** **Keep at 0.0.** The existing kinematic shapers (`PSC_JERK_Z`) already provide excellent smoothing.
*   **Smooth Cinematic Reveleals:** **Set to 5.0 Hz.** Adds an extra layer of "organic" smoothness to any automated altitude changes.
*   **Rescue / High-Speed Obstacle Avoidance:** **Keep at 0.0 or set >30Hz.** You want the absolute minimum lag when the avoidance system commands a climb.

### Troubleshooting
*   **Scenario:** Drone feels "disconnected" vertically; there is a noticeable lag between moving the throttle stick and the drone starting to climb.
    *   **Diagnosis:** `PSC_ACCZ_FLTT` is likely set too low.
    *   **Fix:** Increase to 20.0 Hz or set to 0.0.
