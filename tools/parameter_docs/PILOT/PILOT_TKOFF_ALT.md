---
layout: parameter
name: PILOT_TKOFF_ALT
display_name: Pilot Takeoff Altitude
description: The target altitude (in centimeters) the drone will automatically climb to when a pilot-initiated takeoff is triggered.
default_value: 0
range: 0 1000
units: cm
group: PILOT
visual_asset_id: pilot_takeoff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/mode_loiter.cpp#L100
---

# Pilot Takeoff Altitude (PILOT_TKOFF_ALT)

## Description
`PILOT_TKOFF_ALT` enables the "Automatic Launch" feature for manual flight modes. 

Normally, in modes like **Loiter** or **AltHold**, you have to manually push the throttle stick up to lift the drone off the ground. With this parameter, you can simply arm the drone and push the throttle stick slightly above the center (or use a GCS button). The drone will then automatically climb to this specific height and wait for your next command.

*   **Units:** Centimeters.
*   **0 (Default):** Feature is disabled. Standard manual throttle control for takeoff.
*   **200:** The drone will automatically climb to 2 meters (6.5 ft) above the ground.

## The Engineer's View
Defined in `ArduCopter/Parameters.cpp`. 
When the drone is armed and landed in a semi-autonomous mode (Loiter, AltHold, PosHold, FlowHold), the position controller monitors the throttle stick. If the stick is moved above the `THR_DZ` (Deadzone) and `PILOT_TKOFF_ALT` is non-zero, the `takeoff.start()` function is called.

```cpp
// ArduCopter/mode_loiter.cpp
if (ap.land_complete && throttle_stick > center_stick) {
    takeoff.start(constrain_float(g.pilot_takeoff_alt, 0.0f, 1000.0f));
}
```

The drone then executes a kinematically shaped vertical path to the target altitude, using the `PSC_JERK_Z` and `PSC_ACCEL_Z` limits.

## Tuning & Behavior
*   **Default Value:** 0 (Manual Takeoff).
*   **Recommendation:** Set to **200 (2 meters)**. This is a safe "Head Height" that ensures the drone is clear of ground-effect turbulence and obstacles before the pilot takes over full manual control.
*   **Safety:** Always ensure the area above the drone is clear. If you trigger an automatic takeoff indoors, the drone will hit the ceiling if `PILOT_TKOFF_ALT` is set too high!

### Troubleshooting
*   **Scenario:** My drone "jumps" into the air as soon as I move the throttle stick just a little bit.
    *   **Diagnosis:** `PILOT_TKOFF_ALT` is set to a non-zero value, and you are triggering the auto-launch.
    *   **Fix:** Set to **0** if you prefer manual throttle control during takeoff.