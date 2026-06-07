---
layout: parameter
name: PSC_VELXY_FF
display_name: Position Control Velocity (XY) Feed-Forward
description: Feed-forward gain for the horizontal velocity loop. Directly converts desired velocity into a target lean angle, bypassing the error-correction step for instant response.
default_value: 0.0
range: 0 6.0
units: 
group: PSC
visual_asset_id: psc_velxy_ff_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L1066
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID_2D.cpp#L35
---

# Position Control Velocity (XY) Feed-Forward (PSC_VELXY_FF)

## Description
`PSC_VELXY_FF` is the "predictive throttle" for horizontal movement. While the P, I, and D terms react to **mistakes** (e.g., "I'm not flying as fast as I should be"), the Feed-Forward (FF) term reacts to the **goal** (e.g., "The pilot wants to fly at 5 m/s, so I need to lean by 10 degrees now").

By bypassing the error-correction loop, the FF term eliminates the "lag" associated with PID controllers. It allows the drone to start leaning the moment the stick is moved, rather than waiting for a velocity error to build up. This is the difference between a drone that "oozes" into movement and one that "snaps" into movement.

*   **Low Value (0.0):** Standard behavior. The drone relies on error-correction. There will be a slight delay between stick movement and the drone reaching target speed.
*   **High Value:** The drone leans instantly and aggressively.
*   **Too High:** The drone will "over-lean" when you first move the stick, causing it to shoot past the target speed and then jerk back.

## The Mathematics
The Feed-Forward term is a direct multiplier of the desired velocity:

$$ \vec{A}_{target\_FF} = \vec{V}_{desired} \cdot k_{FF} $$

Where:
*   $\vec{V}_{desired}$ is the speed requested by the pilot or the Position loop.
*   $k_{FF}$ is `PSC_VELXY_FF`.

The output is an acceleration ($\text{cm/s}^2$), which is directly converted into a target Roll and Pitch angle.

## The Engineer's View
This parameter maps to `_kff` in the `_pid_vel_xy` object.

It is applied in `AC_PID_2D::update_all()`:

```cpp
// AC_PID_2D.cpp
_pid_info_x.FF = _target.x * _kff;
_pid_info_y.FF = _target.y * _kff;
return ... + _target * _kff;
```

In modern ArduPilot versions, this is often set to **0.0** by default because the kinematic shaper and high P-gains handle most use cases. However, for specialized flight profiles like high-speed object tracking, it is an essential tuning tool.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0.0 - 6.0
*   **Effect of Increasing:** Snappier starts and stops. Better "lead" in autonomous missions.
*   **Effect of Decreasing:** Smoother, more organic-feeling movement.

### Use Case Recommendations
*   **Racing / FPV Chase:** **Increase to 0.5 - 1.0.** Allows the drone to mimic the pilot's inputs with zero perceived lag, which is critical when chasing a moving subject.
*   **Standard GPS Photography:** **Keep at 0.0.** You want the drone to be smooth and predictable; any "jumpiness" from high FF gains will ruin shots.
*   **Precision Docking:** **Increase to 0.2.** Helps the drone make tiny, instantaneous adjustments when closing the final few centimeters to a target.

### Troubleshooting
*   **Scenario:** When you push the stick forward, the drone "nods" its nose down too far, then lifts it back up slightly as it reaches speed.
    *   **Diagnosis:** `PSC_VELXY_FF` is too high (Initial overshoot).
    *   **Fix:** Reduce `PSC_VELXY_FF` or set to 0.0.

