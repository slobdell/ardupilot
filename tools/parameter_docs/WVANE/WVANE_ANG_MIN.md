---
default_value: 1
description: The minimum target roll/pitch angle before active weathervaning will start.  This provides a dead zone that is particularly useful for poorly trimmed quadplanes.
display_name: Weathervaning min angle
group: WVANE
investigation_status: complete
layout: parameter
name: WVANE_ANG_MIN
range: 0 10
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L57
units: deg
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Weathervaning min angle (WVANE_ANG_MIN)

## Description
This parameter sets a "Deadzone" for the weather vane controller. It defines the minimum amount of roll (or pitch) lean the aircraft must experience before the controller begins to apply any yaw correction.

This prevents the aircraft from constantly "hunting" or jittering in response to small turbulence or minor trim offsets. It ensures the controller only reacts to significant wind forces.

## The Mathematics
The deadzone is subtracted from the absolute error angle.

$ Error_{effective} = \max( |Angle_{measured}| - ANG\_MIN, 0 ) $

If the measured angle is less than `ANG_MIN`, the error is zero, and no yaw output is generated.

## The Engineer's View
In `AC_WeatherVane::get_yaw_out`, the parameter is converted to centi-degrees (`deadzone_cdeg`) and used as a threshold.
It is applied to both Roll and Pitch (if `PITCH_ENABLE` is set) axes.

## Tuning & Behavior
*   **Default Value:** 1.0 degree
*   **Range:** 0 to 10 degrees
*   **Effect of Increasing:** Increases the deadzone. The aircraft will tolerate more lean before correcting. Useful if the aircraft is poorly trimmed or if you want to allow some side-slip.
*   **Effect of Decreasing:** Makes the controller more sensitive. Setting it to 0 means it will react to even the slightest roll angle, which may cause continuous small yaw corrections.