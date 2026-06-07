---
layout: parameter
name: INS_HNTCH_ATT
display_name: Harmonic Notch Filter attenuation
description: The depth of the notch filter in Decibels (dB).
default_value: 40
range: 5 50
units: dB
group: INS
visual_asset_id: ins_hntch_att_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L70
---

# Harmonic Notch Filter attenuation (INS_HNTCH_ATT)

## Description
`INS_HNTCH_ATT` sets how "deep" the cut is. A higher dB value means more noise removal.

*   **15-20 dB:** Mild filtering. Good for slightly noisy frames.
*   **40 dB (Default):** Deep filtering. Removes almost 99% of the noise at the center frequency.
*   **> 40 dB:** Very sharp, deep notch. Can cause phase issues if the bandwidth is too narrow.

## The Mathematics
Attenuation $A$ determines the filter coefficient calculations.
$$ \text{Gain} = 10^{-A/20} $$
At 40dB, the gain at the center frequency is $0.01$.

## The Engineer's View
Used in `NotchFilter::calculate_A_and_Q`.
Higher attenuation increases the "sharpness" of the phase transition around the notch.

## Tuning & Behavior
*   **Default Value:** 40 dB
*   **Recommendation:** Default is usually fine.
    *   If the filter is causing latency issues (oscillations), try reducing this to 20 or 30 dB.
    *   If noise is still getting through, increasing this rarely helps; instead, increase `INS_HNTCH_BW` (Bandwidth).