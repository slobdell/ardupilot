---
layout: parameter
name: ATC_RATE_Y_MAX
display_name: Yaw Rate Max
description: Maximum angular velocity allowed in the yaw axis. Limits how fast the drone can spin its heading per second.
default_value: 0.0
range: 0 1080
units: deg/s
group: ATC
visual_asset_id: atc_rate_y_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L113
---

# Yaw Rate Max (ATC_RATE_Y_MAX)

## Description
`ATC_RATE_Y_MAX` is the "rotation speed limiter" for your drone's heading. It determines the maximum speed (in degrees per second) that the drone is allowed to spin around its center.

Yaw is generally the weakest axis for a multirotor because it relies on torque reaction. If a drone spins too fast, it creates a massive amount of centrifugal force on the motor arms and can easily cause "vertical wash," where the drone drops out of the sky because the motors are busy spinning the drone instead of lifting it. `ATC_RATE_Y_MAX` ensures the drone stays in a safe speed range, even if the pilot pushes the yaw stick all the way to the side.

*   **Low Value (e.g. 45 deg/s):** Very slow, stately rotation. Perfect for smooth cinematic pans.
*   **High Value (e.g. 180 deg/s):** Fast rotation (one full circle every 2 seconds). Good for general flight and rapid target re-acquisition.
*   **Disabled (0):** The drone will spin as fast as its motor torque allows.

## The Mathematics
This parameter acts as a hard ceiling on the requested heading rotation rate ($\omega_{yaw}$):

$$ \omega_{yaw\_target} = \text{constrain}(\omega_{yaw\_calculated}, -\text{RATE\_Y\_MAX}, \text{RATE\_Y\_MAX}) $$

Where:
*   `RATE_Y_MAX` is in degrees per second.
*   $\omega_{yaw\_calculated}$ is derived from the yaw stick or the heading controller.

**Torque Prioritization:** If the drone is at its `RATE_Y_MAX` limit, ArduPilot will often reduce the yaw torque slightly if more Roll or Pitch authority is needed to keep the drone level.

## The Engineer's View
This parameter is the `_ang_vel_yaw_max` member in `AC_AttitudeControl`.

It is enforced in `AC_AttitudeControl::ang_vel_limit()`:

```cpp
// AC_AttitudeControl.cpp
if (!is_zero(ang_vel_yaw_max)) {
    euler_rad.z = constrain_float(euler_rad.z, -ang_vel_yaw_max, ang_vel_yaw_max);
}
```

Unlike Roll and Pitch, which are often scaled together, Yaw is limited independently. This prevents high yaw rates from "stealing" the power needed for roll and pitch stability.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0 - 1080 deg/s
*   **Effect of Increasing:** Allows for faster head-turns and "Yaw Spins." Necessary for tracking fast-moving objects.
*   **Effect of Decreasing:** Smoother pans and less vertical altitude loss during aggressive spinning.

### Use Case Recommendations
*   **Professional Cinematography:** **Set to 30 - 45 deg/s.** This prevents accidental "jerky" heading moves from ruining a shot, ensuring every rotation is a smooth, high-quality pan.
*   **Standard GPS Flying:** **Set to 90 - 120 deg/s.** Provides a responsive tail without risking motor saturation.
*   **FPV Freestyle:** **Keep at 0.0 or set >360.** Pilots want the nose to follow their fingers with no artificial speed limits.

### Troubleshooting
*   **Scenario:** Every time I spin the drone 360 degrees, it drops significantly in altitude.
    *   **Diagnosis:** Yaw torque is starving the lift motors. The spin is too fast for the available motor power.
    *   **Fix:** Reduce `ATC_RATE_Y_MAX` to 60 deg/s.
*   **Scenario:** My drone takes a very long time to turn its nose to the next waypoint in an Auto mission.
    *   **Diagnosis:** `ATC_RATE_Y_MAX` is set too low.
    *   **Fix:** Increase `ATC_RATE_Y_MAX` to 120.