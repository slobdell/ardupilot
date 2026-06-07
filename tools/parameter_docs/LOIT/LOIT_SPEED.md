---
layout: parameter
name: LOIT_SPEED
display_name: Loiter Horizontal Maximum Speed
description: Defines the maximum speed (in cm/s) the drone can travel horizontally in Loiter mode when the pilot's sticks are pushed to the limit.
default_value: 1250
range: 20 3500
units: cm/s
group: LOIT
visual_asset_id: loit_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L37
---

# Loiter Horizontal Maximum Speed (LOIT_SPEED)

## Description
`LOIT_SPEED` is the "Speed Limiter" for your drone's most common flight mode: **Loiter**.

When you push the pitch or roll stick all the way to the edge in Loiter mode, the drone doesn't just lean over to a fixed angle—it attempts to reach a specific ground speed. `LOIT_SPEED` defines what that maximum speed is.

*   **Standard Speed (1250):** 12.5 meters per second (45 km/h). A fast but manageable speed for general flight.
*   **High Speed:** Makes the drone feel much more capable during transits, but makes fine position adjustments more difficult because the stick sensitivity is higher.
*   **Low Speed:** Excellent for precision inspection or when learning to fly. It effectively makes the drone "un-crashable" from over-speeding.

## The Mathematics
The pilot's stick position ($S$, from -1 to 1) is linearly mapped to a **Target Velocity** ($V_{target}$):

$$ V_{target} = S \cdot \text{LOIT\_SPEED} $$

This target velocity is then passed to the **S-Curve shaper**, which ensures the drone accelerates smoothly to reach that speed without exceeding the `LOIT_ACC_MAX` limit.

**Precision Mode:** At very small stick deflections, ArduPilot uses a different sensitivity curve to allow for centimeter-level positioning even if `LOIT_SPEED` is set very high.

## The Engineer's View
This parameter is the `_speed_cms` member in `AC_Loiter`.

It is fundamentally different from **Stabilize** mode. In Stabilize, the stick controls **Angle**. In Loiter, the stick controls **Velocity**. This means that if you are flying at `LOIT_SPEED` and you let go of the sticks, the drone will automatically calculate the required "braking acceleration" to bring the velocity back to zero as quickly as possible.

```cpp
// AC_Loiter.cpp
// Stick input scaling logic uses _speed_cms.
```

## Tuning & Behavior
*   **Default Value:** 1250 cm/s (12.5 m/s)
*   **Range:** 20 - 3500 cm/s
*   **Effect of Increasing:** Faster travel between points in Loiter. Drone feels more powerful.
*   **Effect of Decreasing:** Drone feels "gentle" and safe. Stick movements result in smaller, more controlled speed changes.

### Use Case Recommendations
*   **Industrial Inspection:** **Decrease to 500.** When flying near a cell tower or bridge, you want the drone to move slowly even if you accidentally bump the stick.
*   **Standard Hobby Flight:** **Set to 1500 - 2000.** Allows for spirited flying while still maintaining the safety of a GPS-locked hover.
*   **Search and Rescue:** **Increase to 2500.** Speed is critical when searching large areas manually.

### Troubleshooting
*   **Scenario:** Drone feels very "twitchy" in Loiter—even a tiny stick move makes it lurch forward.
    *   **Diagnosis:** `LOIT_SPEED` is set too high for the pilot's skill level or the frame's agility.
    *   **Fix:** Reduce `LOIT_SPEED` to 1000.
*   **Scenario:** Drone can't fly against a 10 m/s wind in Loiter.
    *   **Diagnosis:** `LOIT_SPEED` must be higher than the wind speed to make progress. 
    *   **Fix:** Increase `LOIT_SPEED` to 1500.