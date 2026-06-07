---
layout: parameter
name: ATC_RAT_RLL_P
display_name: Roll Axis Rate P Gain
description: Converts the roll rate error (desired rotation speed - actual rotation speed) into a motor command. This is the primary parameter for flight stability.
default_value: 0.135
range: 0.01 0.5
units: 
group: ATC
visual_asset_id: atc_rat_rll_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L13
---

# Roll Axis Rate P Gain (ATC_RAT_RLL_P)

## Description
`ATC_RAT_RLL_P` is the single most important parameter for your drone's stability. It sits in the **Innermost Loop** of the flight controller, responsible for managing the actual RPM of your motors to achieve a specific rotation speed.

If the drone is rotating at 10 deg/s but needs to be at 20 deg/s, `ATC_RAT_RLL_P` determines how much extra power is sent to the motors on one side to force that change. 

*   **Low Value:** The drone feels "heavy," sluggish, and will not be able to stabilize itself against wind. It may slowly tilt over and crash because it lacks the authority to fix itself.
*   **High Value:** The drone feels very "tight" and precise.
*   **Too High:** The drone will oscillate (vibrate) rapidly in the roll axis. This is often heard as a high-pitched "shrieking" or "warbling" sound from the motors.

## The Mathematics
This is the Proportional ($k_P$) term of the rate controller. It calculates a motor demand ($	ext{Out}$) based on the **Rate Error**:

$$ \text{Out}_P = k_P \cdot (\omega_{target} - \omega_{actual}) $$

Where:
*   $\omega_{target}$ is the desired roll rate (deg/s) from the outer Angle loop.
*   $\omega_{actual}$ is the actual roll rate measured by the Gyroscope.
*   $k_P$ is `ATC_RAT_RLL_P`.
*   **Dimensionality:** This gain converts Rotation Rate ($T^{-1}$) into a dimensionless motor command ($0.0$ to $1.0$).

## The Engineer's View
This parameter is the `_kp` member of the `_pid_rate_roll` object (class `AC_PID`) inside `AC_AttitudeControl_Multi`.

It is executed hundreds of times per second (loop rate) in `AC_AttitudeControl_Multi::rate_controller_run_dt()`:

```cpp
// AC_AttitudeControl_Multi.cpp
_motors.set_roll(get_rate_roll_pid().update_all(ang_vel_body.x, gyro.x, dt, ...) + ...);
```

The output of this loop is sent directly to the motor mixer, where it is added to the throttle to determine the final PWM signal for each ESC.

## Tuning & Behavior
*   **Default Value:** 0.135 (Varies by frame)
*   **Range:** 0.01 - 0.50
*   **Effect of Increasing:** Faster stabilization, tighter feel, better rejection of aerodynamic disturbances.
*   **Effect of Decreasing:** Smoother flight, but increased risk of "washout" (losing control during aggressive moves) and poor wind handling.

### Use Case Recommendations
*   **Standard Quadcopter:** **Default (0.135) or run AutoTune.** Most modern 5-10 inch drones work well with values between 0.1 and 0.2.
*   **Racing Drone (High Power-to-Weight):** **Decrease to 0.08 - 0.1.** High-power motors provide so much torque that a smaller P-gain is required to prevent oscillation.
*   **Heavy Industrial / Large Props:** **Increase to 0.18 - 0.25.** Large props have high inertia and take longer to change speed; a higher P-gain is needed to force them to react.

### Troubleshooting
*   **Scenario:** High-frequency vibration ("shaking") in the roll axis, especially when at high throttle. 
    *   **Diagnosis:** `ATC_RAT_RLL_P` is too high (Rate loop oscillation).
    *   **Fix:** Reduce `ATC_RAT_RLL_P` by 15% and re-test.