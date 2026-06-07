---
layout: parameter
name: TKOFF_TDRAG_ELEV
display_name: Takeoff Tail-Dragger Elevator
description: The percentage of elevator to apply during the initial stage of a rolling takeoff to hold the tail (or nose) wheel on the ground for steering.
default_value: 0
range: -100 100
units: %
group: TKOFF
visual_asset_id: rolling_takeoff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1254
---

# Takeoff Tail-Dragger Elevator (TKOFF_TDRAG_ELEV)

## Description
`TKOFF_TDRAG_ELEV` is an essential setting for planes with a **Tail Wheel**. 

When a tail-dragger begins its takeoff run, the tail wheel provides the steering. However, as the motor pulls the plane forward, the tail naturally wants to lift into the air. If it lifts too soon, you lose steering control before the rudder becomes effective, causing the plane to "ground loop" (spin out). 

This parameter forces the elevator to pull the tail down, keeping the steering wheel firmly on the ground until the plane has enough speed to steer with the rudder.

*   **100 (Full Up):** Recommended for tail-draggers. Holds the tail wheel down.
*   **0 (Neutral):** Standard for hand-launches.
*   **-20 to -30 (Down):** Used for some tricycle-gear planes to hold the nose wheel down for better grip.

## The Engineer's View
This parameter provides a direct override to the elevator channel during the "Ground Run" phase of takeoff. It is active from the start of the roll until the speed reaches `TKOFF_TDRAG_SPD1`.

```cpp
// ArduPlane/takeoff.cpp
// Apply g.takeoff_tdrag_elevator to elevator output during initial roll.
```

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation for Tail-draggers:** Set to **100**. As the plane reaches `TKOFF_TDRAG_SPD1`, the elevator will return to neutral, allowing the tail to rise into a level flight attitude.
*   **Recommendation for Tricycle (Nose wheel):** Set to **-20** if your nose wheel tends to skitter or lose traction during high-power takeoffs.

### Troubleshooting
*   **Scenario:** My tail-dragger always veers sharply to the left as soon as I start the takeoff roll.
    *   **Diagnosis:** The tail is lifting too early, and you are losing steering.
    *   **Fix:** Ensure `TKOFF_TDRAG_ELEV` is 100 and `TKOFF_TDRAG_SPD1` is set to about 70% of your stall speed.
