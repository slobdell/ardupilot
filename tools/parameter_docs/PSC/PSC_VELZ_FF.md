---
layout: parameter
name: PSC_VELZ_FF
display_name: Position Control Velocity (Vertical) Feed-Forward
description: Feed-forward gain for the vertical velocity loop. Directly maps desired climb/descent rate to a target acceleration, bypassing the error-correction step for faster vertical response.
default_value: 0.0
range: 0 1.0
units: 
group: PSC
visual_asset_id: psc_velz_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L173
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_Basic.cpp#L44
---

# Position Control Velocity (Vertical) Feed-Forward (PSC_VELZ_FF)

## Description
`PSC_VELZ_FF` provides "pre-emptive" vertical force. While the P and I terms in the vertical velocity loop wait for the drone to *miss* its target speed before they act, the Feed-Forward (FF) term acts the moment you move the throttle stick.

If you command a 1 m/s climb, the FF term instantly calculates a requested acceleration to start the drone moving upward. This significantly reduces the vertical "sag" or "delay" felt in altitude-controlled modes (AltHold, Loiter).

*   **Standard Build:** Often set to **0.0** because the shaper and high vertical P-gain handle most situations.
*   **Performance Build:** A small amount of FF makes altitude changes feel "punchier" and more professional.

## The Mathematics
The FF term is proportional to the vertical speed target:

$$ \vec{A}_{z\_target\_FF} = \vec{V}_{z\_target} \cdot k_{FF} $$

Where:
*   $\vec{V}_{z\_target}$ is the commanded climb/descent rate.
*   $k_{FF}$ is `PSC_VELZ_FF`.

## The Engineer's View
This parameter maps to `_kff` in the `_pid_vel_z` object.

It is applied in `AC_PosControl::update_z_controller()`:

```cpp
// AC_PosControl.cpp
_vel_target.z += _vel_desired.z + _vel_offset.z + _vel_terrain;
// ...
_accel_target.z = _pid_vel_z.update_all(_vel_target.z, curr_vel_z, ...);
```

The `AC_PID_Basic` library includes the FF term in its final output calculation. It effectively "leads" the acceleration target, reducing the work the P-term has to do.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** Snappier response to throttle stick changes. Less vertical altitude loss at the start of a climb.
*   **Effect of Decreasing:** Smoother, more damped vertical movement.

### Use Case Recommendations
*   **Heavy Cargo VTOL:** **Set to 0.1.** Helps the drone overcome the huge vertical inertia of a heavy frame to start moving the moment the command is given.
*   **FPV Freestyle in Loiter:** **Set to 0.2.** Makes vertical "pops" feel more like a manual Acro quad.
*   **Standard GPS Photography:** **Keep at 0.0.** Smoothness is priority; raw stick-to-acceleration mapping can sometimes be too "jumpy."

### Troubleshooting
*   **Scenario:** When you push the throttle stick up, the drone "jumps" up suddenly and then settles into the climb rate.
    *   **Diagnosis:** `PSC_VELZ_FF` is too high (initial jerk overshoot).
    *   **Fix:** Reduce `PSC_VELZ_FF` or set to 0.0.
