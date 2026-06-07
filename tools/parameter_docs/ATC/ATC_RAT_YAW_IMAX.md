---
layout: parameter
name: ATC_RAT_YAW_IMAX
display_name: Yaw Axis Rate I-Term Maximum
description: The maximum limit for the yaw rate integrator. Prevents "Integrator Windup" by capping how much counter-torque the controller can use to fix heading drift.
default_value: 0.5
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_rat_yaw_imax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L32
---

# Yaw Axis Rate I-Term Maximum (ATC_RAT_YAW_IMAX)

## Description
`ATC_RAT_YAW_IMAX` is a critical safety fuse for your drone's heading stability. It limits the maximum amount of torque the **Integral (I) term** is allowed to apply to fix a yaw error.

The I-term is designed to learn how to keep the nose straight. If one motor is tilted by 2 degrees, the drone will naturally want to spin. The I-term learns this and applies a constant counter-torque to stay straight. However, if the drone is physically stuck or if a motor is failing, the I-term could "wind up" to 100% authority. If the drone suddenly breaks free, it will spin uncontrollably (death spin). `ATC_RAT_YAW_IMAX` prevents this by putting a hard ceiling on how much authority the "learned memory" has.

*   **Low Value:** Limits the drone's ability to fly if it has tilted motors or asymmetric aerodynamics.
*   **High Value:** Allows the drone to handle major motor misalignments, but increases the risk of a "spin-out" after an entanglement or crash.
*   **Default (0.5):** Allows the integrator to use up to 50% of the motor's counter-torque capacity to fix yaw.

## The Mathematics
The yaw integrator ($\text{Int}$) is accumulated but clamped by this value:

$$ \text{Int}_{new} = \text{constrain}(\text{Int}_{prev} + \text{error} \cdot k_I \cdot dt, -\text{IMAX}, \text{IMAX}) $$

Where:
*   $\text{IMAX}$ is `ATC_RAT_YAW_IMAX`.
*   The output is a $0.0$ to $1.0$ value sent to the motor torque mixer.

## The Engineer's View
This parameter is the `_kimax` member of the `_pid_rate_yaw` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_integrator = constrain_float(_integrator + (error * _ki * dt), -_kimax, _kimax);
```

In `AC_AttitudeControl_Multi`, the yaw integrator has a unique safety feature: it is **Priority-Limited**. If the Roll or Pitch loops already require 100% of the motor power to stay level, the Yaw integrator will stop building up to avoid causing a crash.

## Tuning & Behavior
*   **Default Value:** 0.5 (50% authority)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** Better ability to hold heading on frames with severely tilted motors or asymmetric drag (like a drone carrying a large, non-aerodynamic sign).
*   **Effect of Decreasing:** Safer; limits the force of a "death spin" if the drone's yaw system becomes saturated.

### Use Case Recommendations
*   **Standard Multirotor:** **Keep Default (0.5).** This is a proven, safe ceiling.
*   **Delivery Drones (Large Props):** **Increase to 0.7.** Large propellers generate high yaw torque; if the weight is off-balance, the drone may need more than 50% authority to stay straight.
*   **Indoor / Micro Drones:** **Decrease to 0.3.** Lower authority makes the drone safer and more predictable during indoor collisions.

### Troubleshooting
*   **Scenario:** Drone hovers well, but its tail constantly "creeps" to the left in wind, and increasing `ATC_RAT_YAW_I` doesn't help.
    *   **Diagnosis:** `ATC_RAT_YAW_IMAX` is too low. The drone has reached its "correction limit."
    *   **Fix:** Increase `ATC_RAT_YAW_IMAX` to 0.6 or 0.7.