---
layout: parameter
name: ATC_ACCEL_Y_MAX
display_name: Yaw Acceleration Max
description: Maximum angular acceleration allowed in the yaw axis. Limits how quickly the drone can start or stop spinning (rotating heading).
default_value: 0.0
range: 0 72000
units: cdeg/s/s
group: ATC
visual_asset_id: atc_accel_y_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L36
---

# Yaw Acceleration Max (ATC_ACCEL_Y_MAX)

## Description
`ATC_ACCEL_Y_MAX` defines the maximum "spin authority" allowed around the vertical axis. It limits how fast the drone's heading can accelerate or decelerate.

Since multirotors yaw by changing torque, they have significantly less "grip" on the yaw axis than they do on roll or pitch. If you try to snap into a 360-degree spin too fast, the drone may lose its vertical lift (since motors are busy generating torque instead of lift). `ATC_ACCEL_Y_MAX` prevents this by forcing heading changes to be gradual and within the physical limits of the motors.

*   **Low Value:** Yaw turns are smooth and cinematic. The tail "glides" into and out of turns.
*   **High Value:** Yaw turns are sharp and robotic. The drone stops spinning instantly.
*   **Disabled (0):** The software does not limit heading acceleration.

## The Mathematics
This parameter limits the rate of change of the yaw angular velocity ($\omega_{yaw}$):

$$ \left| \frac{\omega_{yaw}(t) - \omega_{yaw}(t-dt)}{dt} \right| \leq \text{ACCEL\_Y\_MAX} $$

Where:
*   $\text{ACCEL\_Y\_MAX}$ is in centidegrees/sec².
*   **Example:** A value of 9000 means the drone can increase its spin rate by 90 degrees per second, every second.

**Safety Limit:** Yaw acceleration is typically set much lower than Roll/Pitch (e.g. 9,000 vs 50,000) because high yaw torque demands can "starve" the other axes, leading to a loss of control.

## The Engineer's View
This parameter is the `_accel_yaw_max` member in `AC_AttitudeControl`.

It is used in the **Input Shaper** for heading commands:

```cpp
// AC_AttitudeControl.cpp
_ang_vel_target.z = input_shaping_angle(error, _input_tc, get_accel_yaw_max_radss(), ...);
```

By keeping the heading command within this acceleration limit, ArduPilot ensures that the drone's vertical lift remains consistent during turns, preventing "altitude dip" that occurs when motors on one diagonal are spun up to their limit to provide yaw torque.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0 - 72,000
*   **Effect of Increasing:** Snappier heading response. Better for high-speed tracking and sharp "Yaw Spins."
*   **Effect of Decreasing:** Smoother, more elegant yaw pans. Essential for professional videography.

### Use Case Recommendations
*   **Professional Cinematography:** **Set to 9000 - 18000.** Creates perfectly smooth pans that don't look like they were made by a robot.
*   **FPV Freestyle:** **Keep at 0.0 or set >54000.** Required for maneuvers that rely on instant heading changes to change the drone's direction of momentum.
*   **Mapping / Survey:** **Set to 18000.** Ensures the drone turns at the end of each grid line smoothly without overshooting or causing gimbal vibrations.

### Troubleshooting
*   **Scenario:** Drone loses 1-2 meters of altitude every time you perform a fast 360-degree spin.
    *   **Diagnosis:** Yaw torque is starving the vertical lift (Saturation). `ATC_ACCEL_Y_MAX` is too high.
    *   **Fix:** Reduce `ATC_ACCEL_Y_MAX` to 12000.