---
layout: parameter
name: ATC_RAT_RLL_I
display_name: Roll Axis Rate I Gain
description: Integral gain for the roll rate controller. Corrects long-term steady-state errors where the drone fails to reach the requested roll rate.
default_value: 0.135
range: 0.01 2.0
units: 
group: ATC
visual_asset_id: atc_rat_rll_i_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L18
---

# Roll Axis Rate I Gain (ATC_RAT_RLL_I)

## Description
`ATC_RAT_RLL_I` is the "memory" of the roll controller. Its job is to fix persistent mistakes that the P-gain (`ATC_RAT_RLL_P`) isn't strong enough to handle.

If your drone is off-balance (e.g., the battery is mounted slightly to one side) or if there is a constant side-wind, the drone will naturally want to tilt. The I-term "notices" this persistent error and slowly builds up motor power on the weak side until the drone stays level. It is the parameter that ensures the drone actually *stays* where the sticks tell it to, rather than slowly drifting away.

*   **Low Value:** The drone will feel "drifty." It won't hold its angle precisely, especially when moving fast or in wind.
*   **High Value:** The drone holds its attitude very strictly.
*   **Too High:** The drone will develop a slow, rhythmic "wobble" (oscillation) as the integrator over-corrects and then has to unwind itself.

## The Mathematics
The I-term accumulates the rate error over time:

$$ \text{Out}_I += \int_0^t (\omega_{target} - \omega_{actual}) \cdot k_I \cdot dt $$

Where:
*   $k_I$ is `ATC_RAT_RLL_I`.
*   The output is capped by `ATC_RAT_RLL_IMAX` to prevent "Runaway" throttle.

**Anti-Windup:** ArduPilot includes advanced logic to stop the integrator from building up if the motors are already at 100% power, preventing the drone from flipping over if it hits an obstacle.

## The Engineer's View
This parameter is the `_ki` member of the `_pid_rate_roll` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_integrator += (error * _ki * dt);
_integrator = constrain_float(_integrator, -_kimax, _kimax);
```

In `AC_AttitudeControl_Multi`, the integrator is also affected by the **Throttle Mix** logic (`ATC_THR_MIX_MAN`), which determines how much priority the I-term gets compared to the pilot's throttle request.

## Tuning & Behavior
*   **Default Value:** 0.135 (Matches P-gain usually)
*   **Range:** 0.01 - 2.0
*   **Effect of Increasing:** Better attitude hold, less drift in wind, drone feels "heavier" and more stable.
*   **Effect of Decreasing:** Drone feels more agile and "loose," but requires more manual correction from the pilot.

### Use Case Recommendations
*   **Long-Distance Autonomy:** **Increase to 0.2 - 0.3.** Ensures the drone stays perfectly on its path for miles, even as weight changes (e.g., if carrying a liquid payload).
*   **Cinematography:** **Keep Default.** Standard values prevent the slow "integrator wobble" that can ruin a long tracking shot.
*   **FPV Freestyle:** **Decrease to 0.08 - 0.1.** Many freestyle pilots prefer a "looser" feel that allows the drone to follow its own momentum slightly more naturally during acrobatic flips.

### Troubleshooting
*   **Scenario:** Drone oscillates slowly (about 1-2 times per second) in the roll axis.
    *   **Diagnosis:** `ATC_RAT_RLL_I` is too high (Integrator oscillation).
    *   **Fix:** Reduce `ATC_RAT_RLL_I` by 0.02 until the wobble stops.