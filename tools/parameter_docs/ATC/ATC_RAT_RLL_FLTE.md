---
layout: parameter
name: ATC_RAT_RLL_FLTE
display_name: Roll Axis Rate Error Filter
description: Low-pass filter frequency (in Hz) applied to the roll rate error. Smooths out gyro noise and frame vibrations before they reach the motor PID loop.
default_value: 0.0
range: 0 100
units: Hz
group: ATC
visual_asset_id: atc_rat_rll_flte_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L53
---

# Roll Axis Rate Error Filter (ATC_RAT_RLL_FLTE)

## Description
`ATC_RAT_RLL_FLTE` is the primary "vibration shield" for your roll rate controller. 

The Gyroscope on your drone is incredibly sensitive; it can feel every tiny vibration from the motors and every slight flex of the frame. If the flight controller tried to react to every single 100Hz vibration, the motors would be constantly surging, creating heat and noise without actually stabilizing the drone. This filter "washes out" that high-frequency noise, ensuring the PID loop only reacts to the "true" movement of the vehicle.

*   **Higher Frequency (e.g., 40Hz):** Faster control response. The drone feels more "connected," but motor noise and heat will increase.
*   **Lower Frequency (e.g., 10Hz):** Smoother flight and quieter motors, but the drone will feel slightly "loose" or "mushy."
*   **Disabled (0):** The software uses the main gyro sample rate (often 400Hz or 1kHz). Highly risky for larger drones.

## The Mathematics
This is a single-pole low-pass filter applied to the error signal ($E = \omega_{target} - \omega_{gyro}$):

$$ E_{filtered} = E_{prev} + \alpha \cdot (E_{raw} - E_{prev}) $$

Where the smoothing factor $\alpha$ is derived from `ATC_RAT_RLL_FLTE` ($f_c$):

$$ \alpha = \frac{dt}{dt + \frac{1}{2\pi f_c}} $$

**Trade-off:** Lowering $f_c$ increases "Phase Lag." If the lag becomes too great, the drone will start to wobble at a low frequency because its corrections are arriving too late.

## The Engineer's View
This parameter maps to `_filt_E_hz` in the `_pid_rate_roll` object.

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

By filtering the error *before* the P, I, and D calculations, ArduPilot ensures that the entire rate loop is synchronized on a consistent, clean signal.

## Tuning & Behavior
*   **Default Value:** 0.0 (Internal auto-selection)
*   **Range:** 0.0 - 100.0 Hz
*   **Effect of Increasing:** Better stability in high winds. Drone feels more "locked" during flips.
*   **Effect of Decreasing:** Quieter motor sound, less "jello" in the camera gimbal. Essential for large, flexible frames.

### Use Case Recommendations
*   **5-inch Racing Quad:** **Set to 30.0 - 40.0 Hz.** High performance and rigid frames can handle a very high filter cutoff for instant response.
*   **10-15 inch Photography Drone:** **Set to 20.0 Hz.** Good compromise between stability and motor heat.
*   **Large Professional Rig (>15 inch props):** **Set to 10.0 Hz.** Large props have high inertia; trying to control them with 30Hz data is pointless and inefficient.

### Troubleshooting
*   **Scenario:** Drone oscillates rapidly (like a cell phone vibrating) when taking off.
    *   **Diagnosis:** Frame resonance passing through the PID loop.
    *   **Fix:** Reduce `ATC_RAT_RLL_FLTE` by 5.0 Hz increments until the vibration stops.