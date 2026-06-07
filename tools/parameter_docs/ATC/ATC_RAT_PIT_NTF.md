---
layout: parameter
name: ATC_RAT_PIT_NTF
display_name: Pitch Axis Rate Target Notch Filter Index
description: Selects which Harmonic Notch Filter instance (1-8) should be applied to the pitch rate setpoint. Cleans up command-side resonances in forward/backward flight.
default_value: 0
range: 1 8
units: 
group: ATC
visual_asset_id: atc_rat_pit_ntf_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L89
---

# Pitch Axis Rate Target Notch Filter Index (ATC_RAT_PIT_NTF)

## Description
`ATC_RAT_PIT_NTF` is a high-precision command filter for the drone's pitch axis.

In many industrial or cinematic drones, the pitch axis has a long lever arm (the "spine" of the drone). This structure can be prone to specific vibration frequencies. If your automated flight controller (the high-level software) commands pitch changes at a frequency that matches the frame's resonance, the drone will vibrate.

This parameter allows you to apply a **Harmonic Notch Filter** specifically to the command signal. It "scoops out" the problematic frequencies from your mission paths or GPS corrections before they are sent to the motors. This results in a drone that follows complex paths with much greater longitudinal stability and zero "growling" or ringing in the pitch axis.

*   **Set to 0:** No notch filter is applied to the pitch target rate.
*   **Set to 1-8:** Uses the corresponding Harmonic Notch filter (configured via `INS_HNTCH_*`).

## The Mathematics
The notch filter ($H_{notch}$) processes the target pitch rate ($\omega_{pit\_target}$) before the PID loop sees it:

$$ \omega_{pit\_clean} = H_{notch}( \omega_{pit\_raw} ) $$

The filter moves its rejection frequency dynamically to match the noise:
$$ f_{center} \propto \text{Motor\_RPM} $$

## The Engineer's View
This parameter maps to `_notch_T_filter` in the `_pid_rate_pitch` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (_notch_T_filter > 0) {
    // Passes the target through the dynamic notch filter
    target = _notch_T_filter_ptr->apply(target);
}
```

This is particularly useful when using **Terrain Following** or **Object Avoidance**, as those systems can sometimes generate high-frequency "jitter" in the pitch setpoint as they react to noisy environmental data.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 1 - 8 (Filter Index)
*   **Effect of Enabling:** Quieter flight during autonomous navigation. Reduces longitudinal "bobbing" caused by software setpoint jitter.
*   **Effect of Disabling:** Maximum pitch command responsiveness.

### Use Case Recommendations
*   **Agricultural Survey (Terrain Following):** **Set to 1.** Helps smooth the drone's pitch corrections as it follows undulating hills at high speeds.
*   **Lidar-Based Obstacle Avoidance:** **Set to 1.** Prevents "software chatter" from the Lidar sensor from reaching the motors.
*   **Standard Multirotor:** **Keep at 0.** Standard low-pass filters are usually sufficient for command smoothing.

### Troubleshooting
*   **Scenario:** Drone nose "jitters" specifically when obstacle avoidance is enabled, but is smooth in manual flight.
    *   **Diagnosis:** High-level setpoint noise.
    *   **Fix:** Assign a notch filter to the pitch target via `ATC_RAT_PIT_NTF`.