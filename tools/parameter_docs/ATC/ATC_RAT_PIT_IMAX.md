---
layout: parameter
name: ATC_RAT_PIT_IMAX
display_name: Pitch Axis Rate I-Term Maximum
description: The maximum limit for the pitch rate integrator. Prevents "Integrator Windup" by capping how much motor authority the controller can use to fix forward/backward balance errors.
default_value: 0.5
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_rat_pit_imax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L32
---

# Pitch Axis Rate I-Term Maximum (ATC_RAT_PIT_IMAX)

## Description
`ATC_RAT_PIT_IMAX` is a vital safety fuse specifically for the drone's longitudinal balance. It limits the maximum power the **Integral (I) term** is allowed to use to correct for pitch errors.

Because most drones carry their payloads (cameras) and batteries along the pitch axis, they are frequently slightly nose-heavy or tail-heavy. The I-term learns to compensate for this. However, if the drone is physically stuck (e.g., in a tree) or if a front motor has failed, the I-term will "wind up" to 100% power trying to level the drone. If the drone suddenly breaks free, this massive, stored-up correction will cause it to flip over instantly. `ATC_RAT_PIT_IMAX` prevents this by capping that "learned authority."

*   **Low Value:** Limits the drone's ability to fly if it is nose-heavy or tail-heavy.
*   **High Value:** Allows for great balance correction, but increase the risk of a flip-on-recovery.
*   **Default (0.5):** Allows the integrator to use up to 50% of motor range to fix pitch errors.

## The Mathematics
The pitch integrator ($	ext{Int}$) is accumulated but clamped by this value:

$$ 	ext{Int}_{new} = 	ext{constrain}(	ext{Int}_{prev} + 	ext{error} 
k_I 
dt, -	ext{IMAX}, 	ext{IMAX}) $$

Where:
*   $	ext{IMAX}$ is `ATC_RAT_PIT_IMAX`.
*   The output is a $0.0$ to $1.0$ value used in the motor mixer.

## The Engineer's View
This parameter is the `_kimax` member of the `_pid_rate_pitch` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_integrator = constrain_float(_integrator + (error * _ki * dt), -_kimax, _kimax);
```

ArduPilot's **Saturation logic** also stops the integrator from increasing if the drone's throttle is already at zero or full, preventing it from fighting the pilot's primary vertical control.

## Tuning & Behavior
*   **Default Value:** 0.5 (Standard)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** Better ability to stabilize nose-heavy drones (like those with large DSLR gimbals on the front).
*   **Effect of Decreasing:** Safer for racing and testing; drone is less likely to flip after a minor collision.

### Use Case Recommendations
*   **Delivery Drones (Variable Payloads):** **Increase to 0.7 - 0.8.** If the weight moves or is dropped, the drone needs high authority to find its new level point quickly.
*   **Cinematography (Gimbal Protrusion):** **Keep at 0.5 or 0.6.** Ensures the drone stays perfectly level despite the long lever arm of a heavy camera.
*   **Standard FPV / Racing:** **Decrease to 0.4.** Minimizes the "bobbing" after a crash or gate-strike.

### Troubleshooting
*   **Scenario:** Drone flies level at hover, but as soon as you fly forward, it "sags" its nose and you have to constantly pull back.
    *   **Diagnosis:** `ATC_RAT_PIT_IMAX` is being hit. The drone is nose-heavy, but the integrator is capped.
    *   **Fix:** Increase `ATC_RAT_PIT_IMAX` to 0.7 or move the battery further back.