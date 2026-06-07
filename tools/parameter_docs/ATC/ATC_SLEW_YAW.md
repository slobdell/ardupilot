---
layout: parameter
name: ATC_SLEW_YAW
display_name: Yaw Target Slew Rate
description: Limits how quickly the yaw target (heading) can change in RTL and Auto flight modes. Prevents the drone from snapping its tail too aggressively during autonomous missions.
default_value: 6000
range: 500 18000
units: cdeg/s
group: ATC
visual_asset_id: atc_slew_yaw_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L25
---

# Yaw Target Slew Rate (ATC_SLEW_YAW)

## Description
`ATC_SLEW_YAW` is the "comfort setting" for your drone's tail during autonomous flight. While other parameters control how fast the drone *can* spin, this parameter controls how fast the software *wants* to change the goal heading.

When a drone reaches a waypoint and needs to turn 90 degrees to head to the next one, the software calculates a new heading target. Without a slew limit, the target would "jump" instantly, causing the drone to whip its tail around violently. `ATC_SLEW_YAW` forces that change to be gradual, making the drone turn smoothly and predictably.

*   **Low Value (e.g. 1000):** The drone turns very slowly and elegantly during missions.
*   **High Value (e.g. 10000):** The drone snaps to its new heading as fast as possible.
*   **Default (6000):** 60 degrees per second. A standard, safe value for general flight.

## The Mathematics
This parameter acts as a rate limiter for the heading setpoint ($\psi_{target}$):

$$ \left| \frac{\psi_{target}(t) - \psi_{target}(t-dt)}{dt} \right| \leq \text{SLEW\_YAW} $$

Where:
*   $\text{SLEW\_YAW}$ is in centidegrees per second (e.g., 6000 = 60 deg/s).

**Note:** This is an *input* slew limit. It is independent of the *output* limits like `ATC_RATE_Y_MAX`. Even if the drone is physically capable of spinning at 200 deg/s, this parameter will force it to follow a 60 deg/s "ramp" during autonomous moves.

## The Engineer's View
This parameter is the `_slew_yaw` member in `AC_AttitudeControl`.

It is applied in `AC_AttitudeControl::get_slew_yaw_max_degs()`:

```cpp
// AC_AttitudeControl.cpp
float AC_AttitudeControl::get_slew_yaw_max_degs() const
{
    if (!is_positive(_ang_vel_yaw_max)) {
        return _slew_yaw * 0.01;
    }
    return MIN(_ang_vel_yaw_max, _slew_yaw * 0.01);
}
```

By capping the "Slew" at the same value as the "Max Rate," ArduPilot ensures that the path planner never requests a turn that the physical motors can't track, resulting in zero-overshoot turns during Auto missions.

## Tuning & Behavior
*   **Default Value:** 6000 cdeg/s (60 deg/s)
*   **Range:** 500 - 18,000
*   **Effect of Increasing:** Faster waypoint-to-waypoint transitions. Better for high-speed missions where every second counts.
*   **Effect of Decreasing:** Much smoother video during auto-missions. Reduces the "jerky tail" look of autonomous flight.

### Use Case Recommendations
*   **Cinematography (Auto-Paths):** **Decrease to 1500 - 3000.** Ensures the tail move is so slow that it looks like a professional motion-control rig.
*   **Industrial Survey / Mapping:** **Keep Default (6000).** Standard turns are efficient and keep the camera stabilized.
*   **Package Delivery:** **Increase to 10000.** You want the drone to spend as little time as possible turning, to maximize forward flight time and battery life.

### Troubleshooting
*   **Scenario:** During an Auto mission, the drone starts its forward flight to the next waypoint before it has finished turning its nose, resulting in a "banana-shaped" flight path.
    *   **Diagnosis:** `ATC_SLEW_YAW` is too low for the drone's mission speed.
    *   **Fix:** Increase `ATC_SLEW_YAW` to 8000.