---
layout: parameter
name: ATC_ANG_RLL_P
display_name: Roll Axis Angle P Gain
description: Converts the roll angle error (desired tilt - actual tilt) into a desired roll rate (how fast the drone should rotate to fix the tilt).
default_value: 4.5
range: 3.0 12.0
units: 
group: ATC
visual_asset_id: atc_ang_rll_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L102
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_P.cpp#L11
---

# Roll Axis Angle P Gain (ATC_ANG_RLL_P)

## Description
`ATC_ANG_RLL_P` is the primary "stiffness" setting for the drone's horizontal attitude. It controls the **Outer Loop** of the flight controller, which is responsible for maintaining the requested roll angle.

This parameter defines how aggressively the drone should rotate to correct a mistake in its tilt. If the pilot (or autopilot) wants a 20-degree lean, but the drone is currently level, `ATC_ANG_RLL_P` determines how fast the drone should start rolling to reach that 20-degree target.

*   **Low Value:** The drone feels "soft" or "soupy." It may take a long time to reach the desired tilt, making it feel non-responsive to stick inputs.
*   **High Value:** The drone feels "locked-in" and very responsive. Stick inputs feel immediate.
*   **Too High:** The drone will oscillate (jitter) in the roll axis, specifically when the pilot releases the sticks or during a hover.

## The Mathematics
This is a Proportional ($k_P$) controller that generates a **Target Angular Velocity** ($\omega$):

$$ \omega_{roll\_target} = k_P \cdot (\theta_{desired} - \theta_{actual}) $$

Where:
*   $\omega_{roll\_target}$ is the requested rotation speed (deg/s) sent to the inner Rate Loop.
*   $\theta_{desired}$ is the angle requested by the pilot's sticks or the position controller.
*   $\theta_{actual}$ is the current roll estimate from the AHRS/IMU.
*   $k_P$ is `ATC_ANG_RLL_P`.
*   **Dimensionality:** Since it converts Angle (deg) to Angular Velocity (deg/s), the unit of $k_P$ is $1/s$ (Hertz).

**Example:** If the drone is 10 degrees off-target and `ATC_ANG_RLL_P` is 4.5, it will demand a rotation rate of 45 deg/s to fix the error.

## The Engineer's View
This parameter is an instance of the `AC_P` class, instantiated as `_p_angle_roll` within the `AC_AttitudeControl` library.

It is executed inside `AC_AttitudeControl::update_ang_vel_target_from_att_error()`:

```cpp
// AC_AttitudeControl.cpp
const float angleP_roll = _p_angle_roll.kP() * _angle_P_scale.x;
rate_target_ang_vel.x = angleP_roll * attitude_error_rot_vec_rad.x;
```

Note that the result is often passed through a **Square Root Controller** logic if the error is large, which helps prevent overshooting during massive corrections.

## Tuning & Behavior
*   **Default Value:** 4.5 (Standard Multirotor)
*   **Range:** 3.0 - 12.0
*   **Effect of Increasing:** Snappier response to stick inputs. Tighter attitude hold in wind.
*   **Effect of Decreasing:** Smoother, more organic flight feel. Reduces the "robotic" look of automated flight.

### Use Case Recommendations
*   **Cinematography:** **Decrease to 3.5 - 4.0.**
    *   *Why:* Creates smoother transitions when starting and stopping rolls, making the camera footage less jarring.
*   **FPV Freestyle / Racing:** **Increase to 6.0 - 9.0.**
    *   *Why:* Provides the "instant" response needed for proximity flying and rapid gates.
*   **Autonomous Survey / Mapping:** **Keep Default (4.5).**
    *   *Why:* Provides reliable tracking of the mission grid without exciting mechanical resonances.

### Troubleshooting
*   **Scenario:** Drone hovers perfectly, but when you let go of the roll stick after a move, it "bounces" or wobbles 2-3 times before settling.
    *   **Diagnosis:** `ATC_ANG_RLL_P` is too high (Angle loop oscillation).
    *   **Fix:** Reduce `ATC_ANG_RLL_P` by 0.5.