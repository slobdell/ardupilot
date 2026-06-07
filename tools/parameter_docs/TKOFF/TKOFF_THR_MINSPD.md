---
layout: parameter
name: TKOFF_THR_MINSPD
display_name: Takeoff Throttle Min Speed
description: Minimum GPS ground speed required to unsuppress the throttle during automatic takeoff.
default_value: 0
range: 0 30
units: m/s
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/takeoff.cpp#L116
---

# Takeoff Throttle Min Speed (TKOFF_THR_MINSPD)

## Description
`TKOFF_THR_MINSPD` is a safety gate for your airplane's motor. It ensures that the propeller does not start spinning until the aircraft is already moving at a safe speed.

This is primarily used for **Hand Launches** and **Catapult Launches**. 
*   For **Hand Launches**, it prevents the motor from starting while the drone is still in your hand, protecting your fingers from a pusher-prop.
*   For **Catapults**, it ensures the motor only engages after the plane has gained some initial velocity from the bungee or rail.

*   **0 (Default):** Speed check is disabled. The motor starts as soon as the acceleration and delay checks pass.
*   **4.0 m/s:** Recommended for hand-launched pusher-prop planes.

## The Mathematics
The takeoff state machine evaluates three conditions in sequence:
1.  **Acceleration:** Longitudinal acceleration $> \text{TKOFF\_THR\_MINACC}$.
2.  **Delay:** Wait for $T_{delay} = \text{TKOFF\_THR\_DELAY} \times 0.1$ seconds.
3.  **Speed:** GPS Ground Speed $> \text{TKOFF\_THR\_MINSPD}$.

The throttle remains at 0% until:
$$ (V_{gps} > \text{TKOFF\_THR\_MINSPD}) \lor (\text{TKOFF\_THR\_MINSPD} = 0) $$

## The Engineer's View
Defined in `ArduPlane/takeoff.cpp` inside `auto_takeoff_check()`.

The logic is designed to be robust against GPS noise. The ground speed check only arms *after* the acceleration check passes. This prevents a "GPS Jump" (where the coordinates jump 10 meters while sitting still) from accidentally starting the motor.

```cpp
// ArduPlane/takeoff.cpp
if (((gps.ground_speed() > g.takeoff_throttle_min_speed || is_zero(g.takeoff_throttle_min_speed))) &&
    ((now - takeoff_state.last_tkoff_arm_time) >= wait_time_ms)) {
    // Motor unsuppressed
}
```

## Tuning & Behavior
*   **Default Value:** 0
*   **Effect of Increasing:** Safer launches. The motor will start later in the throw/launch.
*   **Effect of Decreasing:** Faster motor response. The motor starts sooner.
*   **Crucial Note:** GPS speed usually lags real speed by about **0.5 seconds**. Account for this lag when setting the speed threshold.

### Use Case Recommendations
*   **Bungee Launch:** Set to **0** and rely on `TKOFF_THR_DELAY` (e.g., 3.0s) to let the bungee fall away before the prop starts.
*   **Hand Launch (Pusher):** Set to **4.0 m/s**. This ensures the plane is already out of your hand before the blades spin up.
*   **Rolling Takeoff (Runway):** Set to **0**. You want the motor to start immediately to begin the roll.