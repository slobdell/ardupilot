---
layout: parameter
name: PSC_ACCZ_NEF
display_name: Position Control Acceleration (Vertical) Error Notch Filter Index
description: Selects which Harmonic Notch Filter instance (1-8) should be applied to the vertical acceleration error. Essential for cleaning up resonant vertical vibrations.
default_value: 0
range: 1 8
units: 
group: PSC
visual_asset_id: psc_accz_nef_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_PosControl.cpp#L252
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_PID.cpp#L96
---

# Position Control Acceleration (Vertical) Error Notch Filter Index (PSC_ACCZ_NEF)

## Description
`PSC_ACCZ_NEF` is an advanced "surgical" filter for altitude control. While standard filters (like `PSC_ACCZ_FLTE`) remove *all* high-frequency noise, a **Notch Filter** removes noise at one specific, problematic frequency (and its harmonics).

On many drones, the frame or the vertical column of air under the propellers has a "resonant frequency"—a specific speed where the whole drone starts to vibrate vertically. If the altitude controller "hears" this vibration and tries to correct it, it can lead to a feedback loop that destroys the drone. By setting this index, you tell the vertical controller to use one of your pre-configured Harmonic Notch filters (usually linked to motor RPM or an FFT) to specifically ignore that resonant vertical frequency.

*   **Set to 0:** No notch filter is applied to the vertical error.
*   **Set to 1-8:** Uses the corresponding Harmonic Notch filter (configured via `INS_HNTCH_*` parameters).

## The Mathematics
The notch filter ($H_{notch}$) is applied to the error signal ($E$) before it enters the PID logic:

$$ \vec{E}_{clean} = H_{notch}( \vec{A}_{z\_target} - \vec{A}_{z\_measured} ) $$

Where $H_{notch}$ is a dynamic filter whose center frequency is typically driven by motor RPM ($f \propto RPM$):

$$ f_{center} = \text{INS\_HNTCH\_FREQ} \cdot \frac{\text{RPM}}{\text{RPM}_{ref}} $$

## The Engineer's View
This parameter maps to `_notch_E_filter` in the `_pid_accel_z` object.

It is applied in `AC_PID::update_all()`:

```cpp
// AC_PID.cpp
if (_notch_E_filter > 0) {
    // Note: The actual filtering happens via a pointer to the 
    // INS harmonic notch library.
    error = _notch_E_filter_ptr->apply(error);
}
```

This integration allows the innermost altitude loop to benefit from the same advanced vibration rejection techniques used by the rate controllers (the main flight loops).

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 1 - 8 (Filter Index)
*   **Effect of Enabling:** Significantly cleaner motor signals in Loiter. Allows for higher vertical P-gains (`PSC_ACCZ_P`) without causing vertical "chirp."
*   **Effect of Disabling:** More susceptible to vertical resonance and Z-axis motor noise.

### Use Case Recommendations
*   **Large Professional Drones:** **Set to 1 (usually).** If you have already configured a Harmonic Notch for your main flight loops, applying it to the vertical loop is highly recommended to improve altitude hold performance in wind.
*   **Small Racers:** **Keep at 0.** Smaller drones usually have resonant frequencies high enough that a standard 20Hz low-pass filter is sufficient.
*   **Coaxial / X8 Drones:** **Set to 1.** Overlapping prop wash creates complex vertical resonances; the notch filter is often mandatory for a stable hover.

### Troubleshooting
*   **Scenario:** Drone hovers well, but you see constant high-frequency oscillations in your `PSCZ.Acc` logs that match your motor RPM.
    *   **Diagnosis:** Vertical resonance is passing into the altitude controller.
    *   **Fix:** Ensure a Harmonic Notch is configured for the frame, and set `PSC_ACCZ_NEF` to that notch's index.
