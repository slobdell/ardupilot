---
layout: parameter
name: ATC_RAT_RLL_IMAX
display_name: Roll Axis Rate I-Term Maximum
description: The maximum limit for the roll rate integrator. Prevents "Integrator Windup" by capping how much motor authority the controller can use to fix long-term attitude errors.
default_value: 0.5
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_rat_rll_imax_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L32
---

# Roll Axis Rate I-Term Maximum (ATC_RAT_RLL_IMAX)

## Description
`ATC_RAT_RLL_IMAX` is a critical safety fuse for your drone's roll control. It limits the maximum power the **Integral (I) term** is allowed to accumulate.

The I-term is designed to "learn" offsets—like a heavy battery mounted to one side. However, if the drone is physically unable to roll (e.g., a prop is broken, or it's tangled in a branch), the I-term will keep increasing its demand until it reaches 100% motor power. This is called "windup." If the drone suddenly breaks free with a wound-up integrator, it will flip over instantly. `ATC_RAT_RLL_IMAX` prevents this by putting a hard ceiling on that "memory" authority.

*   **Low Value:** Limits the drone's ability to fly if it is significantly off-balance.
*   **High Value:** Allows for massive imbalance correction, but increases the risk of violent flips if the drone becomes stuck and then breaks free.
*   **Default (0.5):** Allows the integrator to use up to 50% of the motor's remaining authority to correct for roll errors.

## The Mathematics
The integrator ($	ext{Int}$) is accumulated every time step but is clamped by this value:

$$ 	ext{Int}_{new} = 	ext{constrain}(	ext{Int}_{prev} + 	ext{error} 
k_I 
dt, -	ext{IMAX}, 	ext{IMAX}) $$

Where:
*   $	ext{IMAX}$ is `ATC_RAT_RLL_IMAX`.
*   The output is a value between $0$ and $1.0$ representing motor mixer authority.

## The Engineer's View
This parameter maps to `_kimax` in the `_pid_rate_roll` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_integrator = constrain_float(_integrator + (error * _ki * dt), -_kimax, _kimax);
```

ArduPilot also uses **Throttle-Limited Anti-Windup**: If the pilot is already at 100% throttle, the integrator is not allowed to increase further in the positive direction. This ensures that the drone always prioritizes manual throttle commands over the integrator's "learned" corrections when the motors are saturated.

## Tuning & Behavior
*   **Default Value:** 0.5 (50% authority)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** Greater ability to stabilize very off-balance drones (e.g., asymmetric payloads).
*   **Effect of Decreasing:** Safer; reduces the chance of the drone "darting" or flipping after a crash or entanglement.

### Use Case Recommendations
*   **Standard GPS Photography Drone:** **Keep Default (0.5).** Balanced safety and stability.
*   **Asymmetric Special Purpose Vehicles:** **Increase to 0.7 - 0.8.** If your drone is carrying a heavy sensor off-center, it needs more I-term authority to hold a stable hover.
*   **Indoor / Education / Micro Drones:** **Decrease to 0.3.** Smaller drones have less inertia and flip faster; a lower IMAX makes them much safer for indoor mishaps.

### Troubleshooting
*   **Scenario:** Drone hovers perfectly but stays tilted at 10 degrees for several seconds after a crash or being caught in a branch.
    *   **Diagnosis:** Integrator Windup.
    *   **Fix:** Reduce `ATC_RAT_RLL_IMAX` to 0.4.