---
layout: parameter
name: ATC_RAT_YAW_FF
display_name: Yaw Axis Rate Feed-Forward Gain
description: Directly maps the desired yaw rate to a motor output, bypassing the error-correction logic for instant response to heading changes.
default_value: 0.0
range: 0.0 0.5
units: 
group: ATC
visual_asset_id: atc_rat_yaw_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L30
---

# Yaw Axis Rate Feed-Forward Gain (ATC_RAT_YAW_FF)

## Description
`ATC_RAT_YAW_FF` is the "accelerator pedal" for the tail of your drone. While the P, I, and D terms wait for the drone to *fail* to reach a target rotation speed before they act, the Feed-Forward (FF) term acts pre-emptively.

When you push the yaw stick left or right, the FF term instantly calculates how much motor torque to add *at that exact moment* to start the turn. This removes the "elastic" or "mushy" feeling often found in the tail control of large drones, allowing for a perfectly linear relationship between your finger position and the drone's rotation rate.

*   **Low Value (0.0):** The drone relies entirely on error-correction. There will be a slight delay as the tail "spools up" into the turn.
*   **High Value:** The drone feels extremely sharp. It starts and stops spinning the exact millisecond you move the stick.
*   **Too High:** The drone will "over-spin" when you first move the stick, potentially causing a jerky, high-frequency "snap" that stresses the frame.

## The Mathematics
The FF term is a simple multiplier of the target rotation rate:

$$ \text{Out}_{FF} = \omega_{target} \cdot k_{FF} $$

Where:
*   $\omega_{target}$ is the desired yaw rate (deg/s).
*   $k_{FF}$ is `ATC_RAT_YAW_FF`.

The total output is the sum of PID and FF contributions.

## The Engineer's View
This parameter is the `_kff` member of the `_pid_rate_yaw` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
_pid_info.FF = target * _kff;
// ...
return P + I + D + _pid_info.FF;
```

In the ArduPilot architecture, Yaw Feed-Forward is often crucial for **Octocopters** and other multi-rotor platforms where the torque reaction force is very small compared to the mass of the arms. It provides the "kick" needed to overcome the airframe's rotational inertia.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0.0 - 0.5
*   **Effect of Increasing:** Snappier heading changes. Tighter tracking during autonomous flight.
*   **Effect of Decreasing:** Smoother, more flowing yaw turns.

### Use Case Recommendations
*   **Cinematography (Pan Shots):** **Keep at 0.0.** You want the tail to drift smoothly into its turn to avoid "robotic" camera movement.
*   **Tricopters (Servo Yaw):** **Set to 0.1 - 0.2.** Servos react instantly; adding FF allows the software to take full advantage of that mechanical speed.
*   **FPV Freestyle / Racing:** **Increase to 0.2.** Essential for sharp "Yaw Spins" and clearing tight racing corners without any control lag.

### Troubleshooting
*   **Scenario:** When you start a yaw turn, the tail "snaps" or makes a loud motor sound for a fraction of a second before continuing smoothly.
    *   **Diagnosis:** `ATC_RAT_YAW_FF` is too high.
    *   **Fix:** Reduce `ATC_RAT_YAW_FF` by 0.05.