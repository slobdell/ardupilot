---
layout: parameter
name: PSC_ACCZ_P
display_name: Position Control Acceleration (Vertical) P Gain
description: Converts vertical acceleration error (target acceleration - measured acceleration) into a throttle output.
default_value: 0.5
range: 0.2 1.5
units: 
group: PSC
visual_asset_id: psc_accz_p_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L13
---

# Position Control Acceleration (Vertical) P Gain (PSC_ACCZ_P)

## Description
`PSC_ACCZ_P` is the innermost "knob" of the altitude control system. It determines how hard the flight controller pushes the motors to correct an error in **Vertical Acceleration**.

While `PSC_POSZ_P` cares about height and `PSC_VELZ_P` cares about climb speed, `PSC_ACCZ_P` cares about the *instantaneous force* required to counteract gravity and change speed. It effectively translates "I need more lift" into a specific motor PWM signal.

*   **Low Value:** The drone will feel "heavy" and slow to recover from drops. It may feel like it is struggling to stay airborne when carrying a heavy battery.
*   **High Value:** The drone will feel very "light" and responsive.
*   **Too High:** The drone will oscillate rapidly in the vertical axis, creating a "buzzing" sound as the motors rapidly oscillate their RPM.

## The Mathematics
This parameter is the Proportional ($k_P$) term in the Vertical Acceleration PID loop.

$$ \text{Throttle}_{out} = k_P \cdot (\vec{A}_{z\_target} - \vec{A}_{z\_measured}) + \dots + \text{Hover\_Throttle} $$

Where:
*   $\vec{A}_{z\_target}$ is the acceleration required to reach the target climb rate.
*   $\vec{A}_{z\_measured}$ is the vertical acceleration from the IMU (with gravity removed).
*   $k_P$ is `PSC_ACCZ_P`.
*   **Dimensionality:** This gain converts Acceleration ($L T^{-2}$) into a dimensionless Throttle percentage ($0.0$ to $1.0$).

## The Engineer's View
This parameter is the `_kp` member of the `_pid_accel_z` object (class `AC_PID`) inside `AC_PosControl`.

It is executed in `AC_PosControl::update_z_controller()`:

```cpp
// AC_PosControl.cpp
thr_out = _pid_accel_z.update_all(_accel_target.z, z_accel_meas, _dt, ...) * 0.001f;
thr_out += _motors.get_throttle_hover();
```

Note the `* 0.001f` scaling. This is because the internal PID library often calculates in larger units (e.g., centi-acceleration) and then scales back to the $0..1$ throttle range.

## Tuning & Behavior
*   **Default Value:** 0.5
*   **Range:** 0.2 - 1.5
*   **Effect of Increasing:** Snappier recovery from vertical drops. Better tracking of the terrain in terrain-following modes.
*   **Effect of Decreasing:** Smoother, "softer" vertical behavior. Reduces vertical jitters in high-vibration environments.

### Use Case Recommendations
*   **Racing / Acro-Loiter:** **Increase to 0.7 - 0.9.** Provides the high-authority lift needed for aggressive maneuvers.
*   **Heavy Cargo Drone:** **Decrease to 0.3 - 0.4.** Heavy vehicles have slow motor response times; pushing them too hard vertically with a high P-gain will lead to dangerous "vertical porpoising."
*   **High Vibration Frames:** **Decrease to 0.3.** High vibration creates noise in the IMU's Z-acceleration measurement. Reducing the P-gain prevents this noise from being amplified into the motors.

### Troubleshooting
*   **Scenario:** Drone "bobs" up and down rapidly after a vertical punch.
    *   **Diagnosis:** `PSC_ACCZ_P` is too high (P-gain oscillation).
    *   **Fix:** Reduce `PSC_ACCZ_P` by 0.1 until the bobbing stops.

