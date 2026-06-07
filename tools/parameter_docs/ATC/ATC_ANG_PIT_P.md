---
layout: parameter
name: ATC_ANG_PIT_P
display_name: Pitch Axis Angle P Gain
description: Converts the pitch angle error (desired tilt - actual tilt) into a desired pitch rate (how fast the drone should rotate to fix the tilt).
default_value: 4.5
range: 3.0 12.0
units: 
group: ATC
visual_asset_id: atc_ang_pit_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L108
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_P.cpp#L11
---

# Pitch Axis Angle P Gain (ATC_ANG_PIT_P)

## Description
`ATC_ANG_PIT_P` controls the "stiffness" of the drone's pitch attitude (tilting forward or backward). It is the outer control loop responsible for ensuring the drone reaches and holds the requested pitch angle.

If you push the stick forward to fly, `ATC_ANG_PIT_P` determines how quickly the drone tilts into that forward movement. A high value makes the drone snap into the tilt; a low value makes it tilt gracefully.

*   **Low Value:** Pitch response feels "soft." The drone may take a noticeable amount of time to start moving or stop.
*   **High Value:** Pitch response feels immediate and sharp.
*   **Too High:** The drone will oscillate (bob its nose up and down) during hover or when sticks are released.

## The Mathematics
This is a Proportional ($k_P$) controller that converts an **Angle Error** into a **Target Angular Velocity** ($\omega$):

$$ \omega_{pitch\_target} = k_P \cdot (\theta_{desired} - \theta_{actual}) $$

Where:
*   $\omega_{pitch\_target}$ is the requested rotation speed (deg/s) for the Pitch axis.
*   $\theta_{desired}$ is the angle requested by the sticks or autopilot.
*   $\theta_{actual}$ is the current estimated pitch from the AHRS.
*   $k_P$ is `ATC_ANG_PIT_P`.
*   **Dimensionality:** $1/s$ (Hertz).

**Note on Symmetry:** On most symmetric multirotors (X-quads), this value should be identical to `ATC_ANG_RLL_P`. On rectangular frames ("Dead Cat" or Long-Range frames), it may need to be slightly different to account for the different weight distribution.

## The Engineer's View
This parameter is an instance of the `AC_P` class, member `_p_angle_pitch`, inside `AC_AttitudeControl`.

It is executed in `AC_AttitudeControl::update_ang_vel_target_from_att_error()`:

```cpp
// AC_AttitudeControl.cpp
const float angleP_pitch = _p_angle_pitch.kP() * _angle_P_scale.y;
rate_target_ang_vel.y = angleP_pitch * attitude_error_rot_vec_rad.y;
```

The output `rate_target_ang_vel.y` is the input setpoint for the inner **Pitch Rate PID** loop (`ATC_RAT_PIT_*`).

## Tuning & Behavior
*   **Default Value:** 4.5 (Standard)
*   **Range:** 3.0 - 12.0
*   **Effect of Increasing:** Faster nose-up/nose-down response. Better adherence to the flight path in missions.
*   **Effect of Decreasing:** Smoother, less robotic pitching. Reduces landing gear stress during hard stops.

### Use Case Recommendations
*   **Cinematography:** **Decrease to 3.5 - 4.0.** Creates very smooth "tilt-up" or "tilt-down" shots.
*   **Racing / FPV:** **Increase to 6.0 - 10.0.** Allows for the instant pitch changes required for high-speed maneuvering and gate navigation.
*   **Long-Range Mapping:** **Keep Default (4.5).** Reliable, stable tracking.

### Troubleshooting
*   **Scenario:** Drone nose "bobs" up and down specifically when stopping after forward flight.
    *   **Diagnosis:** `ATC_ANG_PIT_P` is too high (Angle loop overshoot).
    *   **Fix:** Reduce `ATC_ANG_PIT_P` by 0.5.