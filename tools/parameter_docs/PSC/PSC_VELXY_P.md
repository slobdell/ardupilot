---
layout: parameter
name: PSC_VELXY_P
display_name: Position Control Velocity (XY) P Gain
description: Converts the horizontal velocity error (desired speed - actual speed) into a target acceleration.
default_value: 2.0
range: 0.1 6.0
units: 
group: PSC
visual_asset_id: psc_velxy_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1066
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_2D.cpp#L13
---

<!-- 
  NOTE: This file is a manually investigated Golden Sample.
-->

# Position Control Velocity (XY) P Gain (PSC_VELXY_P)

## Description
The `PSC_VELXY_P` parameter controls how aggressively the drone adjusts its acceleration to match the desired velocity. It is the "muscle" of the position controller. While `PSC_POSXY_P` determines the *speed* you want to fly at to fix a position error, `PSC_VELXY_P` determines the *force* (lean angle) applied to achieve that speed.

*   **Low Value:** The drone feels "slushy" or "drifty." It takes a long time to reach the desired speed and may overshoot the stopping point because it doesn't brake hard enough.
*   **High Value:** The drone reacts instantly to velocity errors with sharp leans.
*   **Too High:** The drone will oscillate rapidly (jitter) as it over-corrects velocity noise, especially in wind.

## The Mathematics
This parameter is the Proportional ($k_P$) term of the velocity PID loop.

$$ \vec{A}_{target} = k_P \cdot (\vec{V}_{target} - \vec{V}_{current}) + \dots $$

Where:
*   $\vec{A}_{target}$ is the requested acceleration (cm/s²).
*   $\vec{V}_{target}$ is the desired velocity (cm/s).
*   $k_P$ is `PSC_VELXY_P`.
*   **Dimensionality:** Since it converts Velocity ($L T^{-1}$) to Acceleration ($L T^{-2}$), the unit of $k_P$ is technically $1/s$ (Hertz), though it is treated as a unitless scalar in the GCS.

## The Engineer's View
This parameter is part of the `AC_PID_2D` object `_pid_vel_xy` inside `AC_PosControl`.

It is executed in `AC_PosControl::update_xy_controller()`:

```cpp
// AC_PosControl.cpp
Vector2f accel_target = _pid_vel_xy.update_all(_vel_target.xy(), comb_vel, _dt, _limit_vector.xy());
```

The output `accel_target` is then converted to lean angles (`_roll_target`, `_pitch_target`) which are sent to the Attitude Controller.

## Tuning & Behavior
*   **Default Value:** 2.0 (Standard Copter)
*   **Range:** 0.1 - 6.0
*   **Effect of Increasing:** Sharper tracking of velocity requests. Better wind rejection.
*   **Effect of Decreasing:** Smoother flight, less "twitchiness," but reduced position holding accuracy.
*   **Dependencies:** Must be tuned in conjunction with `PSC_VELXY_D` (Damping). High P usually requires some D to prevent overshoot.

### Use Case Recommendations
*   **Cinematography / Heavy Lift:** **Decrease to 1.0 - 1.5.**
    *   *Why:* Smoothes out the "twitch" caused by GPS noise or wind gusts. Prevents the drone from jerking the camera gimbal when it corrects small position errors.
*   **FPV Racing / Aggressive Flight:** **Increase to 2.5 - 3.0.**
    *   *Why:* Ensures the drone "locks" onto velocity commands instantly. Essential for sharp cornering where any lag results in a wide turn radius.
*   **Long-Range Mapping:** **Keep Default (2.0).**
    *   *Why:* Standard tuning provides the best compromise between track adherence (straight lines) and efficiency.

### Troubleshooting
*   **Scenario:** Drone "twitches" rapidly while hovering in wind.
    *   **Diagnosis:** `PSC_VELXY_P` is too high. The controller is reacting to every tiny gust with a hard lean.
    *   **Fix:** Reduce `PSC_VELXY_P` (try 1.5).
*   **Scenario:** Drone drifts away from target in wind and takes too long to correct.
    *   **Diagnosis:** `PSC_VELXY_P` (or `I`) is too low.
    *   **Fix:** Increase `PSC_VELXY_P`.
