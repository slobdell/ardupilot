---
layout: parameter
name: WVANE_ENABLE
display_name: Weathervaning Enable
description: Enables the automatic yaw control to point the drone's nose (or tail/side) into the wind.
default_value: 0
range: -1 4
units: 
group: WVANE
visual_asset_id: wvane_enable_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_WeatherVane.cpp#L23
---

# Weathervaning Enable (WVANE_ENABLE)

## Description
`WVANE_ENABLE` activates a feature that allows the drone to act like a weather vane. When enabled, the drone will automatically rotate (yaw) so that it is always facing into the wind while hovering in a position-controlled mode (like Loiter or QLoiter).

This is extremely beneficial for **QuadPlanes** and **Long-Endurance Multirotors**. By pointing the nose into the wind, the drone minimizes its surface area and drag, which reduces the motor power needed to maintain position, leading to significantly longer flight times and better stability in gusty conditions.

*   **0: Disabled.** No automatic rotation.
*   **1: Nose into wind.** The drone points its front toward the wind.
*   **2: Nose or tail into wind.**
*   **3: Side into wind.**
*   **4: Tail into wind.**

## The Mathematics
The controller monitors the drone's current "Leaning Angle" (Roll/Pitch). Since the drone must lean against the wind to stay stationary, the roll angle $\phi$ is used as an error signal:
$$ \text{YawRate}_{cmd} = \text{WVANE\_GAIN} \cdot (\phi - \text{WVANE\_ANG\_MIN}) $$

The drone yaws until the roll angle required to maintain position is minimized (i.e., it is facing directly into the wind).

## The Engineer's View
Used in `AC_WeatherVane::get_yaw_out()`.
The logic includes a 2-second stability buffer to prevent the drone from spinning wildly during momentary gusts. Pilot yaw stick input always overrides the weathervaning action.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Recommendation:** 
    *   **QuadPlanes:** **Set to 1 (Nose into wind)**. This prevents the large wings from acting as a sail and destabilizing the hover.
    *   **Multicopters:** Set to **1** if you frequently fly in windy conditions to improve battery efficiency.
*   **Dependencies:** Requires a healthy position estimate (GPS) and `WVANE_GAIN` set correctly (usually 1.0).