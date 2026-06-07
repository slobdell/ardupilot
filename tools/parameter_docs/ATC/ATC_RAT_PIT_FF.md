---
layout: parameter
name: ATC_RAT_PIT_FF
display_name: Pitch Axis Rate Feed-Forward Gain
description: Directly maps the desired pitch rate to a motor output, bypassing the error-correction logic for instant response to forward/backward stick commands.
default_value: 0.0
range: 0.0 0.5
units: 
group: ATC
visual_asset_id: atc_rat_pit_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L30
---

# Pitch Axis Rate Feed-Forward Gain (ATC_RAT_PIT_FF)

## Description
`ATC_RAT_PIT_FF` is the "accelerator pedal" for your drone's pitch axis. While the P, I, and D terms wait for the drone to *miss* its target rotation speed before they correct it, the Feed-Forward (FF) term acts pre-emptively.

When you push the stick forward, the FF term instantly calculates how much power to send to the rear motors to tilt the drone forward *at the same moment* your finger moves. This eliminates the "mushy" or "laggy" feeling often associated with flight controllers and makes the drone feel like it is mechanically locked to your hands.

*   **Low Value (0.0):** The drone relies entirely on error-correction. There will be a slight delay as the drone "spools up" its rotation authority.
*   **High Value:** The drone feels extremely responsive. It starts and stops rotating the exact millisecond you move the sticks.
*   **Too High:** The drone will "over-snap" when you start a movement, potentially causing the nose to dip or rise too far before leveling out at the correct speed.

## The Mathematics
The FF term is a simple multiplier of the target rotation rate:

$$ \text{Out}_{FF} = \omega_{target} \cdot k_{FF} $$

Where:
*   $\omega_{target}$ is the desired pitch rate (deg/s).
*   $k_{FF}$ is `ATC_RAT_PIT_FF`.

The total output is the sum of PID and FF contributions.

## The Engineer's View
This parameter is the `_kff` member of the `_pid_rate_pitch` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_pid_info.FF = target * _kff;
// ...
return P + I + D + _pid_info.FF;
```

Feed-Forward is particularly important in autonomous flight (Auto missions) because it allows the drone to follow its planned path with much higher precision, as the controller doesn't need a large "error" to generate high motor power.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard Multirotor)
*   **Range:** 0.0 - 0.5
*   **Effect of Increasing:** Snappier, more immediate pitch response. Better for high-speed tracking and sharp turns.
*   **Effect of Decreasing:** Smoother, softer pitch behavior.

### Use Case Recommendations
*   **Cinematography:** **Set to 0.05.** Just enough to remove the initial "laziness" of the drone without making the footage look robotic or twitchy.
*   **FPV Racing:** **Increase to 0.2 - 0.3.** Essential for clearing gates and hitting gaps at high speed where any control lag is fatal.
*   **Large Professional Drones:** **Keep at 0.0.** Heavy vehicles should be moved with deliberate, error-checked power to avoid over-stressing the airframe.

### Troubleshooting
*   **Scenario:** When you push the stick forward, the drone "jumps" forward too hard for a split second, then settles.
    *   **Diagnosis:** `ATC_RAT_PIT_FF` is too high.
    *   **Fix:** Reduce `ATC_RAT_PIT_FF` by 0.05.