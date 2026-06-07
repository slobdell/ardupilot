---
layout: parameter
name: INS_HNTCH_OPTS
display_name: Harmonic Notch Filter options
description: Advanced configuration bitmask for the harmonic notch filter.
default_value: 0
range: 0 31
units: 
group: INS
visual_asset_id: ins_hntch_opts_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L112
---

# Harmonic Notch Filter options (INS_HNTCH_OPTS)

## Description
`INS_HNTCH_OPTS` provides advanced tweaks to how the filter operates.

*   **Bit 0 (1): Double Notch.** Puts two notches side-by-side to create a wider, flatter stopband. Good for broad noise peaks.
*   **Bit 1 (2): Multi-Source.** Used with FFT or ESC telemetry to track multiple independent peaks (e.g., different motors spinning at different speeds) instead of just one average frequency.
*   **Bit 2 (4): Update at loop rate.** Updates the filter center frequency every main loop cycle instead of subsampled. Higher CPU usage, better tracking.
*   **Bit 3 (8): Enable on All IMUs.** Forces the filter to run on all gyros, not just the primary. **Crucial** for EKF3 affinity/lane switching to work correctly.
*   **Bit 4 (16): Triple Notch.** Even wider than Double.

## The Mathematics
**Double Notch:** Instead of one filter at $f_0$, it places two at $f_0 \pm \delta$, creating a "W" shape (or flat bottom) response.

**Multi-Source:** Allocates distinct filters for each frequency input source.

## The Engineer's View
*   **Bit 3 (8) - EnableOnAllIMUs:** Highly recommended for redundancy. If the primary gyro fails and EKF switches to the secondary, you want that secondary to be filtered too.
*   **Bit 1 (2) - Multi-Source:** Essential for **Dynamic FFT** setups to track individual motor peaks.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:**
    *   **Set Bit 3 (8) -> Value 8.** (Filter all IMUs).
    *   **If using FFT:** Set Bit 1 (2) + Bit 4 (16) (Triple Notch) often works well -> Value 2 + 16 = 18 (or 2+8 = 10).
    *   **If using ESC Telemetry:** Set Bit 1 (2) -> Value 2 (Track individual motors).