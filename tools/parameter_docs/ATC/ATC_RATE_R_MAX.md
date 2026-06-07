---
layout: parameter
name: ATC_RATE_R_MAX
display_name: Roll Rate Max
description: Maximum angular velocity allowed in the roll axis. Limits how fast the drone can rotate (roll) per second.
default_value: 0.0
range: 0 1080
units: deg/s
group: ATC
visual_asset_id: atc_rate_r_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L101
---

# Roll Rate Max (ATC_RATE_R_MAX)

## Description
`ATC_RATE_R_MAX` is the "top speed" for your drone's rotation. It defines the maximum number of degrees per second the drone is allowed to roll.

If you are flying in a GPS mode (like Loiter) or a stabilized mode, the flight controller will never request a rotation faster than this limit, even if you push your stick to the limit. It ensures the drone remains controllable and doesn't rotate so fast that the EKF (position estimator) loses its orientation.

*   **Low Value (e.g. 90 deg/s):** The drone rotates very slowly and safely. Ideal for beginners and heavy cargo drones.
*   **High Value (e.g. 360 deg/s):** The drone rolls very quickly (one full circle per second). Essential for FPV and aggressive maneuvers.
*   **Disabled (0):** The software does not limit rotation speed. The drone will roll as fast as its motors can physically push it.

## The Mathematics
This parameter acts as a hard "cap" on the requested angular velocity ($\omega$):

$$ \omega_{roll\_target} = \text{constrain}(\omega_{roll\_calculated}, -\text{RATE\_R\_MAX}, \text{RATE\_R\_MAX}) $$

Where:
*   $\text{RATE\_R\_MAX}$ is in degrees/second.
*   $\omega_{roll\_calculated}$ is the output of the pilot's stick scaling or the outer angle loop.

**Note:** This limit is applied *before* the rate PID loop, ensuring the PID controller doesn't "wind up" trying to reach an impossible rotation speed.

## The Engineer's View
This parameter is the `_ang_vel_roll_max` member in `AC_AttitudeControl`.

It is enforced in `AC_AttitudeControl::ang_vel_limit()`:

```cpp
// AC_AttitudeControl.cpp
if (!is_zero(ang_vel_roll_max)) {
    euler_rad.x = thrust_vector_ang_vel.x * ang_vel_roll_max / thrust_vector_length;
}
```

ArduPilot uses a **Spherical Limit** for Roll and Pitch combined. If both axes are at their limits, the controller doesn't just clip them; it scales them both down to ensure the "total" rotation speed remains within the drone's physical capabilities.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0 - 1080 deg/s
*   **Effect of Increasing:** Allows for faster flips and sharper turns.
*   **Effect of Decreasing:** Limits how fast the drone can change its tilt. Makes the drone safer for novice pilots.

### Use Case Recommendations
*   **Cinematography / Inspection:** **Set to 60 - 90 deg/s.** Limits any accidental "jerks" of the stick, ensuring the horizon always moves in a smooth, cinematic way.
*   **Autonomous Search & Rescue:** **Set to 180 deg/s.** Provides a good balance between scanning speed and stabilization accuracy.
*   **Standard Multirotor:** **Keep at 0.0 or 360.** Standard 360 deg/s is common for most hobbyist flight.

### Troubleshooting
*   **Scenario:** I am trying to do a flip, but the drone rolls extremely slowly, like it's fighting me.
    *   **Diagnosis:** `ATC_RATE_R_MAX` is set too low.
    *   **Fix:** Increase `ATC_RATE_R_MAX` to 360 or 0.
*   **Scenario:** During high-speed turns, the EKF loses its position and the drone enters "Land" mode.
    *   **Diagnosis:** The drone is rotating faster than the sensors can accurately track.
    *   **Fix:** Reduce `ATC_RATE_R_MAX` to 180.
    *   **Also check:** `ATC_RATE_P_MAX`.