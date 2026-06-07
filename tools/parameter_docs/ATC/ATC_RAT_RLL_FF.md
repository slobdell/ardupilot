---
layout: parameter
name: ATC_RAT_RLL_FF
display_name: Roll Axis Rate Feed-Forward Gain
description: Directly maps the desired roll rate to a motor output, bypassing the error-correction logic for instant response.
default_value: 0.0
range: 0.0 0.5
units: 
group: ATC
visual_asset_id: atc_rat_rll_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L30
---

# Roll Axis Rate Feed-Forward Gain (ATC_RAT_RLL_FF)

## Description
`ATC_RAT_RLL_FF` is the "direct drive" of the flight controller. While the P, I, and D terms in the PID loop wait for the drone to make a mistake before they act, the Feed-Forward (FF) term acts the moment you move the stick.

If you command a 180 deg/s roll, the FF term instantly calculates a baseline motor power to start that rotation *before* the gyro even feels the movement. This removes the "mushy" feel found in many flight controllers and allows for a perfectly linear relationship between your stick position and the drone's rotation speed.

*   **Low Value (0.0):** The drone relies entirely on error-correction. There will be a slight, perceived lag as the PID loop builds up authority to start the rotation.
*   **High Value:** The drone feels "telepathic." It starts and stops rotating exactly when you move the sticks.
*   **Too High:** The drone will "snap" too hard, potentially overshooting its target rate before the PID loop can catch it.

## The Mathematics
The FF term is a simple multiplier of the target rotation rate:

$$ \text{Out}_{FF} = \omega_{target} \cdot k_{FF} $$

Where:
*   $\omega_{target}$ is the desired roll rate (from the pilot or outer loop).
*   $k_{FF}$ is `ATC_RAT_RLL_FF`.

The total output sent to the motor mixer is the sum of PID and FF:
$$ \text{Out}_{total} = \text{Out}_{P} + \text{Out}_{I} + \text{Out}_{D} + \text{Out}_{FF} $$

## The Engineer's View
This parameter is the `_kff` member of the `_pid_rate_roll` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_pid_info.FF = target * _kff;
// ...
return P + I + D + _pid_info.FF;
```

In the ArduPilot architecture, Feed-Forward is often the preferred way to get responsiveness on large frames because it does not create the high-frequency vibration risks associated with aggressive P and D gains.

## Tuning & Behavior
*   **Default Value:** 0.0 (Traditional Multirotor)
*   **Range:** 0.0 - 0.5
*   **Effect of Increasing:** Snappier, more immediate rotations. Better adherence to rapid 3D maneuvers.
*   **Effect of Decreasing:** Smoother, softer handling.

### Use Case Recommendations
*   **FPV Racing / Freestyle:** **Increase to 0.15 - 0.25.** Essential for the "instant" feel needed to navigate tight gates or perform technical acro.
*   **Heavy Lift / Commercial:** **Keep at 0.0.** Large drones are too heavy for instant rotation; the error-correction loops are safer for managing their massive inertia.
*   **Cinematography:** **Set to 0.05.** A tiny amount of FF can help the drone start moving with less "slop" without making it feel jumpy.

### Troubleshooting
*   **Scenario:** When you start a roll, the drone "kicks" violently, but the rest of the rotation is smooth.
    *   **Diagnosis:** `ATC_RAT_RLL_FF` is too high.
    *   **Fix:** Reduce `ATC_RAT_RLL_FF` by 0.05.