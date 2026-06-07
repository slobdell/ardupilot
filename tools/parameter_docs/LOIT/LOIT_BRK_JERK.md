---
layout: parameter
name: LOIT_BRK_JERK
display_name: Loiter Braking Jerk
description: Defines how smoothly the drone initiates the braking maneuver when the sticks are centered in Loiter mode. Lower values create a "gentle" stop.
default_value: 500
range: 500 5000
units: cm/s/s/s
group: LOIT
visual_asset_id: loit_brk_jerk_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L64
---

# Loiter Braking Jerk (LOIT_BRK_JERK)

## Description
`LOIT_BRK_JERK` determines the **"Feel"** of the brakes. While `LOIT_BRK_ACCEL` determines the *force* used to stop, `LOIT_BRK_JERK` determines how quickly that force is applied.

*   **Low Value (500):** The drone will "ease into" its braking move. This prevents the drone from jerking the camera gimbal when you release the stick.
*   **High Value (2000+):** The drone will "snap" into its braking move instantly. This feels very responsive but can be mechanically stressful.

**Pro-Tip:** If you want your drone to stop fast but not look jerky on camera, use a **High `LOIT_BRK_ACCEL`** combined with a **Low `LOIT_BRK_JERK`**. This allows the drone to reach a high braking power, but ramps that power up smoothly.

## The Mathematics
This parameter limits the rate of change of the braking acceleration ($a_{brake}$):

$$ \left| \frac{da_{brake}}{dt} \right| \leq \text{LOIT\_BRK\_JERK} $$

Where:
*   $\text{LOIT\_BRK\_JERK}$ is in cm/s³.
*   **Example:** If set to 500, it will take 0.5 seconds to reach a full 250 cm/s² braking acceleration.

## The Engineer's View
This parameter is the `_brake_jerk_max_cmsss` member in `AC_Loiter`.

It is applied at the transition between the **Pilot Input State** and the **Braking State**. When the pilot centers the sticks, the EKF position at that moment is used as the target, and this jerk-limited shaper is used to calculate the deceleration path.

```cpp
// AC_Loiter.cpp
// Braking shaper logic uses _brake_jerk_max_cmsss to smooth the transition to zero velocity.
```

## Tuning & Behavior
*   **Default Value:** 500 cm/s³ (0.5 m/s³)
*   **Range:** 500 - 5000 cm/s³
*   **Effect of Increasing:** The drone reacts faster when you let go of the stick. Stops feel "robotic" and crisp.
*   **Effect of Decreasing:** Stops feel "organic" and fluid. Reduces gimbal oscillation during the braking phase.

### Use Case Recommendations
*   **High-End Cinematography:** **Keep Default (500).** This is the sweet spot for smooth camera work.
*   **Search and Rescue / Industrial:** **Increase to 1500.** When searching for an object, you want the drone to stop exactly where you saw it, with no lazy "gliding."
*   **Small Stiff Frames (Racing):** **Set to 2500.** These frames handle jerk well and benefit from the faster response.

### Troubleshooting
*   **Scenario:** When I let go of the stick, the drone makes a sudden "thump" sound from the motors before it starts to slow down.
    *   **Diagnosis:** `LOIT_BRK_JERK` is too high, commanding a torque change faster than the frame can handle.
    *   **Fix:** Reduce `LOIT_BRK_JERK` to 500.