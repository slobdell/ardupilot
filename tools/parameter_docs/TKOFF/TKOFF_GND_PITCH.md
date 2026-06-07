---
layout: parameter
name: TKOFF_GND_PITCH
display_name: Takeoff Ground Pitch
description: The pitch angle (in degrees) to hold while the aircraft is rolling on the runway before reaching rotation speed.
default_value: 5
range: 0 15
units: deg
group: TKOFF
visual_asset_id: rolling_takeoff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/mode_takeoff.cpp#L52
---

# Takeoff Ground Pitch (TKOFF_GND_PITCH)

## Description
`TKOFF_GND_PITCH` is used for **Runway Takeoffs**. It defines the attitude of the aircraft while it is accelerating along the ground, before it has reached enough speed to lift its nose and fly.

For tricycle gear aircraft (nose wheel), this is usually set to **0 or 5 degrees** to keep the plane level on its wheels. For taildraggers, this setting helps the autopilot manage the transition from "tail on ground" to "tail in air" (level roll).

*   **Default Value:** 5 degrees.

## The Engineer's View
Defined in `ArduPlane/mode_takeoff.cpp`. 
This parameter is active whenever the airspeed is below `TKOFF_ROTATE_SPD`. It ensures the autopilot doesn't try to pull up too early, which would cause the tail to strike the ground or the plane to "jump" off the runway prematurely.

```cpp
// ArduPlane/takeoff.cpp
if (auto_state.highest_airspeed < g.takeoff_rotate_speed) {
    nav_pitch_cd = int32_t(100.0f * mode_takeoff.ground_pitch);
    // ...
}
```

## Tuning & Behavior
*   **Default Value:** 5°.
*   **Recommendation:** Match the "Natural" sitting angle of your drone on its wheels. 
*   **Tricycle Gear:** Use **0 or 2 degrees**.
*   **Taildragger:** Use **5 or 8 degrees** to help lift the tail wheel off the ground during the takeoff run.