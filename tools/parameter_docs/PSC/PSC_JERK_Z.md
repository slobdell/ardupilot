---
layout: parameter
name: PSC_JERK_Z
display_name: Position Control Jerk Z (Vertical)
description: Limits the rate of change of acceleration for vertical movement. Controls the smoothness of takeoff, landing, and altitude transitions.
default_value: 5.0
range: 5.0 50.0
units: m/s/s/s
group: PSC
visual_asset_id: psc_jerk_z_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L324
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.h#L521
---

# Position Control Jerk Z (Vertical) (PSC_JERK_Z)

## Description
`PSC_JERK_Z` defines the vertical "acceleration ramp." It limits how quickly the drone can change its vertical acceleration. 

In simple terms, it prevents the drone from "punching" the throttle or "slamming" the brakes when changing altitude. A high jerk value allows the drone to reach its target climb rate instantly, while a low value makes it "float" into the climb.

*   **Low Value:** Altitude changes feel very smooth and gentle. The drone "glides" into a stop. Ideal for cinematography or passenger-carrying vehicles.
*   **High Value:** The drone is very responsive to height changes. It stops exactly on the target line with no hesitation.
*   **Too High:** Can cause mechanical stress on the frame and battery, and potentially lead to vertical "ringing" as the motors try to achieve physically impossible acceleration rates.

## The Mathematics
Vertical Jerk ($j_z$) is the rate of change of vertical acceleration ($a_z$):

$$ j_z(t) = \frac{da_z}{dt} = \frac{d^3z}{dt^3} $$

The ArduPilot shaper ensures that:

$$ |\vec{A}_{z\_target}(t) - \vec{A}_{z\_target}(t-dt)| \leq j_{z\_limit} \cdot dt $$

Where $j_{z\_limit}$ is `PSC_JERK_Z`.

## The Engineer's View
This parameter is the `_shaping_jerk_z` member in `AC_PosControl`.

It is used in `AC_PosControl::set_max_speed_accel_z()` to initialize the vertical shaper:

```cpp
// AC_PosControl.cpp
_jerk_max_z_cmsss = _shaping_jerk_z * 100.0;
```

The shaper is applied in `AC_PosControl::input_pos_vel_accel_z()`, where the commanded altitude is transformed into a kinematically consistent target that the drone's motors can actually follow.

## Tuning & Behavior
*   **Default Value:** 5.0 m/s³
*   **Range:** 5.0 - 50.0 m/s³
*   **Effect of Increasing:** Snappier takeoff and landing. More aggressive response to altitude stick (throttle).
*   **Effect of Decreasing:** Smoother, "softer" vertical movement. Great for reducing camera gimbal "bob" during climb-out.

### Use Case Recommendations
*   **Cinematography:** **Keep Default (5.0) or decrease to 2.5.** Standard 5.0 is already quite smooth, but for very slow cinematic reveals, lower is better.
*   **Autonomous Landing (Precision):** **Increase to 10.0 - 15.0.** When landing on a small target or a moving platform, you want the altitude controller to be extremely responsive to avoid "drifting" during the touchdown phase.
*   **Industrial Inspection:** **Increase to 10.0.** Allows the drone to maintain a consistent distance from a structure (e.g., wind turbine blade) even in gusty vertical air.

### Troubleshooting
*   **Scenario:** Drone "over-accelerates" vertically when the throttle stick is moved small amounts, making fine altitude adjustments difficult.
    *   **Diagnosis:** `PSC_JERK_Z` might be too high for the vehicle's thrust-to-weight ratio.
    *   **Fix:** Reduce `PSC_JERK_Z` to 5.0 or 2.5.
