---
layout: parameter
name: INS_HNTCH_HMNCS
display_name: Harmonic Notch Filter harmonics
description: Bitmask enabling specific harmonic frequencies.
default_value: 3
range: 0 65535
units: 
group: INS
visual_asset_id: ins_hntch_hmncs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L86
---

# Harmonic Notch Filter harmonics (INS_HNTCH_HMNCS)

## Description
`INS_HNTCH_HMNCS` is a bitmask that tells the filter which multiples of the base frequency to target.

*   **Bit 0 (1):** 1st Harmonic (Base Frequency).
*   **Bit 1 (2):** 2nd Harmonic ($2 \times F$).
*   **Bit 2 (4):** 3rd Harmonic ($3 \times F$).
*   **...**

Default is **3 (1 + 2)**, meaning it filters the Base Frequency and the 2nd Harmonic.

## The Mathematics
$$ \text{Active Filters} = \sum_{k=0}^{15} (2^k \text{ is set}) \rightarrow \text{Filter at } (k+1) \cdot f_0 $$

## The Engineer's View
Each set bit allocates a new `NotchFilter` object.
Allocating too many harmonics (e.g., setting it to 255) consumes CPU and memory.
For typical multicopters, the energy is concentrated in the 1st, 2nd, and sometimes 4th harmonic.

## Tuning & Behavior
*   **Default Value:** 3 (1st and 2nd Harmonics)
*   **Recommendation:**
    *   **3 (1st + 2nd):** Good for most quads.
    *   **1 (1st only):** If CPU is tight or noise is simple.
    *   **7 (1st + 2nd + 3rd):** If spectrogram shows a 3rd peak.
    *   **5 (1st + 3rd):** Sometimes useful for specific props.
    *   **127 (All):** Don't do this.