---
layout: parameter
name: PSC_VELZ_IMAX
display_name: Position Control Velocity (Vertical) I-Term Maximum
description: The maximum limit for the vertical velocity integrator. Prevents integrator windup by capping how much vertical force the controller can build up to correct climb rate errors.
default_value: 1000
range: 1.0 8.0
units: 
group: PSC
visual_asset_id: psc_velz_imax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L173
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_Basic.cpp#L25
---

# Position Control Velocity (Vertical) I-Term Maximum (PSC_VELZ_IMAX)

## Description
`PSC_VELZ_IMAX` is a safety clamp for the vertical velocity loop. It limits the maximum "correction authority" that the integrator (`PSC_VELZ_I`) can accumulate over time.

While the innermost loop has its own limit (`PSC_ACCZ_IMAX`) for hover throttle, this middle loop limit ensures that the software doesn't "try too hard" to maintain a specific climb rate if the vehicle is physically unable to do so (e.g., if it is carrying an overweight payload or is stuck). It prevents the drone from building up a massive "power surge" that would cause it to rocket upwards if the physical resistance suddenly disappeared.

*   **Standard Build:** Often set to **1000** (full authority), but since the vertical velocity integrator is usually disabled (`I=0`), this parameter often has no practical effect.
*   **Safety:** Always keep this at a reasonable value to prevent runaway vertical commands.

## The Mathematics
The vertical velocity integrator is constrained to this maximum value:

$$ \vec{I}_{new} = \text{constrain}(\vec{I}_{prev} + \text{error} \cdot k_I \cdot dt, -\text{IMAX}, \text{IMAX}) $$

Where:
*   $\text{IMAX}$ is `PSC_VELZ_IMAX`.
*   The output is typically scaled to match the units of vertical acceleration.

## The Engineer's View
This parameter maps to `_kimax` in the `_pid_vel_z` object.

It is applied in `AC_PID_Basic::update_all()`:

```cpp
// AC_PID_Basic.cpp
_integrator = constrain_float(_integrator + (error * _ki * dt), -_kimax, _kimax);
```

Just like the other PID loops in ArduPilot, this integrator is also protected by "Saturation Checking"—it will stop increasing if the output throttle has already reached 100%, regardless of the IMAX setting.

## Tuning & Behavior
*   **Default Value:** 1000 (Standard)
*   **Range:** 1.0 - 8.0 (Internal units vary)
*   **Effect of Increasing:** Allows the drone to maintain more consistent climb rates under extreme loads.
*   **Effect of Decreasing:** Safer; limits the maximum "punch" the velocity controller can add over long periods.

### Use Case Recommendations
*   **Tethered Operations:** **Decrease to 300.** Limits the tension the drone can put on the cable if the vertical path planner fails.
*   **Standard Flight:** **Keep at Default (1000).** This is a safe ceiling for normal operation.

### Troubleshooting
*   **Scenario:** Drone holds climb rate perfectly for the first 10 seconds of a heavy lift, then starts to slowly lose speed.
    *   **Diagnosis:** `PSC_VELZ_IMAX` is likely being hit. The drone needs more integrator authority to maintain the speed against the weight.
    *   **Fix:** Increase `PSC_VELZ_IMAX` or increase `PSC_VELZ_P` to reduce reliance on the integrator.

