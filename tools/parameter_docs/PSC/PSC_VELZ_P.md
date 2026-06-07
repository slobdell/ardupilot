---
layout: parameter
name: PSC_VELZ_P
display_name: Position Control Velocity (Vertical) P Gain
description: Converts vertical velocity error (desired climb rate - actual climb rate) into a target vertical acceleration.
default_value: 5.0
range: 1.0 8.0
units: 
group: PSC
visual_asset_id: psc_velz_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L173
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_Basic.cpp#L15
---

# Position Control Velocity (Vertical) P Gain (PSC_VELZ_P)

## Description
`PSC_VELZ_P` is the "throttle response" of the altitude controller. While `PSC_POSZ_P` determines *what* climb rate we want, `PSC_VELZ_P` determines how much *force* (vertical acceleration) the drone applies to achieve that rate.

*   **Low Value:** The drone feels "underpowered" vertically. It takes a long time to reach its target climb rate. If you increase the throttle stick, the drone will accelerate slowly.
*   **High Value:** The drone reacts instantly to vertical commands.
*   **Too High:** The drone will oscillate vertically at a high frequency, sounding like a "vibration" in the motors, especially during rapid descents.

## The Mathematics
This parameter is the Proportional ($k_P$) term in the inner Vertical Velocity loop.

$$ A_{z\_target} = k_P \cdot (V_{z\_target} - V_{z\_current}) + \dots $$

Where:
*   $A_{z\_target}$ is the requested vertical acceleration (cm/s²) sent to the Accel controller.
*   $V_{z\_target}$ is the desired climb/descent rate.
*   $V_{z\_current}$ is the current EKF vertical velocity.
*   $k_P$ is `PSC_VELZ_P`.
*   **Dimensionality:** Since it converts Velocity ($L T^{-1}$) to Acceleration ($L T^{-2}$), the unit of $k_P$ is $1/s$ (Hertz).

## The Engineer's View
This parameter is the `_kp` member of the `_pid_vel_z` object (class `AC_PID_Basic`) inside `AC_PosControl`.

It is executed in `AC_PosControl::update_z_controller()`:

```cpp
// AC_PosControl.cpp
_accel_target.z = _pid_vel_z.update_all(_vel_target.z, curr_vel_z, _dt, _motors.limit.throttle_lower, _motors.limit.throttle_upper);
```

The output `_accel_target.z` is then combined with the feed-forward and gravity compensation to determine the final throttle output.

## Tuning & Behavior
*   **Default Value:** 5.0
*   **Range:** 1.0 - 8.0
*   **Effect of Increasing:** Faster vertical acceleration. Drone maintains climb rate more accurately under varying loads.
*   **Effect of Decreasing:** Smoother, softer vertical movement.

### Use Case Recommendations
*   **Standard Multirotors:** **Keep Default (5.0).** ArduPilot defaults are very well tuned for vertical response on 4-10 inch props.
*   **Large / Heavy Vehicles:** **Decrease to 3.0 - 4.0.** Heavy vehicles cannot accelerate vertically as fast as small ones; a high P-gain will lead to "ringing" in the throttle.
*   **Precision Docking / Precision Landing:** **Increase to 6.0.** Ensures the vertical velocity is perfectly matched to the descent profile to avoid hard landings.

### Troubleshooting
*   **Scenario:** Drone "jitters" or makes a high-pitched oscillation sound only when climbing or descending.
    *   **Diagnosis:** `PSC_VELZ_P` is too high for the motor/prop combination.
    *   **Fix:** Reduce `PSC_VELZ_P` by 0.5 until the noise stops.
