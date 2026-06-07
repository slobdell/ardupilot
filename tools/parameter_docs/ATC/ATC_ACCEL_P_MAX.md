---
layout: parameter
name: ATC_ACCEL_P_MAX
display_name: Pitch Acceleration Max
description: Maximum angular acceleration allowed in the pitch axis. Limits how quickly the drone can change its forward/backward rotation speed.
default_value: 0.0
range: 0 180000
units: cdeg/s/s
group: ATC
visual_asset_id: atc_accel_p_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L70
---

# Pitch Acceleration Max (ATC_ACCEL_P_MAX)

## Description
`ATC_ACCEL_P_MAX` defines the maximum "torque authority" allowed around the pitch axis (tilting forward or backward). It limits the intensity of the drone's longitudinal rotation changes.

Think of it as the drone's "pitch throttle." If you command a sudden dive, `ATC_ACCEL_P_MAX` ensures the drone doesn't flip into that dive so violently that it stalls its props or causes a brown-out. It provides the "softness" or "sharpness" of the start and stop of a pitch maneuver.

*   **Low Value:** Pitch changes are smooth and gradual. The drone will tilt forward or backward like a heavy ship.
*   **High Value:** Pitch changes are sharp and aggressive. The drone snaps into forward flight instantly.
*   **Disabled (0):** No limit is applied; the drone will rotate as fast as the motors can physically push the frame.

## The Mathematics
This parameter limits the rate of change of the pitch angular velocity ($\omega_{pitch}$):

$$ \left| \frac{\omega_{pitch}(t) - \omega_{pitch}(t-dt)}{dt} \right| \leq \text{ACCEL\_P\_MAX} $$

Where:
*   $\text{ACCEL\_P\_MAX}$ is in centidegrees/sec².
*   **Example:** A value of 36000 means the drone can increase its pitch rotation by 360 degrees per second, every second.

On frames like "Dead Cats," where the mass is distributed longitudinally, `ACCEL_P_MAX` often needs to be lower than `ACCEL_R_MAX` because the airframe has more inertia along the pitch axis.

## The Engineer's View
This parameter is the `_accel_pitch_max` member in `AC_AttitudeControl`.

It is used in the **Input Shaper** for all pitch-related attitude commands:

```cpp
// AC_AttitudeControl.cpp
_ang_vel_target.y = input_shaping_angle(error, _input_tc, get_accel_pitch_max_radss(), ...);
```

By constraining the input before it reaches the PID loop, ArduPilot ensures that the inner Rate Loop never receives a "step" command that it can't physically follow. This prevents P-gain "overshoot" and motor saturation during high-authority pitch changes.

## Tuning & Behavior
*   **Default Value:** 0.0 (Standard)
*   **Range:** 0 - 180,000
*   **Effect of Increasing:** Snappier pitch response. Better for high-speed tracking and stopping.
*   **Effect of Decreasing:** Smoother cinematic movement. Reduces the risk of "pitch bobbing" during aggressive flight.

### Use Case Recommendations
*   **Cinematography:** **Set to 36000.** Provides a very professional, weighted feel to forward flight starts and stops.
*   **Long-Range Flying:** **Set to 20000.** High pitch accelerations are inefficient and increase drag; a lower limit keeps the drone in its "sweet spot" for cruise efficiency.
*   **Racing / Acro:** **Keep at 0.0.** Racers need the absolute maximum pitch authority to perform "power loops" and clear sharp turns.

### Troubleshooting
*   **Scenario:** Drone nose "dips" or "bobs" when you release the stick after flying forward.
    *   **Diagnosis:** `ATC_ACCEL_P_MAX` is likely set too high, allowing the drone to stop rotating faster than the PID loop can stabilize.
    *   **Fix:** Reduce `ATC_ACCEL_P_MAX` to 40000 and re-test.