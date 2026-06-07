---
layout: parameter
name: PSC_ACCZ_IMAX
display_name: Position Control Acceleration (Vertical) I-Term Maximum
description: The maximum limit for the vertical acceleration integrator. Prevents "Integrator Windup" by capping how much throttle the drone can add to compensate for weight/gravity.
default_value: 800
range: 0 1000
units: d%
group: PSC
visual_asset_id: psc_accz_imax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L32
---

# Position Control Acceleration (Vertical) I-Term Maximum (PSC_ACCZ_IMAX)

## Description
`PSC_ACCZ_IMAX` is a critical safety limit for the vertical controller. It defines the maximum "authority" given to the vertical integrator (`PSC_ACCZ_I`). 

The integrator's job is to learn the hover throttle. However, if the drone is physically prevented from climbing (e.g., it is tangled in a tree, or you are holding it down during a test), the integrator will keep increasing the throttle command to try and fix the error. Without a limit, the drone would eventually reach 100% throttle, leading to a dangerous situation if it suddenly breaks free.

*   **Low Value:** Limits the drone's ability to compensate for very heavy payloads or extremely low battery voltages.
*   **High Value:** Allows the drone to compensate for massive weight changes, but increases the risk of "runaway" throttle if the drone is stuck.
*   **Units:** Expressed in "Deci-percent" of throttle (e.g., 800 = 80%).

## The Mathematics
The integrator ($\vec{I}$) is calculated over time, but is clamped by this parameter:

$$ \vec{I}_{new} = \text{constrain}(\vec{I}_{prev} + \text{error} \cdot k_I \cdot dt, -\text{IMAX}, \text{IMAX}) $$

Where:
*   $\text{IMAX}$ is `PSC_ACCZ_IMAX`.
*   The output is typically scaled so that 1000 = full motor authority.

## The Engineer's View
This parameter maps to `_kimax` in the `_pid_accel_z` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_integrator = constrain_float(_integrator + (error * _ki * dt), -_kimax, _kimax);
```

ArduPilot also includes a **Secondary Safety**: the integrator is not allowed to increase if the motors are already at their physical limits (`_motors.limit.throttle_upper`), which further prevents windup.

## Tuning & Behavior
*   **Default Value:** 800 (80% throttle authority)
*   **Range:** 0 - 1000
*   **Effect of Increasing:** Allows the drone to handle much heavier payloads than its "natural" hover point.
*   **Effect of Decreasing:** Safer for indoor testing; ensures the drone can't "power out" of a situation with more than a certain amount of force.

### Use Case Recommendations
*   **Standard Quad:** **Keep Default (800).** This is safe and effective.
*   **Heavy Lift / Delivery Drone:** **Increase to 1000 (if needed).** If your payload is so heavy that you hover at 75% throttle, you need the full 1000 range to ensure the drone can still climb effectively.
*   **Tethered Drone:** **Decrease to 400.** If the drone is on a power-tether, you want to strictly limit how much it can pull on the cable if the sensors fail.

### Troubleshooting
*   **Scenario:** Drone hovers perfectly at the start of the flight, but starts to sink slowly as the battery gets low, and never recovers.
    *   **Diagnosis:** `PSC_ACCZ_IMAX` is too low. The drone needs more than 80% authority to stay level at low voltage, but the integrator is hitting the cap.
    *   **Fix:** Increase `PSC_ACCZ_IMAX` to 1000.
