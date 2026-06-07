---
default_value: 0
description: This converts the target roll/pitch angle of the aircraft into the correcting (into wind) yaw rate. e.g. Gain = 2, roll = 30 deg, pitch = 0 deg, yaw rate = 60 deg/s.
display_name: Weathervaning gain
group: WVANE
investigation_status: complete
layout: parameter
name: WVANE_GAIN
range: 0.5 4
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L48
units: 1/s
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Weathervaning gain (WVANE_GAIN)

## Description
This parameter controls the "strength" of the weather vaning response. It acts as a multiplier that converts the aircraft's lean angle (caused by wind) into a command to rotate (yaw) into the wind.

A higher gain means the aircraft will turn faster into the wind for a given amount of lean. A lower gain results in a gentler, slower turn.

## The Mathematics
The output is calculated by applying a Low Pass Filter (LPF) to the product of the error and the gain.

$ Rate_{yaw} = LPF( Error_{deg} \cdot Gain ) $

Where:
*   $ Error_{deg} $ is the calculated misalignment (mostly Roll angle, or Pitch angle if options enabled).
*   $ Gain $ is `WVANE_GAIN`.
*   $ LPF $ is a smoothing filter: $ y_n = 0.98 y_{n-1} + 0.02 x_n $

For example, if the aircraft is rolled 10 degrees due to wind and the Gain is 2.0, the target yaw rate will settle at 20 degrees per second.

## The Engineer's View
The parameter is used in `AC_WeatherVane::get_yaw_out`.
The heavy low-pass filter ($ \alpha = 0.02 $) is hardcoded to prevent oscillation and ensure smooth yaw changes. This means the weathervaning response is intentionally damped and will lag slightly behind the instantaneous roll angle.

## Tuning & Behavior
*   **Default Value:** 1 (Plane/Copter), 0 (Disabled/Other)
*   **Range:** 0.5 to 4.0
*   **Effect of Increasing:** The aircraft will yaw more aggressively into the wind. If set too high, it may overshoot or oscillate (wag its tail).
*   **Effect of Decreasing:** The aircraft will take longer to align with the wind.
*   **Dependencies:** `WVANE_ENABLE` must be active. `WVANE_OPTIONS` affects how the error is calculated.