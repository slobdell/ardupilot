---
layout: parameter
name: TKOFF_ACCEL_CNT
display_name: Takeoff Throttle Acceleration Count
description: Number of forward/backward acceleration events required to trigger the motor start.
default_value: 1
range: 1 10
units: 
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1254
---

# Takeoff Throttle Acceleration Count (TKOFF_ACCEL_CNT)

## Description
`TKOFF_ACCEL_CNT` is the "Confirmation Code" for your launch trigger. It enables a feature often called **"Shake-to-Arm."**

Instead of a single throw triggering the motor, you can require multiple forward and backward jolts. This is extremely useful for preventing accidental motor starts caused by bumping the drone or walking with it in windy conditions.

*   **1 (Default):** A single forward throw triggers the motor.
*   **2+:** Requires multiple deliberate forward/backward shakes to start the motor.

## The Engineer's View
Defined in `ArduPlane/takeoff.cpp`. 
The code maintains a counter of "acceleration events." An event is recorded every time the X-axis acceleration exceeds `TKOFF_THR_MINACC`. To prevent false counts from vibration, events must alternate direction (Forward/Backward) or happen within a specific time window.

```cpp
// ArduPlane/takeoff.cpp
if (g2.takeoff_throttle_accel_count <= 1) {
    if (xaccel < g.takeoff_throttle_min_accel) {
        goto no_launch;
    }
} else {
    // Advanced shake detection logic
    bool odd_event = ((takeoff_state.accel_event_counter & 1) != 0);
    // ...
}
```

## Tuning & Behavior
*   **Default Value:** 1.
*   **Recommendation:** Set to **2 or 3** if you are launching in high-vibration environments or from a moving vehicle.
*   **Usage:** If set to **2**, you must give the plane a firm forward "pump" or shake before the final throw to arm the throttle.