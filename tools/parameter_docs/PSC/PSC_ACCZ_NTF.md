---
layout: parameter
name: PSC_ACCZ_NTF
display_name: Position Control Acceleration (Vertical) Target Notch Filter Index
description: Selects which Harmonic Notch Filter instance (1-8) should be applied to the vertical acceleration target. Clean up command-side resonances.
default_value: 0
range: 1 8
units: 
group: PSC
visual_asset_id: psc_accz_ntf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L89
---

# Position Control Acceleration (Vertical) Target Notch Filter Index (PSC_ACCZ_NTF)

## Description
`PSC_ACCZ_NTF` is the sister filter to `PSC_ACCZ_NEF`. While the "Error Notch" filter cleans up noise from the sensors (IMU), the **Target Notch** filter cleans up noise from the commands (Software).

In a complex vertical control system, the "target acceleration" is often the result of many calculations—path planning, terrain following, and obstacle avoidance. Sometimes, these software processes can introduce rhythmic "stepping" or high-frequency ripples into the command signal. If these ripples happen to match the physical resonance of the frame or the motors, they can cause the drone to vibrate. This parameter allows the drone to specifically "ignore" those command-side frequencies.

*   **Set to 0:** No notch filter is applied to the vertical target.
*   **Set to 1-8:** Uses the corresponding Harmonic Notch filter (configured via `INS_HNTCH_*`).

## The Mathematics
The notch filter ($H_{notch}$) is applied to the target acceleration signal ($T$) before it enters the PID loop:

$$ \vec{T}_{clean} = H_{notch}( \vec{A}_{z\_target\_raw} ) $$

The clean target $\vec{T}_{clean}$ is then compared against the actual acceleration to compute the error.

## The Engineer's View
This parameter maps to `_notch_T_filter` in the `_pid_accel_z` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (_notch_T_filter > 0) {
    target = _notch_T_filter_ptr->apply(target);
}
```

This is rarely used on standard multirotors but is critical for large, flexible frames or vehicles where the path planner (e.g., Terrain Following) might be updating at a lower rate than the PID loops, creating high-frequency "stairs" in the input signal.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 1 - 8 (Filter Index)
*   **Effect of Enabling:** Smoother motor sound during vertical maneuvers. Reduces "ringing" in the motor output when following complex vertical paths.
*   **Effect of Disabling:** Maximum responsiveness to command changes.

### Use Case Recommendations
*   **Terrain Following / Lidar-Based flight:** **Consider setting to 1.** Lidar and terrain sensors often update at low frequencies (10-50Hz). This notch filter can round off the "jumps" in target altitude as the drone crosses uneven terrain.
*   **Standard Build:** **Keep at 0.** Standard low-pass filters (`PSC_ACCZ_FLTT`) are usually sufficient for command smoothing.
*   **Very Large VTOL (Flexible Wings):** **Set to 1.** Flexible wings can act like giant vertical springs. A command-side notch filter ensures the software never "kicks" the wing at its resonant frequency.

### Troubleshooting
*   **Scenario:** Drone makes a distinct "thumping" or "humming" sound specifically when following terrain or a mission path, but is quiet when hovering still.
    *   **Diagnosis:** Command-side resonance.
    *   **Fix:** Apply a notch filter at the resonant frequency of the frame via `PSC_ACCZ_NTF`.
