---
layout: parameter
name: TKOFF_THR_MINACC
display_name: Takeoff Throttle Min Acceleration
description: Minimum forward acceleration required to trigger the automatic takeoff sequence.
default_value: 0
range: 0 30
units: m/s/s
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/takeoff.cpp#L78
---

# Takeoff Throttle Min Acceleration (TKOFF_THR_MINACC)

## Description
`TKOFF_THR_MINACC` is the "Starting Gun" for an automatic plane launch. It detects the physical throw of your hand or the pull of a bungee cord to tell the autopilot: "The mission has begun."

Without this parameter, the drone might try to start its motor the moment you switch to AUTO mode. With it, the drone sits silently until it feels a sharp forward jolt.

*   **0 (Default):** Acceleration check is disabled. The takeoff sequence starts immediately upon entering AUTO mode.
*   **15.0 m/s²:** Recommended for hand-launches. This requires a firm, confident throw to trigger.

## The Mathematics
The autopilot uses the forward-axis accelerometer (X-axis) and removes the effects of gravity and tilt. It looks for a peak value:

$$ \text{Forward Acceleration} > \text{TKOFF\_THR\_MINACC} $$

Once this threshold is crossed, the takeoff timer starts. For even greater safety, you can require multiple "jolts" using the `TKOFF_ACCEL_CNT` parameter.

## The Engineer's View
The value is sourced from the `TECS_controller.get_VXdot()` method, which provides a highly filtered and compensated acceleration estimate.

```cpp
// ArduPlane/takeoff.cpp
float xaccel = TECS_controller.get_VXdot();
if (xaccel < g.takeoff_throttle_min_accel) {
    goto no_launch;
}
```

This prevents the takeoff from being triggered by wind gusts or simple tilting of the aircraft, as only true longitudinal acceleration is considered.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** 0 to 30 m/s/s (0 to ~3G).
*   **Effect of Increasing:** Requires a harder throw. Safer against accidental triggers while walking with the drone.
*   **Effect of Decreasing:** Easier to trigger. Good for weak throwers or lightweight planes.

### Troubleshooting
*   **Scenario:** I threw the plane but the motor never started!
    *   **Diagnosis:** Your throw was too weak, or `TKOFF_THR_MINACC` is set too high.
    *   **Fix:** Check your logs for `TECS.VXdot`. Reduce the parameter to match 70% of your typical throw peak.
*   **Scenario:** The motor started while I was just walking to the launch site!
    *   **Diagnosis:** `TKOFF_THR_MINACC` is too low or 0.
    *   **Fix:** Set to at least **10.0** to require a deliberate motion.

```