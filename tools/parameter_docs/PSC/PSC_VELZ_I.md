---
layout: parameter
name: PSC_VELZ_I
display_name: Position Control Velocity (Vertical) I Gain
description: Integral gain for the vertical velocity loop. Corrects long-term climb/descent rate errors.
default_value: 0.0
range: 0.02 1.00
units: 
group: PSC
visual_asset_id: psc_velz_i_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L173
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_Basic.cpp#L20
---

# Position Control Velocity (Vertical) I Gain (PSC_VELZ_I)

## Description
`PSC_VELZ_I` is the **Integral** term for the vertical velocity controller. It works to eliminate persistent errors in climb or descent rates. 

While the innermost acceleration loop (`PSC_ACCZ_I`) handles gravity and hover throttle, the vertical velocity loop ensures that if you command a 1 m/s climb, you actually get exactly 1 m/s, even if there is an updraft or downdraft. 

*   **Note:** In many multirotor configurations, this is set to **0.0** by default. This is because the innermost Acceleration loop is so effective at maintaining the vertical state that an additional integrator in the velocity loop often adds unnecessary complexity and potential for oscillation.
*   **Too Low:** The drone may not reach its target climb/descent speed in high-drag situations.
*   **Too High:** Can cause vertical "surging" or low-frequency bouncing during altitude changes.

## The Mathematics
This parameter scales the accumulation of vertical velocity error:

$$ \vec{A}_{z\_target} += \int_0^t (V_{z\_target} - V_{z\_current}) \cdot k_I \cdot dt $$

Where:
*   $k_I$ is `PSC_VELZ_I`.
*   The integral accumulates the error between commanded and actual vertical speed.

## The Engineer's View
This parameter is the `_ki` member of the `_pid_vel_z` object (class `AC_PID_Basic`) inside `AC_PosControl`.

It is executed in `AC_PosControl::update_z_controller()`:

```cpp
// AC_PosControl.cpp
_accel_target.z = _pid_vel_z.update_all(_vel_target.z, curr_vel_z, _dt, ...);
```

By default, the `AC_PID_Basic` vertical velocity PID is initialised with `kI = 0` in the `AC_PosControl` constructor.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard Multirotor)
*   **Range:** 0.02 - 1.00
*   **Effect of Increasing:** Better adherence to target climb rates under load or in heavy vertical wind.
*   **Effect of Decreasing:** Smoother vertical transitions, less vertical "hunting."

### Use Case Recommendations
*   **Heavy Lift / Tethered:** **Consider setting to 0.1.** Helps the drone overcome the constant downward pull of a heavy cable to maintain a precise climb rate.
*   **Standard GPS Drones:** **Keep at 0.0.** The default cascaded architecture is designed to work without this integrator.
*   **High Performance / Racing:** **Keep at 0.0.** Vertical speed is handled by the high-frequency P-gain (`PSC_VELZ_P`) and the Acceleration loop.

### Troubleshooting
*   **Scenario:** Drone oscillates up and down slowly (1 second per bounce) only when climbing at high speeds.
    *   **Diagnosis:** `PSC_VELZ_I` is too high, causing vertical phase lag.
    *   **Fix:** Reduce `PSC_VELZ_I` to 0.0 or 0.05.
