---
layout: parameter
name: BARO_FLTR_RNG
display_name: "Filter Range"
description: "Range around the average value that new samples must be within to be accepted."
default_value: 0
range: 0 100
units: "%"
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L175
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Filter Range (BARO_FLTR_RNG)

## Description
This parameter acts as a "Noise Gate" for barometric pressure samples. It defines a percentage-based threshold around the current moving average. Any new pressure reading that falls outside of this window is rejected as "glitchy" noise and ignored.

This is extremely useful for protecting the altitude estimate from electromagnetic interference (EMI) or voltage spikes on the I2C bus, which can cause sudden, unrealistic jumps in pressure readings.

## The Mathematics
A sample ($P_{new}$) is only accepted if it is within $\pm X\%$ of the current smoothed average ($P_{avg}$):

$$ |P_{new} - P_{avg}| \le P_{avg} \times \frac{BARO\_FLTR\_RNG}{100} $$

If the new sample is outside this range, the system discards it and waits for the next sample.

## The Engineer's View
In `AP_Baro.cpp`, this parameter maps to `_filter_range`.
It is primarily used in sensor backends (like `AP_Baro_MS56XX.cpp` or `AP_Baro_BMP280.cpp`) to validate raw pressure data before it enters the altitude conversion logic. 
*   **0 (Default):** Disables the check. All samples are accepted.
*   **Setting it too tight:** Can cause the barometer to "freeze" during rapid climbs or descents because the actual pressure change is faster than the allowed window.

## Tuning & Behavior
*   **Default Value:** 0 (Filter disabled).
*   **Recommended Value:** If you experience altitude "glitches" or sudden jumps, try a value of **10** (10% window). 
*   **Symptom of too Low:** Barometric altitude stops updating during high-performance maneuvers.
*   **Symptom of too High:** The sensor remains sensitive to electrical noise spikes.

