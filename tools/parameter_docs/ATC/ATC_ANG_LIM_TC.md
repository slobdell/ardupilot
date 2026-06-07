---
layout: parameter
name: ATC_ANG_LIM_TC
display_name: Angle Limit Time Constant
description: Controls how quickly the drone reduces its maximum lean angle to prioritize altitude hold when motors are reaching their limit.
default_value: 1.0
range: 0.5 10.0
units: s
group: ATC
visual_asset_id: atc_ang_lim_tc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L86
---

# Angle Limit Time Constant (ATC_ANG_LIM_TC)

## Description
`ATC_ANG_LIM_TC` is a specialized safety parameter that handles "low-power" situations. 

Multirotors need vertical thrust to stay in the air. When they tilt (lean), some of that thrust is redirected sideways for movement. If you are carrying a heavy load or have a weak battery, the motors might reach 100% power just to stay level. If you then try to tilt by 30 degrees, the drone will lose lift and fall.

ArduPilot automatically calculates a "Safe Tilt Angle" based on how much throttle you have left. `ATC_ANG_LIM_TC` determines how fast that limit is applied. It ensures the drone prioritizes "not falling out of the sky" over "moving sideways."

*   **Low Value:** The drone will aggressively and instantly limit your tilt if it thinks it is about to lose altitude.
*   **High Value:** The drone will allow temporary "overshoots" of the tilt limit, relying on momentum before slowly enforcing the new safety limit.
*   **Default (1.0):** A slow, 1-second decay that provides a smooth transition when reaching power limits.

## The Mathematics
The controller calculates the maximum tilt ($\theta_{max}$) that can be sustained at the current throttle setting. This parameter smooths that limit:

$$ \theta_{lim\_smoothed} = \theta_{lim\_smoothed\_prev} + \frac{dt}{dt + \tau} \cdot (\theta_{max\_calculated} - \theta_{lim\_smoothed\_prev}) $$

Where:
*   $\tau$ is `ATC_ANG_LIM_TC`.
*   $\theta_{max\_calculated}$ is the physical limit based on motor saturation.

**Implication:** If you punch the throttle to climb, your available tilt angle drops. This parameter determines how quickly that drop is enforced on your stick inputs.

## The Engineer's View
This parameter is the `_angle_limit_tc` member in `AC_AttitudeControl`.

It is used in `AC_AttitudeControl_Multi::update_althold_lean_angle_max()`:

```cpp
// AC_AttitudeControl_Multi.cpp
float althold_lean_angle_max = acosf(constrain_float(throttle_in / (AC_ATTITUDE_CONTROL_ANGLE_LIMIT_THROTTLE_MAX * thr_max), 0.0f, 1.0f));
_althold_lean_angle_max = _althold_lean_angle_max + (_dt / (_dt + _angle_limit_tc)) * (althold_lean_angle_max - _althold_lean_angle_max);
```

This is a critical part of the **Altitude Hold prioritization** logic. By smoothing the limit, the drone prevents jerky "twitching" of the attitude when flying at the edge of its performance envelope.

## Tuning & Behavior
*   **Default Value:** 1.0s
*   **Range:** 0.5 - 10.0s
*   **Effect of Increasing:** The drone will be more "brave"—it will allow you to tilt aggressively even if it means losing a little altitude temporarily.
*   **Effect of Decreasing:** The drone is very "cautious"—it will flatten itself out immediately if it feels the motors working too hard.

### Use Case Recommendations
*   **Heavy Cargo Drones:** **Decrease to 0.5.** You want the safety limits to kick in instantly to prevent any vertical drop.
*   **Underpowered / Battery-Saving builds:** **Decrease to 0.5.** Helps keep the drone in a safe operating range.
*   **Racing / Acro-Loiter:** **Increase to 2.0.** Allows the pilot to "force" a tilt for a second to clear an obstacle, accepting a temporary loss in height.

### Troubleshooting
*   **Scenario:** During a fast forward dash in AltHold, the drone suddenly "nods" its nose up and slows down, even though my stick is still forward.
    *   **Diagnosis:** The drone hit its power limit and is enforcing the angle limit.
    *   **Fix:** If you have motor headroom, increase `ATC_ANG_LIM_TC` to 2.0 to make the correction less jarring.