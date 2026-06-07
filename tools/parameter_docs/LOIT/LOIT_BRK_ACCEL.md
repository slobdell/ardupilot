---
layout: parameter
name: LOIT_BRK_ACCEL
display_name: Loiter Braking Acceleration
description: Defines how aggressively the drone "brakes" when the pilot releases the sticks in Loiter mode. High values lead to sudden, sharp stops.
default_value: 250
range: 25 500
units: cm/s/s
group: LOIT
visual_asset_id: loit_brk_accel_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L55
---

# Loiter Braking Acceleration (LOIT_BRK_ACCEL)

## Description
`LOIT_BRK_ACCEL` determines the "stopping distance" of your drone in Loiter mode. It defines the maximum deceleration the drone is allowed to use when you let go of the control sticks.

Think of it as the difference between a car with standard brakes and one with racing brakes. 
*   **Low Value (e.g. 50):** The drone will "coast" for a long distance after you release the stick. This looks very graceful on camera but can be dangerous if you need to stop quickly to avoid a tree.
*   **High Value (e.g. 400):** The drone will "slam on the brakes," pitching up aggressively to stop in its tracks.
*   **Default (250):** 2.5 m/s². A balanced stop that doesn't stress the frame but keeps the drone safe.

## The Mathematics
The path shaper calculates the required deceleration ($a_{brake}$) to reach zero velocity:

$$ a_{brake} = \text{constrain}\left( \frac{V_{current}^2}{2 \cdot \text{Dist}_{to\_target}}, 0, \text{LOIT\_BRK\_ACCEL} \right) $$

If you release the sticks while flying at 10 m/s, and `LOIT_BRK_ACCEL` is 250 (2.5 m/s²), it will take exactly **4 seconds** and **20 meters** for the drone to come to a complete stop.

## The Engineer's View
This parameter is the `_brake_accel_cmss` member in `AC_Loiter`.

It is specifically triggered when the sticks return to the **Deadzone** (`THR_DZ`). One advanced technical detail is that **Braking uses a different Jerk limit** (`LOIT_BRK_JERK`). This allows you to have a very high `LOIT_BRK_ACCEL` (for safety) but a low Jerk limit so the *start* of the braking maneuver isn't too violent for the gimbal.

```cpp
// AC_Loiter.cpp
// Logic for entering the "Braking State" and applying _brake_accel_cmss.
```

## Tuning & Behavior
*   **Default Value:** 250 cm/s² (2.5 m/s²)
*   **Range:** 25 - 500 cm/s²
*   **Effect of Increasing:** Shorter stopping distance. Drone feels more "responsive" to stick centering.
*   **Effect of Decreasing:** Smoother, "lazier" stops. Much better for cinematic "flow."

### Use Case Recommendations
*   **Cinematography:** **Decrease to 100 - 150.** This prevents the drone from jerking the horizon every time you finish a move.
*   **Precision Industrial Flight:** **Increase to 350 - 400.** If you are flying 1 meter away from a building, you want the drone to stop *instantly* when you release the stick.
*   **Racing:** **Keep Default or Increase.** You need reliable stopping power to hit gates in Loiter mode.

### Troubleshooting
*   **Scenario:** I release the stick, and the drone tilts back so hard that the landing gear appears in the camera shot.
    *   **Diagnosis:** `LOIT_BRK_ACCEL` is too high, or `LOIT_BRK_JERK` is too high.
    *   **Fix:** Reduce `LOIT_BRK_ACCEL` to 150.
*   **Scenario:** I release the stick, but the drone keeps drifting for 5-10 meters before stopping.
    *   **Diagnosis:** `LOIT_BRK_ACCEL` is too low.
    *   **Fix:** Increase `LOIT_BRK_ACCEL` to 300.