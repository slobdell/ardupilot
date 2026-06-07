---
layout: parameter
name: TKOFF_THR_DELAY
display_name: Takeoff Throttle Delay
description: Time delay between the acceleration trigger and the motor starting.
default_value: 2
range: 0 127
units: ds
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/takeoff.cpp#L16
---

# Takeoff Throttle Delay (TKOFF_THR_DELAY)

## Description
`TKOFF_THR_DELAY` is a critical safety timer. It provides a brief pause between when you **throw** the plane and when the **propeller starts spinning**.

This delay is essential for hand-launches with pusher-propellers (motors at the back). It gives you enough time to move your hand away from the fuselage so that your fingers are not struck by the rotating blades.

*   **Units:** Deci-seconds (1/10th of a second).
*   **2 (Default):** 0.2 seconds.
*   **Recommendation:** Use at least **2** for all hand launches. Use **20-30** (2-3 seconds) for bungee/catapult launches.

## The Mathematics
The delay is a hard timer ($T_{wait}$) applied after the acceleration check passes:

$$ T_{wait} = \text{TKOFF\_THR\_DELAY} \times 0.1 \text{ seconds} $$

The throttle is held at 0% until this timer expires. After expiration, the `TKOFF_THR_MINSPD` check is performed.

## The Engineer's View
Defined in `ArduPlane/takeoff.cpp`.

```cpp
// ArduPlane/takeoff.cpp
uint16_t wait_time_ms = MIN(uint16_t(g.takeoff_throttle_delay)*100,12700);
```

The maximum allowed delay is 12.7 seconds. This is sufficient for even the longest catapult rails or complex bungee setups.

## Tuning & Behavior
*   **Default Value:** 2 (0.2s).
*   **Effect of Increasing:** The motor starts later. Safe for your hands, but the plane will lose more altitude before the motor takes over.
*   **Effect of Decreasing:** The motor starts sooner. High risk of prop-striking your hand during launch.

### Use Case Recommendations
*   **Bungee Launch:** Set to **30 (3.0s)**. This ensures the bungee ring has completely detached from the plane's hook before the propeller starts spinning, preventing the line from tangling in the motor.
*   **Hand Launch (Front Prop):** Set to **0 or 1**. Your hand is behind the motor, so risk is low.
*   **Hand Launch (Pusher Prop):** Set to **2 or 5**. You need to be fast, but safe.