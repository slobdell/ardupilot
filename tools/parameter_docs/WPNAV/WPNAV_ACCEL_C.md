---
layout: parameter
name: WPNAV_ACCEL_C
display_name: Waypoint Cornering Acceleration
description: Maximum lateral acceleration allowed when cornering between waypoints in Auto mode.
default_value: 0
range: 0 500
units: cm/s/s
group: WPNAV
visual_asset_id: wpnav_accel_c_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L104
---

# Waypoint Cornering Acceleration (WPNAV_ACCEL_C)

## Description
`WPNAV_ACCEL_C` controls how "hard" the drone turns at waypoints during an autonomous mission. 

It defines the maximum centripetal acceleration allowed during a cornering maneuver. This parameter determines whether the drone will slow down significantly to hit a sharp point, or maintain speed by flying a wider, more graceful arc.

*   **0 (Default):** Uses **2x** the value of `WPNAV_ACCEL`. This is usually the best setting for a smooth mission.
*   **High Value:** The drone will maintain high speed through corners, pulling high Gs. This looks aggressive and "jerky" but completes missions faster.
*   **Low Value:** The drone will slow down significantly as it approaches waypoints to avoid high lateral forces.

## The Mathematics
The maximum cornering speed $v_{max}$ is calculated based on the radius of the turn $r$ and this acceleration limit $a_c$:
$$ v_{max} = \sqrt{a_c \cdot r} $$

Where $a_c$ is `WPNAV_ACCEL_C`.

If the drone is flying at `WPNAV_SPEED` and encounters a turn where the radius is too tight for the current $a_c$, it must decelerate before entering the turn.

## The Engineer's View
Used in `AC_WPNav::advance_wp_target_along_track()` and passed to the S-Curve trajectory generator.
The S-Curve logic uses this to calculate the "cornering arc" that connects two mission legs. If `WPNAV_ACCEL_C` is very high, the drone will start the turn much closer to the physical waypoint.

## Tuning & Behavior
*   **Default Value:** 0 (Defaults to $2 \times \text{WPNAV\_ACCEL}$)
*   **Recommendation:** Leave at **0** for general use.
*   **Racing/Speed Missions:** Increase to **400 or 500** to maintain maximum momentum. Ensure your `ANGLE_MAX` and motor thrust can handle the resulting lean angles.
*   **Cinematography:** Decrease to **50 or 100** (or keep default 0) to ensure the camera gimbal isn't subjected to high lateral G-forces during turns.