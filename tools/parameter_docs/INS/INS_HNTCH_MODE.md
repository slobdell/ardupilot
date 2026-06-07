---
layout: parameter
name: INS_HNTCH_MODE
display_name: Harmonic Notch Filter Dynamic Mode
description: Determines how the filter tracks the noise frequency.
default_value: 1
range: 0 4
units: 
group: INS
visual_asset_id: ins_hntch_mode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L104
---

# Harmonic Notch Filter Dynamic Mode (INS_HNTCH_MODE)

## Description
`INS_HNTCH_MODE` tells the filter how to find the noise. Motor noise moves as you change throttle. This parameter selects the "Sensor" used to track that movement.

*   **0: Fixed.** The filter sits at `INS_HNTCH_FREQ` and never moves. Useful for frame resonance that doesn't change.
*   **1: Throttle (Default).** Uses the estimated throttle output. If you throttle up, the filter frequency rises. Simple and effective for most drones without RPM sensors.
*   **2: RPM Sensor.** Uses real-time data from an RPM sensor. Extremely accurate.
*   **3: ESC Telemetry.** Uses RPM data reported by BLHeli_32/AM32 ESCs via DShot. The "Gold Standard" for filtering.
*   **4: Dynamic FFT.** Uses a Fast Fourier Transform to "listen" to the noise and find the peak automatically. CPU intensive but requires no external sensors.

## The Mathematics
**Throttle Mode (1):**
$$ f_{center} = \text{FREQ} \cdot \frac{\text{Throttle}_{current} - \text{Throttle}_{min}}{\text{REF} - \text{Throttle}_{min}} + f_{min} $$
*(Simplified linear model)*.

**ESC/RPM Mode (2/3):**
$$ f_{center} = \text{RPM}_{average} / 60 $$

## The Engineer's View
This maps to the `_tracking_mode` member of `HarmonicNotchFilterParams`.
*   **Throttle:** Low latency, but an "estimate". Requires tuning `INS_HNTCH_REF`.
*   **ESC Telemetry:** High accuracy, but can have transport latency.
*   **FFT:** High latency (window size dependent), but requires zero tuning of reference values.

## Tuning & Behavior
*   **Default Value:** 1 (Throttle)
*   **Recommendation:**
    *   If you have **BLHeli_32/AM32 ESCs**, set to **3 (ESC Telemetry)**.
    *   If you have a powerful H7 board (Cube Orange, Durandal), set to **4 (FFT)**.
    *   Otherwise, stick with **1 (Throttle)** and tune `INS_HNTCH_REF` carefully.