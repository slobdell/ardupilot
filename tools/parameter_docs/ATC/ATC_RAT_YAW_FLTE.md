---
layout: parameter
name: ATC_RAT_YAW_FLTE
display_name: Yaw Axis Rate Error Filter
description: Low-pass filter frequency (in Hz) applied to the yaw rate error. Smooths out gyro noise and vibrations before they reach the motor torque loop.
default_value: 0.0
range: 0 20
units: Hz
group: ATC
visual_asset_id: atc_rat_yaw_flte_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L231
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L53
---

# Yaw Axis Rate Error Filter (ATC_RAT_YAW_FLTE)

## Description
`ATC_RAT_YAW_FLTE` is the primary "tail-vibration shield" for your drone. 

While Roll and Pitch have to deal with intense vibrations from the motor arms flexing, the Yaw axis (the vertical axis) typically feels a different kind of noise. Because multirotors yaw by changing torque, any rapid "pulsing" in the motor RPM can look like a yaw rotation to the gyroscope. This filter "washes out" that high-frequency motor noise, ensuring the tail controller only reacts to the drone's actual heading changes.

*   **Higher Frequency (e.g., 10Hz):** Faster yaw response. The nose feels more "locked," but motor noise will increase.
*   **Lower Frequency (e.g., 2Hz):** Smoother heading hold and quieter tail, but the drone may feel slightly "mushy" or take longer to stop a fast turn.
*   **Default (0):** Internal auto-selection (usually very low, around 2-5Hz).

## The Mathematics
This is a single-pole low-pass filter applied to the yaw error signal ($E = \omega_{yaw\_target} - \omega_{yaw\_gyro}$):

$$ E_{filtered} = E_{prev} + \alpha \cdot (E_{raw} - E_{prev}) $$

Where $\alpha$ is derived from `ATC_RAT_YAW_FLTE` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Note:** The yaw filter frequency is usually much lower than the roll/pitch filters because torque reaction is a slow physical process, and we want to avoid exciting the mechanical "twist" of the drone's frame.

## The Engineer's View
This parameter maps to `_filt_E_hz` in the `_pid_rate_yaw` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (_reset_filter) {
    _reset_filter = false;
    _error = target - measurement;
} else {
    _error += ((target - measurement) - _error) * get_filt_E_alpha(dt);
}
```

Filtering the error *before* it enters the PID loop ensures that the I-term (`ATC_RAT_YAW_I`) doesn't build up "learned corrections" based on momentary noise spikes.

## Tuning & Behavior
*   **Default Value:** 0.0 (Internal auto-selection, usually 2.0 - 5.0 Hz)
*   **Range:** 0.0 - 20.0 Hz
*   **Effect of Increasing:** Snappier tail hold. Faster corrections for motor-torque dips.
*   **Effect of Decreasing:** Quieter motor operation, less "growling" sound from the propellers during hover.

### Use Case Recommendations
*   **Long Endurance Drones:** **Set to 2.0 Hz.** Minimizes wasted motor current on correcting high-frequency yaw jitter, increasing battery life.
*   **Racing / FPV Chase Drones:** **Increase to 10.0 - 15.0 Hz.** Essential for the "instant tail" feel needed when tracking moving objects at high speeds.
*   **Heavy Lift Multirotors:** **Set to 3.0 Hz.** Prevents the long, heavy arms from oscillating at their resonant twisting frequency.

### Troubleshooting
*   **Scenario:** Drone nose "shakes" rapidly from side to side in wind.
    *   **Diagnosis:** Yaw loop resonance.
    *   **Fix:** Reduce `ATC_RAT_YAW_FLTE` by 1.0 Hz increments.