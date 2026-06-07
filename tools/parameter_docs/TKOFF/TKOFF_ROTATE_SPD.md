---
layout: parameter
name: TKOFF_ROTATE_SPD
display_name: Takeoff Rotate Speed
description: The airspeed (in m/s) at which the aircraft "rotates" its nose up to the climb angle during a runway takeoff.
default_value: 0
range: 0 30
units: m/s
group: TKOFF
visual_asset_id: rolling_takeoff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/takeoff.cpp#L198
---

# Takeoff Rotate Speed (TKOFF_ROTATE_SPD)

## Description
`TKOFF_ROTATE_SPD` is the "Fly Speed" for runway takeoffs. It defines the exact moment the autopilot pulls back on the elevator to lift the nose and start climbing.

If you set this too low, the plane might try to fly before it has enough speed, leading to a stall and a crash. If you set it too high, you will waste runway length and potentially damage your landing gear by rolling too fast.

*   **0 (Default):** The plane will rotate as soon as it feels enough airspeed to move the control surfaces (not recommended for runway takeoffs).
*   **Recommendation:** Set to **1.1x to 1.3x** your stall speed.

## The Engineer's View
Defined in `ArduPlane/takeoff.cpp`. 
The parameter acts as a state trigger. While `Airspeed < TKOFF_ROTATE_SPD`, the plane uses `TKOFF_GND_PITCH`. Once the threshold is crossed, the autopilot transitions to the mission climb pitch or `TKOFF_LVL_PITCH`.

```cpp
// ArduPlane/takeoff.cpp
if (!auto_state.rotation_complete && g.takeoff_rotate_speed > 0) {
    if (auto_state.highest_airspeed < g.takeoff_rotate_speed) {
        // Still rolling
    } else {
        // Rotate!
    }
}
```

## Tuning & Behavior
*   **Default Value:** 0.
*   **Effect of Increasing:** Safer takeoff with more lift energy. Requires a longer runway.
*   **Effect of Decreasing:** Shorter takeoff run. Higher risk of stalling during the initial climb.

### Use Case Recommendations
*   **Standard Build:** If your plane stalls at 12 m/s, set `TKOFF_ROTATE_SPD` to **14 or 15 m/s**.
*   **Hand/Catapult Launch:** Always set to **0**. You want the plane to enter climb mode immediately after it leaves your hand.
