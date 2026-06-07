---
layout: parameter
name: WNDVN_DIR_FILT
display_name: Wind Vane Direction Filter
description: Low-pass filter frequency for the apparent wind direction data.
default_value: 0.5
range: -1.0 10.0
units: Hz
group: WNDVN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L89
---

# Wind Vane Direction Filter (WNDVN_DIR_FILT)

## Description
`WNDVN_DIR_FILT` smooths the raw data coming from the wind vane. 

Wind is naturally turbulent, and physical vanes tend to "jitter" or bounce rapidly. This filter removes that high-frequency noise, providing a stable "Apparent Wind" direction for the autopilot to use for sail trimming.

*   **Higher Frequency (e.g. 2.0 Hz):** More responsive to quick wind shifts, but "nervous" sails.
*   **Lower Frequency (e.g. 0.1 Hz):** Very smooth sail movement, but may be too slow to react to real gusts.
*   **-1:** Disables the filter (Not recommended).

## Tuning & Behavior
*   **Default:** 0.5 Hz.
*   **Recommendation:** Leave at **0.5 Hz**. If your sail servos are constantly twitching, reduce this value to **0.2 Hz**.