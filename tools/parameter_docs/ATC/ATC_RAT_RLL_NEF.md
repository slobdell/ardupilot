---
layout: parameter
name: ATC_RAT_RLL_NEF
display_name: Roll Axis Rate Error Notch Filter Index
description: Selects which Harmonic Notch Filter instance (1-8) should be applied to the roll rate error. Critical for removing motor-induced resonances from the flight control loop.
default_value: 0
range: 1 8
units: 
group: ATC
visual_asset_id: atc_rat_rll_nef_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L106
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L96
---

# Roll Axis Rate Error Notch Filter Index (ATC_RAT_RLL_NEF)

## Description
`ATC_RAT_RLL_NEF` is a specialized "anti-vibration" setting. While standard filters (like `RAT_RLL_FLTE`) remove all high-frequency noise, a **Notch Filter** is like a surgical knife—it removes noise at one very specific, problematic frequency.

On multirotors, the motors and propellers create intense vibration at specific frequencies (linked to their RPM). If these vibrations happen to match the "ringing" frequency of your drone's carbon fiber arms, the arms will start to oscillate. If the flight controller tries to fix these oscillations, it creates a feedback loop that makes the motors shriek and can even cause the drone to explode mid-air. 

By setting this index, you tell the roll controller to use one of your pre-configured Harmonic Notch filters (linked to motor RPM or an FFT) to specifically "ignore" those frame resonances.

*   **Set to 0:** No notch filter is applied to the roll rate error.
*   **Set to 1-8:** Uses the corresponding Harmonic Notch filter (configured via `INS_HNTCH_*`).

## The Mathematics
The notch filter ($H_{notch}$) is applied to the error signal ($E$) before it enters the PID logic:

$$ \vec{E}_{clean} = H_{notch}( \omega_{target} - \omega_{actual} ) $$

The center frequency of the notch ($f_c$) is dynamic and moves with the motor speed:
$$ f_c \propto \text{Motor\_RPM} $$

This ensures that no matter how fast you are flying, the "noise" from the propellers is always perfectly filtered out.

## The Engineer's View
This parameter maps to `_notch_E_filter` in the `_pid_rate_roll` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (_notch_E_filter > 0) {
    // Passes the error through the INS library's harmonic notch pointer
    error = _notch_E_filter_ptr->apply(error);
}
```

By applying the notch to the **Error** signal (rather than the raw Gyro), ArduPilot ensures that the P, I, and D terms all receive the cleanest possible data, allowing for much higher gains and a "locked-in" feel.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 1 - 8 (Filter Index)
*   **Effect of Enabling:** Allows for much higher `ATC_RAT_RLL_P` and `D` gains. Makes the drone sound significantly quieter and smoother.
*   **Effect of Disabling:** Motors will be noisier and hotter. Increased risk of "D-gain blowouts."

### Use Case Recommendations
*   **High-Performance Multirotors:** **Always Set to 1 (after configuring `INS_HNTCH`).** Modern flight performance depends entirely on good notch filtering.
*   **Large Frames (>15 inch):** **Set to 1.** Large arms are very prone to low-frequency resonance that standard filters can't catch without creating too much lag.
*   **Small Whoops:** **Keep at 0.** Resonances are usually high enough that standard filters handle them.

### Troubleshooting
*   **Scenario:** I increased my D-gain and now the drone oscillates violently the moment I take off.
    *   **Diagnosis:** Frame resonance is being amplified.
    *   **Fix:** Ensure `INS_HNTCH` is configured and set `ATC_RAT_RLL_NEF` to 1.