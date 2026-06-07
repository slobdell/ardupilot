---
layout: parameter
name: PSC_JERK_XY
display_name: Position Control Jerk XY
description: Limits the rate of change of acceleration for horizontal movement. Controls the smoothness of the "S-Curve" path generation.
default_value: 5.0
range: 1.0 20.0
units: m/s/s/s
group: PSC
visual_asset_id: psc_jerk_xy_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L315
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.h#L57
---

# Position Control Jerk XY (PSC_JERK_XY)

## Description
`PSC_JERK_XY` defines the "smoothness" of the drone's horizontal movements. In physics, **Jerk** is the rate at which acceleration changes. High jerk means the drone snaps into a lean instantly; low jerk means it rolls into the lean gracefully.

ArduPilot uses **S-Curve Kinematics** to generate paths. Instead of jerky, "bang-bang" movements, the controller shapes the velocity profile so that acceleration and deceleration are applied gradually, respecting this Jerk limit.

*   **Low Value:** Flight feels very "fluid" and "soft." Ideal for cinematography.
*   **High Value:** Flight feels "robotic" and "snappy." The drone stops and starts with minimal lag.
*   **Too High:** Can cause mechanical stress or "ringing" (oscillation) as the motors try to change the vehicle's attitude faster than is physically possible.

## The Mathematics
Jerk ($j$) is the third derivative of position ($p$):

$$ j(t) = \frac{d\vec{A}}{dt} = \frac{d^3\vec{P}}{dt^3} $$

In the ArduPilot shaper, this parameter limits the slope of the acceleration curve:

$$ |\vec{A}_{target}(t) - \vec{A}_{target}(t-dt)| \leq j_{limit} \cdot dt $$

Where $j_{limit}$ is `PSC_JERK_XY`.

## The Engineer's View
This parameter is the `_shaping_jerk_xy` member in `AC_PosControl`. 

It is used in `AC_PosControl::set_max_speed_accel_xy()` to initialize the kinematic path generators:

```cpp
// AC_PosControl.cpp
_jerk_max_xy_cmsss = _shaping_jerk_xy * 100.0;
```

Crucially, the code includes a **Safety Override**: it will automatically lower your jerk limit if the Attitude Controller's maximum angular rates (`ATC_RAT_RLL_P` etc.) are too low to support the requested snap. It ensures the position controller doesn't "ask" for a lean faster than the drone can rotate.

## Tuning & Behavior
*   **Default Value:** 5.0 m/s³
*   **Range:** 1.0 - 20.0 m/s³
*   **Effect of Increasing:** Snappier response to stick inputs in Loiter. Tighter cornering in Auto missions.
*   **Effect of Decreasing:** Smoother, "lazier" movement. Great for reducing "jello" in video.

### Use Case Recommendations
*   **Cinematic Drone:** **Decrease to 1.0 - 2.5.** Creates beautiful, smooth transitions between hover and flight.
*   **Industrial / Delivery:** **Keep Default (5.0).** Good balance of speed and mechanical preservation.
*   **Racing / Aggressive Auto:** **Increase to 10.0 - 15.0.** Necessary for high-speed obstacle avoidance where every millisecond of acceleration counts.

### Troubleshooting
*   **Scenario:** Drone "bobs" or "overshoots" slightly when stopping, despite high D-gain.
    *   **Diagnosis:** `PSC_JERK_XY` might be too low, preventing the drone from applying brakes fast enough.
    *   **Fix:** Increase `PSC_JERK_XY` in increments of 1.0.
