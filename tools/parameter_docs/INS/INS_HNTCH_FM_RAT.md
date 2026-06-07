---
layout: parameter
name: INS_HNTCH_FM_RAT
display_name: Throttle notch min freqency ratio
description: Sets the lower floor for the notch frequency as a percentage of the base frequency.
default_value: 1.0
range: 0.1 1.0
units: 
group: INS
visual_asset_id: ins_hntch_fm_rat_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/Filter/HarmonicNotchFilter.cpp#L120
---

# Throttle notch min freqency ratio (INS_HNTCH_FM_RAT)

## Description
`INS_HNTCH_FM_RAT` prevents the filter frequency from dropping too low when you lower the throttle.

*   **1.0 (Default):** The filter never drops below `INS_HNTCH_FREQ`.
*   **< 1.0:** The filter can drop to `FREQ * FM_RAT`.

This is important because filtering at very low frequencies (e.g., < 40Hz) introduces massive phase lag (delay) that can destabilize the drone.

## The Mathematics
$$ f_{min\_limit} = \text{INS\_HNTCH\_FREQ} \times \text{INS\_HNTCH\_FM\_RAT} $$
$$ f_{actual} = \max(f_{calculated}, f_{min\_limit}) $$

## The Engineer's View
Used in `HarmonicNotchFilter::update()`.
It clamps the lower bound of the center frequency.

## Tuning & Behavior
*   **Default Value:** 1.0
*   **Range:** 0.1 - 1.0
*   **Recommendation:** Leave at **1.0** if using Throttle Reference.
*   **Exception:** If you set `INS_HNTCH_FREQ` to your *hover* frequency (Throttle Mode), you might want to allow the filter to drop slightly during descent (low throttle). Set to **0.7** to allow it to track down to 70% of hover RPM.