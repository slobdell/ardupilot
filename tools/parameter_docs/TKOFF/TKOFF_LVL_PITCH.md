---
layout: parameter
name: TKOFF_LVL_PITCH
display_name: Takeoff Level-Flight Pitch
description: The target pitch angle (in degrees) used during the initial stage of takeoff before reaching TKOFF_LVL_ALT.
default_value: 15
range: 0 45
units: deg
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/mode_takeoff.cpp#L34
---

# Takeoff Level-Flight Pitch (TKOFF_LVL_PITCH)

## Description
`TKOFF_LVL_PITCH` is the "Launch Angle" for your airplane. It defines how steeply the plane should point its nose up immediately after being thrown or launched.

This initial pitch is maintained until the aircraft reaches the `TKOFF_LVL_ALT` (Stage 1 altitude). It ensures the drone gains altitude rapidly without stalling or wavering.

*   **Default Value:** 15 degrees.
*   **15 - 20 Degrees:** Standard for high-power park flyers and gliders.
*   **5 - 10 Degrees:** For heavy, low-power aircraft that need to prioritize airspeed over climb rate.

## The Engineer's View
Defined in `ArduPlane/mode_takeoff.cpp`. 
During the initial "Phase 1" of a takeoff mission, the autopilot ignores the standard TECS (Total Energy Control System) pitch demands and forces the nose to this specific angle. This provides a predictable and repeatable launch behavior.

```cpp
// ArduPlane/mode_takeoff.cpp
AP_GROUPINFO("LVL_PITCH", 3, ModeTakeoff, level_pitch, 15),
```

## Tuning & Behavior
*   **Default Value:** 15°.
*   **Effect of Increasing:** Steeper climb. Better for clearing nearby obstacles, but carries a higher risk of a stall if the motor power isn't sufficient.
*   **Effect of Decreasing:** Shallower climb. The plane gains airspeed faster but altitude slower.

### Troubleshooting
*   **Scenario:** The plane climbs steeply after I throw it, but then the wings wobble and it falls (Tip Stall).
    *   **Diagnosis:** `TKOFF_LVL_PITCH` is too high for your plane's weight or power. 
    *   **Fix:** Reduce to 10 or 12 degrees.
*   **Scenario:** I threw the plane perfectly, but it slowly drifted down into the tall grass.
    *   **Diagnosis:** `TKOFF_LVL_PITCH` is too low, or `TKOFF_THR_MAX` is too low.
    *   **Fix:** Increase to 18 degrees and ensure full throttle is allowed.