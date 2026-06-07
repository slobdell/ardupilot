---
default_value: 0
description: Below this ground speed weathervaning is permitted. Set to 0 to ignore this condition when checking if vehicle should weathervane.
display_name: Weathervaning max ground speed
group: WVANE
investigation_status: complete
layout: parameter
name: WVANE_SPD_MAX
range: 0 50
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L78
units: m/s
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Weathervaning max ground speed (WVANE_SPD_MAX)

## Description
This parameter defines a maximum ground speed threshold for active weathervaning. If the aircraft is moving across the ground faster than this speed, the weather vane controller is automatically disabled.

This is typically used to ensure that weathervaning only occurs during hover or slow maneuvering, and not during high-speed forward flight where the aerodynamics of the airframe (like a vertical tail) or other navigation controllers should take precedence.

## The Mathematics
The controller checks the magnitude of the horizontal velocity vector ($V_{xy}$).

$ If \quad ||V_{xy}|| > SPD\_MAX \quad \rightarrow \quad Disable \quad Weathervaning $

The logic requires a valid velocity estimate from the AHRS/EKF. If speed is unknown, weathervaning is disabled for safety.

## The Engineer's View
In `AC_WeatherVane::get_yaw_out`, this check uses `vel_ned.xy().length_squared()` against `_max_vel_xy` squared to avoid square root operations.
If `SPD_MAX` is set to 0, this check is skipped (weathervaning allowed at any speed).

## Tuning & Behavior
*   **Default Value:** 0 (Disabled/Unlimited) for Plane, typically higher for Copter.
*   **Range:** 0 to 50 m/s.
*   **Effect of Increasing:** Allows weathervaning at higher ground speeds.
*   **Effect of Decreasing:** Restricts weathervaning to lower speeds.
*   **Note:** If set to 0, the speed check is ignored.