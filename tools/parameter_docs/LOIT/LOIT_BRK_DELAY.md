---
layout: parameter
name: LOIT_BRK_DELAY
display_name: Loiter Brake Start Delay
description: Defines the time delay (in seconds) between the pilot centering the sticks and the drone actively applying its brakes in Loiter mode.
default_value: 0.1
range: 0 2.0
units: s
group: LOIT
visual_asset_id: loit_brk_delay_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L73
---

# Loiter Brake Start Delay (LOIT_BRK_DELAY)

## Description
`LOIT_BRK_DELAY` is a small but important "usability" setting for Loiter mode. It determines how long the drone should wait before it starts its active braking maneuver.

When you center your control sticks, the drone can either stop immediately or "coast" for a fraction of a second. This delay is useful because it prevents the drone from "jerking" its brakes if you are just passing the stick through the center point (e.g., when switching from flying forward to flying backward).

*   **Low Value (0.0):** The drone brakes the instant the stick enters the deadzone. This is the most responsive setting but can feel "twitchy" for your fingers.
*   **High Value (e.g. 1.0):** The drone will coast for a full second before it actively tries to stop. This feels very "loose" and is generally not recommended for precise flight.
*   **Default (0.1):** A tiny 100ms buffer that makes stick-centering feel natural without adding noticeable lag.

## The Mathematics
This parameter acts as a **Deadzone Timer** ($\Delta t_{idle}$). The Braking state is only entered if:

$$ \text{Stick\_In\_Deadzone\_Time} \geq \text{LOIT\_BRK\_DELAY} $$

If the pilot moves the stick out of the deadzone before the delay expires, the braking state is cancelled and the drone continues to follow the pilot's speed command.

## The Engineer's View
This parameter is the `_brake_delay` member in `AC_Loiter`.

It is a simple time-logic gate. In the `AC_Loiter::update()` loop, a counter tracks how many milliseconds have passed since the sticks were last outside the `THR_DZ`. This prevents the "SCurve Shaper" from resetting its target every time a pilot has a shaky finger.

```cpp
// AC_Loiter.cpp
// Timer logic for initiating the brake shaper.
```

## Tuning & Behavior
*   **Default Value:** 0.1s
*   **Range:** 0.0 - 2.0s
*   **Effect of Increasing:** The drone feels "smoother" to pilot commands but takes longer to come to a stop.
*   **Effect of Decreasing:** The drone stops instantly. Stick feel is much more "robotic."

### Use Case Recommendations
*   **High-Resolution Photography:** **Keep at 0.1.** This small buffer prevents tiny finger movements from triggering a gimbal-shaking brake maneuver.
*   **Tactical / FPV Loitering:** **Decrease to 0.0.** You want the absolute maximum responsiveness. If you center the stick, the drone must stop now.
*   **Beginner Training:** **Increase to 0.3.** Makes the drone feel more forgiving of "nervous" stick movements through the center point.

### Troubleshooting
*   **Scenario:** Drone seems to "hesitate" for a split second after I release the sticks before it finally starts to brake.
    *   **Diagnosis:** `LOIT_BRK_DELAY` is set too high.
    *   **Fix:** Reduce to 0.1 or 0.0.