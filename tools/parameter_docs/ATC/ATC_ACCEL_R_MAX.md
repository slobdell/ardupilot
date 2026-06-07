---
layout: parameter
name: ATC_ACCEL_R_MAX
display_name: Roll Acceleration Max
description: Maximum angular acceleration allowed in the roll axis. Limits how quickly the drone can change its roll rotation speed.
default_value: 0.0
range: 0 180000
units: cdeg/s/s
group: ATC
visual_asset_id: atc_accel_r_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L61
---

# Roll Acceleration Max (ATC_ACCEL_R_MAX)

## Description
`ATC_ACCEL_R_MAX` defines the "maximum torque" the flight controller is allowed to request around the roll axis. While `ATC_RAT_RLL_P` determines how much authority the drone *has*, `ATC_ACCEL_R_MAX` determines how much authority it is *allowed to use* to start or stop a rotation.

Think of it as the "traction control" for your drone's rotation. If this value is too high, the drone will try to snap into a roll so fast that the motors saturated or the battery voltage drops. If it is too low, the drone will feel "heavy" and slow to start moving, even if your PID gains are high.

*   **Low Value:** Flight feels very smooth, stable, and "heavy." Rotations start and stop with a noticeable ramp-up.
*   **High Value:** Rotations feel instant and sharp.
*   **Disabled (0):** The software does not limit angular acceleration (limited only by physical motor power).

## The Mathematics
This parameter limits the rate of change of the target angular velocity ($\omega_{target}$):

$$ \left| \frac{\omega_{target}(t) - \omega_{target}(t-dt)}{dt} \right| \leq \text{ACCEL\_R\_MAX} $$

Where:
*   $\text{ACCEL\_R\_MAX}$ is in centidegrees/sec².
*   **Example:** A value of 72000 means the drone can increase its rotation speed by 720 degrees per second, every second.

## The Engineer's View
This parameter is the `_accel_roll_max` member in `AC_AttitudeControl`.

It is used in the **Input Shaper** logic inside `AC_AttitudeControl::input_shaping_angle()` and `input_shaping_ang_vel()`.
These functions ensure that the setpoints sent to the PID loops are physically achievable by the drone, preventing the PID loops from "winding up" against impossible targets.

```cpp
// AC_AttitudeControl.cpp
_ang_vel_target.x = input_shaping_angle(error, _input_tc, get_accel_roll_max_radss(), ...);
```

By keeping the target acceleration within this limit, ArduPilot ensures that the drone's attitude remains predictable and that the "Square Root Controller" (which handles large errors) doesn't over-command the motors.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0 - 180,000 (0 to 1800 deg/s/s)
*   **Effect of Increasing:** Snappier, more immediate rotations. The drone feels "lighter."
*   **Effect of Decreasing:** Smoother, more cinematic rotations. Greatly reduces current spikes during aggressive flight.

### Use Case Recommendations
*   **Cinematography / Aerial Inspection:** **Set to 36000 - 54000.** Limits the "jerkiness" of the drone, making it easier for the camera operator and reducing mechanical stress.
*   **Large Professional Rig (>25 inch props):** **Set to 20000.** Large props have enormous inertia; trying to accelerate them faster than 200 deg/s/s usually results in wasted energy and heat.
*   **High Performance / Racing:** **Keep at 0.0 or set >110000.** Racers need the absolute maximum torque available to clear obstacles and make 180-degree turns.

### Troubleshooting
*   **Scenario:** Drone feels "laggy" to start a roll, even though the PID gains are high.
    *   **Diagnosis:** `ATC_ACCEL_R_MAX` is set too low, bottlenecking the command.
    *   **Fix:** Increase `ATC_ACCEL_R_MAX` by 10000.