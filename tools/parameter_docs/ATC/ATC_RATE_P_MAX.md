---
layout: parameter
name: ATC_RATE_P_MAX
display_name: Pitch Rate Max
description: Maximum angular velocity allowed in the pitch axis. Limits how fast the drone can rotate forward or backward per second.
default_value: 0.0
range: 0 1080
units: deg/s
group: ATC
visual_asset_id: atc_rate_p_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L107
---

# Pitch Rate Max (ATC_RATE_P_MAX)

## Description
`ATC_RATE_P_MAX` defines the "pitch speed limit" for your drone. It determines the maximum degrees per second the drone is allowed to tilt forward or backward.

This parameter is essential for keeping the drone within its physical flight envelope. If you pitch too fast, you risk motor saturation (where motors on one side hit 100% and cannot lift the drone anymore) or sensor loss. `ATC_RATE_P_MAX` acts as a safety governor, ensuring that even if you slam the stick forward, the drone will only accelerate its rotation up to this specific speed.

*   **Low Value (e.g. 60 deg/s):** The drone pitches very slowly. Ideal for heavy-lift commercial drones and passenger vehicles.
*   **High Value (e.g. 360 deg/s):** The drone can perform one full forward flip every second. Essential for high-performance flight.
*   **Disabled (0):** The software does not limit pitch rotation speed.

## The Mathematics
This parameter caps the target angular velocity ($\omega_{pitch}$) calculated by the flight controller:

$$ \omega_{pitch\_target} = \text{constrain}(\omega_{pitch\_calculated}, -\text{RATE\_P\_MAX}, \text{RATE\_P\_MAX}) $$

Where:
*   $\text{RATE\_P\_MAX}$ is in degrees per second.
*   $\omega_{pitch\_calculated}$ is the desired rotation rate from stick input or the angle loop.

**Combined Limits:** ArduPilot enforces this limit in a way that respects the drone's total thrust. If you are at the limit of both Roll and Pitch, the controller will prioritize whichever axis has the larger error while keeping the total vector within safe bounds.

## The Engineer's View
This parameter is the `_ang_vel_pitch_max` member in `AC_AttitudeControl`.

It is applied in `AC_AttitudeControl::ang_vel_limit()`:

```cpp
// AC_AttitudeControl.cpp
if (!is_zero(ang_vel_pitch_max)) {
    euler_rad.y = thrust_vector_ang_vel.y * ang_vel_pitch_max / thrust_vector_length;
}
```

This limit is particularly important during **High Speed Braking**. When the drone stops moving forward, it must pitch up aggressively. If `RATE_P_MAX` is too low, the drone may take too long to pitch up and could potentially overshoot its stopping point or strike an obstacle.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0 - 1080 deg/s
*   **Effect of Increasing:** Allows for sharper, more immediate forward/backward maneuvers. Necessary for high-speed automated missions.
*   **Effect of Decreasing:** Smoother pitch transitions. Reduces landing gear stress during hard stops.

### Use Case Recommendations
*   **Large Professional Octocopters:** **Set to 60 - 90 deg/s.** These large vehicles have massive inertia; attempting to pitch them faster than 90 deg/s is inefficient and can cause structural fatigue.
*   **Standard GPS Multirotor:** **Set to 180 deg/s.** Provides a good balance of agility and safety.
*   **Freestyle / Racing Quads:** **Keep at 0.0.** Performance is the priority; the pilot is responsible for managing the rotation speed.

### Troubleshooting
*   **Scenario:** During an Auto mission, the drone seems to "glide" through waypoints instead of turning sharply.
    *   **Diagnosis:** `ATC_RATE_P_MAX` (and potentially `ATC_RATE_R_MAX`) is set too low, limiting the drone's ability to change its attitude quickly.
    *   **Fix:** Increase `ATC_RATE_P_MAX` to 180.