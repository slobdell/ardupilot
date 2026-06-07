---
layout: parameter
name: ATC_RAT_YAW_NTF
display_name: Yaw Axis Rate Target Notch Filter Index
description: Selects which Harmonic Notch Filter instance (1-8) should be applied to the yaw rate setpoint. Cleans up command-side resonances in heading control.
default_value: 0
range: 1 8
units: 
group: ATC
visual_asset_id: atc_rat_yaw_ntf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L89
---

# Yaw Axis Rate Target Notch Filter Index (ATC_RAT_YAW_NTF)

## Description
`ATC_RAT_YAW_NTF` is a surgical filter for your drone's tail commands. 

In a multirotor, yaw is the most mechanically flexible axis because the drone has to "twist" the frame to spin. On large drones with long motor arms, this torsional flexibility creates a specific resonant frequency—if the tail moves at just the right speed, the whole frame starts to vibrate. 

Sometimes, the high-level flight software (like the GPS heading hold or an automated survey grid) can request tiny, rapid yaw changes that accidentally hit this resonance. This filter "scoops out" those problematic command frequencies before they reach the motors, ensuring the tail always moves with professional smoothness.

*   **Set to 0:** No notch filter is applied to the yaw target.
*   **Set to 1-8:** Uses the corresponding Harmonic Notch filter (configured via `INS_HNTCH_*`).

## The Mathematics
The notch filter ($H_{notch}$) processes the target yaw rate ($\omega_{yaw\_target}$) before it enters the control loop:

$$ \omega_{yaw\_clean} = H_{notch}( \omega_{yaw\_target\_raw} ) $$

The clean target $\omega_{yaw\_clean}$ is then used for the PID calculation. Because the filter is dynamic ($f_c \propto \text{RPM}$), it perfectly ignores command noise that matches the physical propeller noise.

## The Engineer's View
This parameter maps to `_notch_T_filter` in the `_pid_rate_yaw` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (_notch_T_filter > 0) {
    // Passes the target through the dynamic notch filter
    target = _notch_T_filter_ptr->apply(target);
}
```

This is an essential feature for **Large Octocopters** or **Tethered Drones** where the physical heading torque is low and command-side jitter can easily cause a resonant "tail wag."

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 1 - 8 (Filter Index)
*   **Effect of Enabling:** Quieter motors during heading changes. Reduces the chance of "tail-induced" frame vibration during autonomous turns.
*   **Effect of Disabling:** Maximum heading responsiveness.

### Use Case Recommendations
*   **High-Value Aerial Cinematography:** **Set to 1.** Ensures that every camera pan is perfectly clean and free from software-induced mikro-jitters.
*   **Large Hybrid/Heavy Lift Drones:** **Set to 1.** Prevents the high-leverage motors from exciting the torsional modes of the long frame arms.
*   **Standard Quadcopter:** **Keep at 0.** Standard low-pass filters are usually sufficient for command smoothing.

### Troubleshooting
*   **Scenario:** Drone tail "vibrates" or makes a high-pitched growl only when rotating in an Auto mission.
    *   **Diagnosis:** Command-side torsional resonance.
    *   **Fix:** Assign a notch filter to the yaw target via `ATC_RAT_YAW_NTF`.