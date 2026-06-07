---
layout: parameter
name: TKOFF_THR_SLEW
display_name: Takeoff Throttle Slew Rate
description: The maximum rate of change (percentage per second) for the motor throttle during an automatic takeoff.
default_value: 0
range: -1 100
units: %/s
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1254
---

# Takeoff Throttle Slew Rate (TKOFF_THR_SLEW)

## Description
`TKOFF_THR_SLEW` prevents your motor from jumping from 0% to 100% instantly. It forces a smooth, gradual "ramp up" of power.

This is critical for **Runway Takeoffs** where a sudden burst of power could cause the plane to veer sideways or "torque roll" before the wings are generating lift. It is also easier on your battery and ESC, as it avoids massive instantaneous current spikes.

*   **0 (Default):** Use the global `THR_SLEWRATE` value (typically 100%/s).
*   **-1:** No limit. The throttle jumps instantly. (Dangerous for large props!).
*   **20:** Ramps the throttle from 0 to 100 over **5 seconds**.

## The Engineer's View
This parameter provides a dedicated slew rate limit specifically for the `AUTO` and `TAKEOFF` flight stages. It helps stabilize the initial ground run where aerodynamic surfaces like the rudder are not yet effective.

```cpp
// ArduPlane/takeoff.cpp
// Limits the rate of change of the internal _throttle_output variable.
```

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation for Runway:** Set to **20 or 30**. This provides a scale-like, controllable acceleration.
*   **Recommendation for Hand-Launch:** Keep at **0 or set to 100**. You want the power as fast as possible once the plane has left your hand.

### Troubleshooting
*   **Scenario:** My plane always spins out on the runway as soon as the motor starts.
    *   **Diagnosis:** The sudden torque of the propeller is overcoming the steering traction.
    *   **Fix:** Reduce `TKOFF_THR_SLEW` to 20.