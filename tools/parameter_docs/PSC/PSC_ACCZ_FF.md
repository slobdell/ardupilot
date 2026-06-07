---
layout: parameter
name: PSC_ACCZ_FF
display_name: Position Control Acceleration (Vertical) Feed-Forward
description: Feed-forward gain for the vertical acceleration loop. Directly maps requested acceleration to motor output, bypassing the error-correction step for faster response.
default_value: 0.0
range: 0 0.5
units: 
group: PSC
visual_asset_id: psc_accz_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L30
---

# Position Control Acceleration (Vertical) Feed-Forward (PSC_ACCZ_FF)

## Description
`PSC_ACCZ_FF` is the "prediction" component of the altitude controller. While the P, I, and D terms react to **errors** (mistakes the drone has already made), the Feed-Forward (FF) term reacts to the **command** itself.

If you tell the drone to climb at 2 m/s, the FF term instantly calculates a baseline throttle increase *before* the drone even starts to sink or slow down. It provides "pre-emptive authority," making the vertical control feel significantly more responsive and connected to the pilot's sticks.

*   **Low Value (0.0):** The drone relies entirely on error-correction. It will always lag slightly behind your climb/descent commands.
*   **High Value:** The drone "jumps" instantly when you command a climb.
*   **Too High:** The drone will "kick" violently and potentially overshoot its climb rate because it's adding too much power before the sensors can even measure the movement.

## The Mathematics
The Feed-Forward term is multiplied directly by the target acceleration:

$$ \text{Throttle}_{FF} = \vec{A}_{z\_target} \cdot k_{FF} $$

Where:
*   $\vec{A}_{z\_target}$ is the requested acceleration.
*   $k_{FF}$ is `PSC_ACCZ_FF`.

The total output becomes:
$$ \text{Throttle}_{total} = \text{Throttle}_{FF} + \text{Throttle}_{P} + \text{Throttle}_{I} + \text{Throttle}_{D} $$

## The Engineer's View
This parameter maps to `_kff` in the `_pid_accel_z` object.

It is applied in `AC_PosControl::update_z_controller()`:

```cpp
// AC_PosControl.cpp
thr_out = _pid_accel_z.update_all(_accel_target.z, z_accel_meas, _dt, ...) * 0.001f;
thr_out += _pid_accel_z.get_ff() * 0.001f;
```

In ArduPilot, Feed-Forward is often preferred over high P-gains because it does not create the same high-frequency oscillations. It is a "clean" way to get performance.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0.0 - 0.5
*   **Effect of Increasing:** Faster response to altitude commands. Reduces the "initial drop" when switching into AltHold/Loiter while moving fast.
*   **Effect of Decreasing:** Smoother, more damped vertical response.

### Use Case Recommendations
*   **Standard Build:** **Keep at 0.0.** The vertical loop is usually strong enough without it.
*   **High-Dynamics / Racing:** **Increase to 0.1 - 0.2.** Gives the "vertical punch" needed to clear obstacles instantly.
*   **Helicopters (Traditional):** **Keep at 0.0.** Collective pitch response is different from multirotor RPM response; FF can cause over-speeding of the head.

### Troubleshooting
*   **Scenario:** When you push the throttle stick up, the drone "twitches" or "kicks" up violently for a split second, then settles into a smooth climb.
    *   **Diagnosis:** `PSC_ACCZ_FF` is too high. The initial "kick" from the command is overpowering the drone's inertia.
    *   **Fix:** Reduce `PSC_ACCZ_FF` by 0.05.
