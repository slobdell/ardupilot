---
layout: parameter
name: PSC_POSXY_P
display_name: Position Control (XY) P Gain
description: Converts the horizontal distance error (target - current) into a desired target velocity.
default_value: 1.0
range: 0.5 2.0
units: 
group: PSC
visual_asset_id: psc_posxy_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1060
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_P_2D.cpp#L11
---

<!-- 
  NOTE: This file is the "Golden Sample" for the Rich-Atomic documentation strategy.
-->

# Position Control (XY) P Gain (PSC_POSXY_P)

## Description
The `PSC_POSXY_P` parameter determines the "stiffness" of the vehicle's position hold in the horizontal (XY) plane. It acts as the primary driver for converting position errors (how far you are from the target) into requested velocities (how fast you should fly to get back).

*   **Low Value:** The drone feels "loose" and will drift further from the target before correcting. It may feel sluggish to stop.
*   **High Value:** The drone fights aggressively to hold position. It stops sharply.
*   **Too High:** The drone will overshoot the target and oscillate (jitter) around the position hold, often observed as a rapid "twitching" in Loiter mode.

## The Mathematics
This parameter is the Proportional ($k_P$) term in the outer loop of the cascaded position controller.

$$ \vec{V}_{target} = k_P \cdot (\vec{P}_{target} - \vec{P}_{current}) $$

Where:
*   $\vec{V}_{target}$ is the requested velocity (in cm/s) sent to the inner Velocity Loop.
*   $\vec{P}_{target}$ is the desired location (e.g., where the sticks are commanded or the loiter point).
*   $\vec{P}_{current}$ is the EKF estimated position.
*   $k_P$ is the `PSC_POSXY_P` gain.
*   **Dimensionality:** Since it converts Position ($L$) to Velocity ($L T^{-1}$), the unit of $k_P$ is $1/s$ (Hertz).

## The Engineer's View
This parameter is an instance of the `AC_P_2D` class, instantiated as `_p_pos_xy` within the `AC_PosControl` library.

It is executed on every main loop cycle (typically 400Hz) inside `AC_PosControl::update_xy_controller()`:

```cpp
// AC_PosControl.cpp
Vector2f vel_target = _p_pos_xy.update_all(_pos_target.x, _pos_target.y, comb_pos);
```

The output of this P-controller becomes the input target for the **Velocity PID** loop (`PSC_VELXY_*`), meaning any noise or oscillation here will cascade down into the velocity and acceleration controllers.

## Tuning & Behavior
*   **Default Value:** 1.0 (Standard for most quadcopters)
*   **Range:** 0.5 - 2.0
*   **Effect of Increasing:** Sharper position holding, faster braking when sticks are released.
*   **Effect of Decreasing:** Smoother braking, "softer" loiter, less aggressive correction against wind gusts.
*   **Dependencies:** If you change this significantly, you may need to re-tune `PSC_VELXY_P` and `PSC_VELXY_D` to handle the more aggressive velocity demands.

### Use Case Recommendations
*   **Cinematography:** **Decrease to 0.7 - 0.8.**
    *   *Why:* Prevents the "hard stop" when you release the sticks at a waypoint. It creates a gentle, coasting deceleration that looks more organic on camera.
*   **Precision Inspection / Survey:** **Increase to 1.2 - 1.5.**
    *   *Why:* When inspecting a wind turbine or bridge, you want the drone to hold its coordinate exactly against wind gusts, even if the motor response is aggressive.
*   **General Flying:** **Keep Default (1.0).**
    *   *Why:* Provides a balanced feel where the drone is responsive but not twitchy.

### Practical Tuning Tip
For large, heavy cinematic drones, reduce this to **0.8** or **0.7** to prevent sudden jerky stops that ruin camera footage. For FPV racing or aggressive autonomous missions, increase to **1.2 - 1.5** for tight cornering accuracy.
