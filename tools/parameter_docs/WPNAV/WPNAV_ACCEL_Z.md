---
layout: parameter
name: WPNAV_ACCEL_Z
display_name: Waypoint Vertical Acceleration
description: Defines the maximum vertical acceleration (in cm/s²) the drone is allowed to use during autonomous missions (Auto, RTL, Guided).
default_value: 100
range: 50 500
units: cm/s/s
group: WPNAV
visual_asset_id: wpnav_accel_z_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L70
---

# Waypoint Vertical Acceleration (WPNAV_ACCEL_Z)

## Description
`WPNAV_ACCEL_Z` is the "Vertical Gas Pedal" limit for autonomous flight. It determines how aggressively the drone initiates a climb or starts braking for a descent during a mission.

*   **Low Value (e.g. 50):** The drone starts and stops its climbs very gently. Ideal for delicate payloads or cinematography.
*   **High Value (e.g. 200):** The drone "punches" its way into climbs. Flight feels more robotic and rapid.
*   **Default (100):** 1.0 m/s². A safe, balanced setting for most multirotors.

**Constraint:** This value should generally be set **equal to or lower than** `PSC_ACCZ_P` authority. If you set `WPNAV_ACCEL_Z` higher than what the drone can physically achieve, you will get "Altitude Slop" where the drone falls behind its mission path.

## The Mathematics
This parameter sets the acceleration limit ($a_{z_max}$) for the vertical path shaper:

$$ V_z(t) = V_{z_initial} + \text{constrain}(a_{z_calc}, -a_{z_max}, a_{z_max}) \cdot dt $$

Where:
*   $a_{z_max}$ is `WPNAV_ACCEL_Z`.

The vertical shaper uses this to ensure that the transition between different vertical speeds follows a smooth ramp, preventing the "instant torque" shocks that can damage motor mounts.

## The Engineer's View
This parameter is the `_wp_accel_z_cmss` member in `AC_WPNav`.

One important engineering detail: **This limit is combined with the Jerk limit (`WPNAV_JERK`)**. The shaper will prioritize the jerk limit during the start of a move, and only reach full `WPNAV_ACCEL_Z` if the move is long enough. 

```cpp
// AC_WPNav.cpp
// Vertical shaper logic uses _wp_accel_z_cmss to calculate the velocity profile.
```

## Tuning & Behavior
*   **Default Value:** 100 cm/s² (1.0 m/s²)
*   **Range:** 50 - 500 cm/s²
*   **Effect of Increasing:** Snappier altitude corrections. Drone handles vertical "staircase" missions more efficiently.
*   **Effect of Decreasing:** Smoother, more flowing altitude changes. Greatly reduces the "bobbing" often seen in camera gimbal footage.

### Use Case Recommendations
*   **Cinematography:** **Decrease to 50 - 80.** Prevents the "jerk" seen on the horizon when the drone finishes a climb.
*   **Rapid Mapping (Terrain Following):** **Increase to 150.** When flying close to hills, the drone needs to accelerate vertically fast enough to follow the ground without crashing.
*   **Heavy Lift Cargo:** **Decrease to 50.** Minimizes the vertical G-load on the airframe during transitions.

### Troubleshooting
*   **Scenario:** Drone makes a loud "thump" sound from the motors at the very top of a climb.
    *   **Diagnosis:** `WPNAV_ACCEL_Z` is too high, causing a sudden motor current drop that triggers mechanical ringing.
    *   **Fix:** Reduce `WPNAV_ACCEL_Z` to 80.