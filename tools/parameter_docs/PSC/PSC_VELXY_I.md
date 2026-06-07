---
layout: parameter
name: PSC_VELXY_I
display_name: Position Control Velocity (XY) I Gain
description: Integral gain for the velocity controller. Corrects long-term steady-state errors (drift) where the drone fails to reach the target velocity (or fails to hold position against wind).
default_value: 1.0
range: 0.02 1.00
units: 
group: PSC
visual_asset_id: psc_velxy_i_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1066
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_2D.cpp#L18
---

<!-- 
  NOTE: This file is a manually investigated Golden Sample based on Source Code Truth.
-->

# Position Control Velocity (XY) I Gain (PSC_VELXY_I)

## Description
The `PSC_VELXY_I` parameter is the **Integral** term of the velocity controller. Its primary job is to "learn" and compensate for persistent external forces—most commonly **Wind**.

If `PSC_VELXY_P` is the "muscle" that reacts to immediate error, `PSC_VELXY_I` is the "memory" that notices if the P-term isn't doing enough. If the drone is commanding a 0 m/s velocity (hover) but the wind keeps pushing it backwards, the I-term builds up over time, leaning the drone further and further into the wind until the drift stops.

*   **Too Low:** The drone will drift significantly downwind before stopping. In fast forward flight, it may lag behind the desired speed.
*   **Too High:** The drone will "overshoot" when the wind stops or when stopping after a fast flight, taking a long time to level out (known as "I-term windup").

## The Mathematics
This parameter scales the accumulated error over time.

$$ \vec{A}_{target} += \int_0^t (\vec{V}_{target} - \vec{V}_{current}) \cdot k_I \cdot dt $$

Where:
*   $\vec{A}_{target}$ is the requested acceleration (lean angle).
*   The integral $\int$ accumulates the velocity error every time step.
*   $k_I$ is `PSC_VELXY_I`.

**Anti-Windup:** The code explicitly limits this accumulation via `PSC_VELXY_IMAX` to prevent the drone from building up a dangerous lean angle if it is physically stuck or held.

## The Engineer's View
This parameter is the `_ki` member of the `_pid_vel_xy` object in `AC_PosControl`.

It is executed in `AC_PID_2D::update_i()`:

```cpp
// AC_PID_2D.cpp
Vector2f delta_integrator = (_error * _ki) * dt;
_integrator += delta_integrator;
```

Crucially, the integrator has **Leakiness** or **Reset** logic handled in `AC_PosControl::soften_for_landing_xy()`, which prevents the drone from tipping over if it is on the ground but thinks it is drifting.

## Tuning & Behavior
*   **Default Value:** 1.0 (Standard Copter)
*   **Range:** 0.02 - 1.00
*   **Effect of Increasing:** stronger wind resistance, better holding of exact coordinates over long periods.
*   **Effect of Decreasing:** Less "slop" or overshoot when stopping, but potential for "toilet bowling" (orbiting the target) if wind is strong and P-gain is low.

### Use Case Recommendations
*   **Windy Environments / Maritime:** **Increase to 1.5 - 2.0.**
    *   *Why:* The drone needs to "lean into" the wind aggressively to hold position above a boat or shoreline.
*   **Indoor / GPS-Denied:** **Decrease to 0.5.**
    *   *Why:* Without wind, a high I-term can accumulate noise from Optical Flow sensors, causing a slow, wobbling drift.
*   **General:** **Keep Default (1.0).**

### Troubleshooting
*   **Scenario:** Drone flies to a waypoint, stops, but then slowly overshoots and has to back up.
    *   **Diagnosis:** `PSC_VELXY_I` is too high (I-term windup). The drone built up a "lean forward" memory during the flight that it didn't dump fast enough when stopping.
    *   **Fix:** Reduce `PSC_VELXY_I` or increase `PSC_VELXY_D` to dampen the stop.
