---
layout: parameter
name: PSC_ACCZ_D_FF
display_name: Position Control Acceleration (Vertical) Derivative Feed-Forward
description: Derivative feed-forward gain for the vertical acceleration loop. Provides pre-emptive motor correction based on how quickly the acceleration target is changing.
default_value: 0.0
range: 0 0.02
units: 
group: PSC
visual_asset_id: psc_accz_d_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L81
---

# Position Control Acceleration (Vertical) Derivative Feed-Forward (PSC_ACCZ_D_FF)

## Description
`PSC_ACCZ_D_FF` is an advanced "predictive" term for vertical flight. While standard Feed-Forward (`PSC_ACCZ_FF`) looks at the target acceleration itself, the **Derivative Feed-Forward (D_FF)** looks at how fast the *target* is changing.

Think of it as the "lookahead" for a vertical punch. If the software suddenly requests a massive increase in acceleration, the D_FF term instantly adds a burst of throttle to help the motors overcome the inertia of the propellers. It helps the drone "lead" into a maneuver before any error has even occurred.

*   **Low Value (0.0):** Standard behavior. The drone accelerates as commanded by the shaper.
*   **High Value:** Creates a very aggressive vertical response. The drone "snaps" into climbs and descents.
*   **Too High:** Can cause "kickback" or jerky movements, as the drone over-predicts the needed force.

## The Mathematics
The D_FF term is proportional to the derivative of the target signal ($A_{z\_target}$):

$$ \text{Throttle}_{D\_FF} = \frac{d(\vec{A}_{z\_target})}{dt} \cdot k_{D\_FF} $$

Where:
*   $k_{D\_FF}$ is `PSC_ACCZ_D_FF`.
*   $\frac{d(\vec{A}_{z\_target})}{dt}$ is the rate of change of the acceleration setpoint.

This is added to the final throttle sum alongside the P, I, D, and base FF terms.

## The Engineer's View
This parameter maps to `_kdff` in the `_pid_accel_z` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float target_derivative = (target - _last_target) / dt;
    _pid_info.D_FF = target_derivative * _kdff;
}
```

Because it looks at the *target derivative*, it is immune to IMU vibration noise (unlike the standard D-term). However, it is very sensitive to "steps" in the high-level path planner, which is why it's usually used with a well-shaped S-curve.

## Tuning & Behavior
*   **Default Value:** 0.0
*   **Range:** 0.0 - 0.02
*   **Effect of Increasing:** Snappier, more instantaneous vertical transitions. Reduces altitude sag at the start of a climb.
*   **Effect of Decreasing:** Smoother, more organic vertical movement.

### Use Case Recommendations
*   **Acrobatic / FPV Autonomous Flight:** **Increase to 0.005.** Helps the drone track aggressive 3D flight paths where altitude changes are frequent and sharp.
*   **Standard Multirotors:** **Keep at 0.0.** The standard shaper and P-gain are usually sufficient.
*   **High-Speed Vertical Search:** **Increase to 0.01.** If the drone is rapidly oscillating its height to search for an object, D_FF improves the accuracy of those transitions.

### Troubleshooting
*   **Scenario:** Drone makes a distinct "pop" or "click" sound in the motors when starting a vertical movement.
    *   **Diagnosis:** `PSC_ACCZ_D_FF` is likely too high, commanding an impossible step-change in motor torque.
    *   **Fix:** Set back to 0.0.
