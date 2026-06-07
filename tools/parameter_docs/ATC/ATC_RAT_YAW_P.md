---
layout: parameter
name: ATC_RAT_YAW_P
display_name: Yaw Axis Rate P Gain
description: Converts the yaw rate error (desired rotation speed - actual rotation speed) into a motor command. Primary parameter for heading stability and "tail hold" authority.
default_value: 0.18
range: 0.10 2.50
units: 
group: ATC
visual_asset_id: atc_rat_yaw_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L13
---

# Yaw Axis Rate P Gain (ATC_RAT_YAW_P)

## Description
`ATC_RAT_YAW_P` is the "tail hold" authority for your drone. It sits in the **Innermost Loop** of the yaw controller, managing the torque differences between clockwise and counter-clockwise spinning motors to achieve a specific rotation rate.

Unlike Roll and Pitch, which use powerful differential thrust, multirotors yaw by changing the balance of motor torque. This is a much weaker force. `ATC_RAT_YAW_P` determines how aggressively the flight controller fights to keep the nose pointed in the right direction.

*   **Low Value:** The tail will feel "vague" or "lazy." When you stop a turn, the drone might continue to drift (coast) for a few degrees. It will also be easily blown around by the wind.
*   **High Value:** The drone tracks heading commands precisely. Turns feel sharp and immediate.
*   **Too High:** The drone will develop "Tail Wag"—the nose will rapidly oscillate left and right. This can cause the entire frame to vibrate and potentially lose altitude.

## The Mathematics
This is the Proportional ($k_P$) term of the yaw rate controller:

$$ \text{Out}_P = k_P \cdot (\omega_{target} - \omega_{actual}) $$

Where:
*   $\omega_{target}$ is the desired yaw rate (deg/s).
*   $\omega_{actual}$ is the actual rotation rate measured by the Z-axis of the Gyroscope.
*   $k_P$ is `ATC_RAT_YAW_P`.

**Note:** Yaw gains are typically much higher than Roll/Pitch gains (e.g., 0.5 to 1.0 vs 0.1) because the physical torque authority is so much lower.

## The Engineer's View
This parameter is the `_kp` member of the `_pid_rate_yaw` object (class `AC_PID`) inside `AC_AttitudeControl_Multi`.

It is executed in `AC_AttitudeControl_Multi::rate_controller_run_dt()`:

```cpp
// AC_AttitudeControl_Multi.cpp
_motors.set_yaw(get_rate_yaw_pid().update_all(ang_vel_body.z, gyro.z, dt, ...) + ...);
```

On some frames, high yaw demands can "starve" the other axes for power. ArduPilot's motor mixer includes logic to prioritize Roll and Pitch over Yaw to ensure the drone doesn't flip over just to fix its heading.

## Tuning & Behavior
*   **Default Value:** 0.18 (Standard)
*   **Range:** 0.10 - 2.50
*   **Effect of Increasing:** Sharper, more precise yaw response. Better "locking" of the heading in wind.
*   **Effect of Decreasing:** Smoother, more cinematic turns. Less stress on the motor bearings.

### Use Case Recommendations
*   **Professional Video (Smooth Pans):** **Decrease to 0.12 - 0.15.** Creates very graceful, slow yaw movements that look great on camera.
*   **Yaw-Heavy Freestyle (Yaw Spins):** **Increase to 0.5 - 1.0.** Needed to stop extreme rotations instantly and provide the "locked" feel during technical maneuvers.
*   **Tricopters:** **Rely on specific tuning.** Tricopters use a servo for yaw, which provides much higher authority than torque reaction. Their `ATC_RAT_YAW_P` values are usually much lower.

### Troubleshooting
*   **Scenario:** The drone's tail constantly "wags" left and right about 2-3 times per second during a hover.
    *   **Diagnosis:** `ATC_RAT_YAW_P` is too high.
    *   **Fix:** Reduce `ATC_RAT_YAW_P` by 0.05.