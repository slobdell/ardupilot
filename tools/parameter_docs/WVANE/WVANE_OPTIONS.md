---
default_value: 0
description: Options impacting weathervaning behaviour
display_name: Weathervaning options
group: WVANE
investigation_status: complete
layout: parameter
name: WVANE_OPTIONS
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L104
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.h#L33
units: Bitmask
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Weathervaning options (WVANE_OPTIONS)

## Description
This parameter controls advanced behavior modifiers for the Weather Vane controller. The Weather Vane controller automatically yaws the aircraft into the wind during VTOL flight to reduce drag and improve stability. 

By default, the controller primarily uses the **Roll** angle to detect if the aircraft is being blown sideways and applies a Yaw correction. Enabling specific options here allows the controller to also use **Pitch** information, providing a faster and more robust response when the wind is coming from the front or back.

## The Mathematics
When **Bit 0 (PITCH_ENABLE)** is active, the controller adds the pitch error to the total error term, increasing the aggressiveness of the yaw correction.

**Standard Logic (Bit 0 = 0):**
$$ Error = \max(|Roll_{deg}| - Deadzone, 0) $$

**Enhanced Logic (Bit 0 = 1):**
For **Nose In** weather vaning:
$$ Error = |Roll_{deg}| + \max(Pitch_{deg} - Deadzone, 0) $$
*(Only applied if Pitch > Deadzone)*

This effectively means that if the aircraft is pitching up to fight the wind (while nose-in), that pitch effort is treated as "misalignment" energy that needs to be converted into a yaw correction to face the wind more directly.

## The Engineer's View
This parameter is read in `AC_WeatherVane::get_yaw_out` inside `libraries/AC_AttitudeControl/AC_WeatherVane.cpp`.

It is cast to the `AC_WeatherVane::Options` enum.
*   **Bit 0 (`PITCH_ENABLE`)**: 
    *   Defined as `(1<<0)`.
    *   When set, it modifies the error calculation for `Direction::NOSE_IN` and `Direction::TAIL_IN`.
    *   For `NOSE_IN`: It checks if `pitch_cdeg` is positive (nose up) and exceeds the deadzone.
    *   For `TAIL_IN`: It checks if `pitch_cdeg` is negative (nose down) and exceeds the deadzone (in the negative direction).

This is particularly useful for QuadPlanes or Tailsitters where wind resistance manifests as both a roll moment (side force) and a pitch moment (drag).

## Tuning & Behavior
*   **Bit 0 (Value 1):** **Enable Pitch Input.**
    *   **Recommended For:** Aircraft that tend to "hang" in the wind with a high pitch angle but fail to yaw into it aggressively enough.
    *   **Effect:** Increases weathervaning gain effectively when the aircraft is pitching to hold position against the wind.

