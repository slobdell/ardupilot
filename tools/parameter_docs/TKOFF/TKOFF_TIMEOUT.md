---
layout: parameter
name: TKOFF_TIMEOUT
display_name: Takeoff Safety Timeout
description: The maximum time (in seconds) allowed for the aircraft to reach flying speed during takeoff.
default_value: 0
range: 0 120
units: s
group: TKOFF
visual_asset_id: takeoff_failure_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1262
---

# Takeoff Safety Timeout (TKOFF_TIMEOUT)

## Description
`TKOFF_TIMEOUT` is a vital "Dead-Man's Switch" for automatic launches. It monitors your aircraft's progress and aborts the mission if the plane isn't speeding up as expected.

If you launch your plane but the motor fails, or if a wheel is stuck in a rut on the runway, the drone might continue to sit there with the throttle active, or it might stumble into the grass. `TKOFF_TIMEOUT` ensures that if the plane doesn't reach at least 4 m/s (roughly 9 mph) within this time limit, the autopilot kills the motor and disarms the drone.

*   **0 (Default):** Timeout is disabled. The drone will keep trying to take off until the battery dies or it is manually disarmed.
*   **Recommendation:** Set to **5 or 10 seconds**.

## The Engineer's View
Defined in `ArduPlane/takeoff.cpp`. 
The timer starts the moment the "Triggered AUTO" message appears (after the acceleration and delay checks pass). The logic checks the GPS ground speed against a fixed internal threshold (4.0 m/s).

```cpp
// ArduPlane/takeoff.cpp
if (g2.takeoff_timeout > 0 &&
    !takeoff_state.launchTimerStarted &&
    now - takeoff_state.start_time_ms > (uint32_t)g2.takeoff_timeout*1000U &&
    gps.ground_speed() < 4.0f) {
    gcs().send_text(MAV_SEVERITY_CRITICAL, "Takeoff timeout");
    disarm_motors();
}
```

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Effect of Setting:** Provides a crucial safety backup for autonomous operations.
*   **Usage Tip:** If you have a very large, slow-accelerating plane, ensure your timeout is long enough to account for the slow build-up of speed.

### Troubleshooting
*   **Scenario:** My drone disarms immediately after a hand-launch!
    *   **Diagnosis:** `TKOFF_TIMEOUT` is set too low, or your `TKOFF_THR_DELAY` is so long that the timeout expires before the motor even starts.
    *   **Fix:** Increase `TKOFF_TIMEOUT` to 10.