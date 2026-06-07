---
layout: parameter
name: ATC_RAT_PIT_P
display_name: Pitch Axis Rate P Gain
description: Converts the pitch rate error (desired pitch speed - actual pitch speed) into a motor command. Primary parameter for forward/backward flight stability.
default_value: 0.135
range: 0.01 0.5
units: 
group: ATC
visual_asset_id: atc_rat_pit_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L13
---

# Pitch Axis Rate P Gain (ATC_RAT_PIT_P)

## Description
`ATC_RAT_PIT_P` is the core stability parameter for the drone's forward and backward movement. It sits in the **Innermost Loop** of the pitch controller, managing the motor RPM differences between the front and rear of the drone to achieve a specific rotation rate.

*   **Low Value:** The drone feels "heavy" and slow to pitch. It may struggle to stop after a forward dash and will be easily pushed around by wind.
*   **High Value:** The drone feels very responsive and sharp.
*   **Too High:** The drone will oscillate (jitter) rapidly in the pitch axis (nose-up/nose-down). This is often audible as a "growl" or rapid motor pulsing.

## The Mathematics
This is the Proportional ($k_P$) term of the pitch rate controller:

$$ \text{Out}_P = k_P \cdot (\omega_{target} - \omega_{actual}) $$

Where:
*   $\omega_{target}$ is the desired pitch rate (deg/s) from the outer Angle loop.
*   $\omega_{actual}$ is the actual pitch rate measured by the Gyroscope.
*   $k_P$ is `ATC_RAT_PIT_P`.

## The Engineer's View
This parameter is the `_kp` member of the `_pid_rate_pitch` object (class `AC_PID`) inside `AC_AttitudeControl_Multi`.

It is executed in `AC_AttitudeControl_Multi::rate_controller_run_dt()`:

```cpp
// AC_AttitudeControl_Multi.cpp
_motors.set_pitch(get_rate_pitch_pid().update_all(ang_vel_body.y, gyro.y, dt, ...) + ...);
```

On most symmetric frames, `ATC_RAT_PIT_P` and `ATC_RAT_PIT_P` should be identical. However, on "Dead Cat" frames or those with long fore-aft arms, these values will often diverge during AutoTune to account for the difference in rotating mass.

## Tuning & Behavior
*   **Default Value:** 0.135 (Standard Quad)
*   **Range:** 0.01 - 0.50
*   **Effect of Increasing:** Better tracking of forward speed commands. Drone stays level more accurately when punching the throttle.
*   **Effect of Decreasing:** Smoother, "lazier" pitch handling.

### Use Case Recommendations
*   **Long-Range / "Dead Cat" Frames:** **Rely on AutoTune.** These frames often require a significantly higher Pitch P-gain than Roll P-gain because the rear motors are further from the center than the front motors.
*   **Racing Drone:** **Decrease to 0.08 - 0.1.** High-torque motors need lower gains to avoid over-correcting.
*   **Heavy Cargo Drone:** **Increase to 0.18 - 0.22.** Needed to overcome the high longitudinal inertia of the airframe.

### Troubleshooting
*   **Scenario:** Drone nose "twitches" or bobs up and down rapidly when flying forward at high speed.
    *   **Diagnosis:** `ATC_RAT_PIT_P` is too high (Aerodynamic resonance).
    *   **Fix:** Reduce `ATC_RAT_PIT_P` by 0.01.