---
layout: parameter
name: INS_HNTCH_REF
display_name: Harmonic Notch Filter reference value
description: The reference sensor value used to scale the notch frequency.
default_value: 0
range: 0.0 1.0
units: 
group: INS
visual_asset_id: ins_hntch_ref_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L95
---

# Harmonic Notch Filter reference value (INS_HNTCH_REF)

## Description
`INS_HNTCH_REF` tells the filter how to interpret the dynamic sensor data.

*   **Throttle Mode (1):** This is your **Hover Throttle**.
    *   If you hover at 35% throttle, set this to **0.35**.
    *   The filter assumes that at 0.35 throttle, the noise is at `INS_HNTCH_FREQ`.
*   **ESC/RPM Mode (2/3):** This is a **Scaler**.
    *   Usually set to **1.0** (No scaling).
    *   If you have a helicopter where the RPM sensor reports Motor RPM but the noise is at Rotor RPM (gear ratio), you can use this to scale it. Or if using FFT, this is unused.

## The Mathematics
**Throttle Mode:**
$$ \text{Scaling Factor} = \frac{\text{Current Throttle}}{\text{INS\_HNTCH\_REF}} $$
$$ f_{notch} = \text{INS\_HNTCH\_FREQ} \times \sqrt{\text{Scaling Factor}} $$
*(Note: The relationship is often modeled as square root for RPM vs Throttle).*

## The Engineer's View
If set to **0** in dynamic modes, the filter effectively becomes static or disabled (depending on code path).
In **FFT Mode**, this parameter is typically ignored, but setting it to a non-zero value is sometimes required to "arm" the dynamic logic in older firmwares.

## Tuning & Behavior
*   **Default Value:** 0
*   **Range:** 0.0 - 1.0
*   **Critical for Throttle Mode:** If this is wrong, the notch will move incorrectly. Ideally, perform a "Hover Learn" flight or check `MOT_THST_HOVER` and copy that value here.