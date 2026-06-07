---
layout: parameter
name: ATC_RAT_PIT_D_FF
display_name: Pitch Axis Rate Derivative Feed-Forward
description: Derivative feed-forward gain for the pitch rate loop. Provides pre-emptive motor correction based on how quickly the pitch command is changing.
default_value: 0.0
range: 0 0.02
units: 
group: ATC
visual_asset_id: atc_rat_pit_d_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L81
---

# Pitch Axis Rate Derivative Feed-Forward (ATC_RAT_PIT_D_FF)

## Description
`ATC_RAT_PIT_D_FF` is an advanced predictive control term for your drone's forward and backward rotation. While standard Feed-Forward (`ATC_RAT_PIT_FF`) looks at your desired pitch speed, the **Derivative Feed-Forward (D_FF)** looks at how fast you are *moving the stick*.

If you suddenly slam the pitch stick forward to dodge an obstacle, the D_FF term instantly commands a surge of power to the rear motors to tilt the nose down. It provides the "kick" needed to overcome the longitudinal inertia of the drone's frame and battery. This results in a drone that follows your commands with zero perceived lag.

*   **Low Value (0.0):** Standard behavior. The drone relies on error-correction and base feed-forward.
*   **High Value:** Creates a sharp "snap" at the beginning of pitch moves.
*   **Too High:** Can cause "kickback" or jerky, non-linear movements in the pitch axis.

## The Mathematics
The D_FF term is proportional to the rate of change of the pitch setpoint ($\\omega_{pit\_target}$):

$$ \text{Out}_{D\_FF} = \frac{d(\\omega_{pit\_target})}{dt} \cdot k_{D\_FF} $$

Where:
*   $k_{D\_FF}$ is `ATC_RAT_PIT_D_FF`.
*   $\\frac{d(\\omega_{pit\_target})}{dt}$ is the rate of change of the requested pitch speed.

**Vibration Immunity:** Because this term is derived from the **Setpoint** (pilot stick) rather than the **Gyro** (sensor), it does not amplify motor vibration. You can use D_FF to get a "stiff" response without the risk of motor heating associated with standard D-gains.

## The Engineer's View
This parameter maps to `_kdff` in the `_pid_rate_pitch` object.

It is executed in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (is_positive(dt)) {
    float target_derivative = (target - _last_target) / dt;
    _pid_info.D_FF = target_derivative * _kdff;
}
```

In ArduPilot, D_FF is especially useful for "Dead Cat" or long-range frames where the Pitch axis has significantly more mass to move than the Roll axis. It helps "lead" the heavier longitudinal axis into maneuvers.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0.0 - 0.02
*   **Effect of Increasing:** Snappier longitudinal transitions. Reduced altitude loss during aggressive pitch maneuvers.
*   **Effect of Decreasing:** Smoother, more organic pitch behavior.

### Use Case Recommendations
*   **Speed Runs / Drag Racing:** **Increase to 0.01.** Essential for performing the instant, aggressive tilts needed to maximize acceleration from a hover.
*   **Cinematography:** **Keep at 0.0.** High D_FF gains can make the horizon "snap" in a way that looks artificial on video.
*   **Standard Multirotor:** **Keep at 0.0.** Standard tuning is safer and easier to manage for most pilots.

### Troubleshooting
*   **Scenario:** Drone nose "bobs" or twitches whenever I move the stick, even slightly.
    *   **Diagnosis:** `ATC_RAT_PIT_D_FF` is likely too high, reacting to tiny finger twitches.
    *   **Fix:** Reduce `ATC_RAT_PIT_D_FF` to 0.002 or set back to 0.