---
layout: parameter
name: ATC_RAT_PIT_FLTE
display_name: Pitch Axis Rate Error Filter
description: Low-pass filter frequency (in Hz) applied to the pitch rate error. Smooths out gyro noise and vibrations before they reach the motor PID loop.
default_value: 0.0
range: 0 100
units: Hz
group: ATC
visual_asset_id: atc_rat_pit_flte_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L162
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L53
---

# Pitch Axis Rate Error Filter (ATC_RAT_PIT_FLTE)

## Description
`ATC_RAT_PIT_FLTE` is the primary "noise cleaner" for your pitch controller. 

The drone's gyroscope is extremely sensitive and picks up every mechanical vibration from the motors and frame. If the flight controller tried to react to every tiny vibration, the motors would work overtime, wasting battery and potentially burning out. This filter "washes out" that high-frequency noise, ensuring the PID loop only reacts to the drone's actual movements.

*   **Higher Frequency (e.g., 40Hz):** Faster control response. The drone feels more "locked-in," but motor noise and heat will increase.
*   **Lower Frequency (e.g., 10Hz):** Smoother flight and quieter motors, but the drone will feel slightly "loose" or "mushy" in its pitch.
*   **Disabled (0):** The software uses the main gyro sample rate. This is risky for all but the cleanest, most rigid racing frames.

## The Mathematics
This is a single-pole low-pass filter applied to the pitch error signal ($E$):

$$ E_{filtered} = E_{prev} + \alpha \cdot (E_{raw} - E_{prev}) $$

Where $\alpha$ is derived from `ATC_RAT_PIT_FLTE` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Trade-off:** A lower $f_c$ introduces "Phase Lag." If the lag becomes too great, the drone will develop a low-frequency vertical "nodding" or wobble because its pitch corrections are arriving too late.

## The Engineer's View
This parameter maps to `_filt_E_hz` in the `_pid_rate_pitch` object.

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

By filtering the error *before* the P, I, and D calculations, ArduPilot ensures that the entire rate loop is based on a smooth, consistent measurement of the vehicle's state.

## Tuning & Behavior
*   **Default Value:** 0.0 (Internal auto-selection)
*   **Range:** 0.0 - 100.0 Hz
*   **Effect of Increasing:** Snappier pitch response. Tighter tracking during rapid forward flight.
*   **Effect of Decreasing:** Quieter motors, less "jello" in the camera gimbal. Essential for long-range frames with flexible motor arms.

### Use Case Recommendations
*   **Standard GPS Photography Drone:** **Set to 20.0 Hz.** Provides a very smooth and quiet vertical hover.
*   **FPV Freestyle Quad:** **Set to 30.0 - 40.0 Hz.** High performance requires a high filter cutoff for instant response.
*   **Heavy Lift Multirotors:** **Set to 10.0 Hz.** Large props generate significant low-frequency noise; a lower filter keeps the system stable.

### Troubleshooting
*   **Scenario:** Drone's nose "vibrates" or makes a growling sound during fast forward flight.
    *   **Diagnosis:** Frame resonance passing through the PID loop.
    *   **Fix:** Reduce `ATC_RAT_PIT_FLTE` by 5.0 Hz.