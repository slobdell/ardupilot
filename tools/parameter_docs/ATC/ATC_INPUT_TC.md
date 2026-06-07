---
layout: parameter
name: ATC_INPUT_TC
display_name: Attitude Control Input Time Constant
description: Controls the responsiveness and smoothness of pilot stick inputs. Acts as a "low-pass filter" on the requested attitude targets.
default_value: 0.15
range: 0 1.0
units: s
group: ATC
visual_asset_id: atc_input_tc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L94
---

# Attitude Control Input Time Constant (ATC_INPUT_TC)

## Description
`ATC_INPUT_TC` is the "smoothness filter" for the pilot's fingers. It determines how fast the flight controller attempts to reach the attitude requested by your sticks.

Even if you move your stick instantly from 0 to 100%, the drone won't instantly command 100%. `ATC_INPUT_TC` defines the time it takes for the software target to catch up to your actual stick position. It removes the "jerkiness" from manual flight, making the drone feel like it has weight and momentum.

*   **Low Value (e.g., 0.05):** The drone feels very "twitchy" and responsive. It reacts to every tiny movement of your hand. 
*   **High Value (e.g., 0.5):** The drone feels very "soft" or "delayed." It will take a long time to start and stop its movements.
*   **Default (0.15):** A "Medium" setting that feels natural for most multirotor pilots.

## The Mathematics
This parameter acts as the time constant ($\tau$) for a first-order low-pass filter on the requested target:

$$ \theta_{target}(t) = \theta_{target}(t-dt) + \frac{dt}{\tau + dt} \cdot (\theta_{pilot} - \theta_{target}(t-dt)) $$

Where:
*   $\theta_{pilot}$ is the raw angle requested by your stick position.
*   $\theta_{target}$ is the smoothed value sent to the flight control loops.
*   $\tau$ is `ATC_INPUT_TC`.

**Physical Meaning:** A time constant of 0.15s means that if you hold the stick at a fixed position, the drone will reach 63% of that target angle in 150 milliseconds.

## The Engineer's View
This parameter is the `_input_tc` member in `AC_AttitudeControl`.

It is used in the **Input Shaper** for all manual modes (Loiter, AltHold, Stabilize):

```cpp
// AC_AttitudeControl.cpp
_euler_rate_target.x = input_shaping_angle(wrap_PI(euler_roll_angle - _euler_angle_target.x), _input_tc, euler_accel.x, _euler_rate_target.x, _dt);
```

By filtering the *input* rather than the output, ArduPilot ensures that the PID loops are always following a perfectly smooth, continuous path, which significantly reduces motor noise and frame stress compared to raw stick commands.

## Tuning & Behavior
*   **Default Value:** 0.15s
*   **Range:** 0.0 - 1.0s
*   **Effect of Increasing:** Smoother, more professional cinematic look. Reduces battery sag during aggressive stick movements.
*   **Effect of Decreasing:** Tighter stick feel. Essential for racing or flying in tight spaces where you need immediate reaction.

### Use Case Recommendations
*   **Racing / FPV Freestyle:** **Decrease to 0.05 - 0.10.** You want the drone to follow your brain with zero delay.
*   **Cinematography:** **Increase to 0.20 - 0.50.** This makes the drone feel "heavy," like a full-sized helicopter. It prevents small finger shakes from showing up on the camera.
*   **Beginner Pilots:** **Set to 0.20.** Makes the drone easier to control by slowing down its reactions to "panic" stick movements.

### Troubleshooting
*   **Scenario:** The drone feels "delayed" or "disconnected." I move the stick, but I have to wait for the drone to react.
    *   **Diagnosis:** `ATC_INPUT_TC` is set too high.
    *   **Fix:** Reduce `ATC_INPUT_TC` to 0.10.