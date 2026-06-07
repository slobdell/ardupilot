---
layout: parameter
name: WNDVN_TRUE_FILT
display_name: True Wind Data Low-Pass Filter
description: Cutoff frequency for the filter applied to the calculated True Wind (global frame) speed and direction.
default_value: 0.05
range: 0 10
units: Hz
group: WNDVN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WindVane/AP_WindVane.cpp#L100
---

# True Wind Data Low-Pass Filter (WNDVN_TRUE_FILT)

## Description
`WNDVN_TRUE_FILT` smooths the "Global" wind estimate.

Unlike apparent wind (what the drone feels while moving), **True Wind** is the actual wind speed and direction relative to the ground. It is calculated by combining apparent wind data with the drone's own velocity and heading. This calculation is prone to errors during turns. This very slow filter (default 0.05 Hz) ensures that the drone builds a stable long-term estimate of the real wind conditions.

## Tuning & Behavior
*   **Default:** 0.05 Hz (Very Slow).
*   **Significance:** It takes about 20 seconds for a change in the real wind to be fully reflected in the "True Wind" estimate. This prevent's the drone's own movements from "polluting" the wind estimate.