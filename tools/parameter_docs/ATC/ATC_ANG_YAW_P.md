---
layout: parameter
name: ATC_ANG_YAW_P
display_name: Yaw Axis Angle P Gain
description: Converts the yaw angle error (desired heading - actual heading) into a desired yaw rate (how fast the drone should spin to fix the heading).
default_value: 4.5
range: 3.0 12.0
units: 
group: ATC
visual_asset_id: atc_ang_yaw_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L114
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_P.cpp#L11
---

# Yaw Axis Angle P Gain (ATC_ANG_YAW_P)

## Description
`ATC_ANG_YAW_P` controls the drone's "heading stiffness." It is responsible for making sure the nose of the drone stays pointed where you want it.

If the wind pushes the tail of the drone, or if you command a 90-degree turn, `ATC_ANG_YAW_P` determines how hard the drone should start spinning to align with that new heading.

*   **Low Value:** The drone feels "sloppy" in its heading. It may drift away from its heading when accelerating or in wind. The nose feels "vague" to the pilot.
*   **High Value:** Heading hold is very precise. The drone snaps to new headings instantly.
*   **Too High:** The drone will oscillate its tail (wagging) or make sharp, sudden yaw corrections that cause the whole frame to twitch.

## The Mathematics
This Proportional ($k_P$) gain converts heading error into a **Rotation Rate**:

$$ \omega_{yaw\_target} = k_P \cdot (\psi_{desired} - \psi_{actual}) $$

Where:
*   $\omega_{yaw\_target}$ is the requested rotation speed around the vertical axis (deg/s).
*   $\psi_{desired}$ is the target heading (0-360 deg).
*   $\psi_{actual}$ is the current heading (from Compass/EKF).
*   $k_P$ is `ATC_ANG_YAW_P`.
*   **Dimensionality:** $1/s$ (Hertz).

**Yaw Constraint:** Heading error is always calculated using "Shortest Path" logic (the drone will never spin more than 180 degrees to fix its heading).

## The Engineer's View
This parameter is an instance of the `AC_P` class, member `_p_angle_yaw`, inside `AC_AttitudeControl`.

It is executed in `AC_AttitudeControl::update_ang_vel_target_from_att_error()`:

```cpp
// AC_AttitudeControl.cpp
const float angleP_yaw = _p_angle_yaw.kP() * _angle_P_scale.z;
rate_target_ang_vel.z = angleP_yaw * attitude_error_rot_vec_rad.z;
```

The output `rate_target_ang_vel.z` becomes the input setpoint for the inner **Yaw Rate PID** loop (`ATC_RAT_YAW_*`).

## Tuning & Behavior
*   **Default Value:** 4.5 (Standard)
*   **Range:** 3.0 - 12.0
*   **Effect of Increasing:** Tighter heading hold. Better rejection of motor-induced yaw torque (yaw-dip).
*   **Effect of Decreasing:** Smoother yaw turns. More "drifty" heading feel.

### Use Case Recommendations
*   **Precision Photography / Survey:** **Keep Default (4.5).** Heading accuracy is important for georeferencing, but too much gain can cause vibration in the gimbal.
*   **Yaw-Heavy Freestyle:** **Increase to 6.0 - 8.0.** Provides the crisp yaw stops needed for maneuvers like "Yaw Spins" or "Orbit" mode.
*   **Large Professional Drones:** **Keep Default or decrease to 3.5.** Large frames have high yaw-inertia (due to long arms); pushing them too hard with P-gain leads to "frame flex" and low-frequency oscillations.

### Troubleshooting
*   **Scenario:** Drone hovers well, but its tail "wags" back and forth once every few seconds.
    *   **Diagnosis:** `ATC_ANG_YAW_P` is too high (Angle loop resonance).
    *   **Fix:** Reduce `ATC_ANG_YAW_P` by 0.5.