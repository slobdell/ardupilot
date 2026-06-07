---
layout: parameter
name: TUNE_RANGE
display_name: Transmitter Tuning Range
description: Defines the multiplier for the parameter being tuned. A value of 2.0 means the parameter can be adjusted from 0.5x to 2.0x its starting value.
default_value: 2.0
range: 1.1 5.0
units: 
group: TUNE
visual_asset_id: radio_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Tuning/AP_Tuning.cpp#L41
---

# Transmitter Tuning Range (TUNE_RANGE)

## Description
`TUNE_RANGE` sets the "Sensitivity" of the tuning knob.

It defines the total spread of values the knob can command, centered around the value the parameter had when the tuning session started.

*   **2.0 (Default):** The knob can adjust the parameter from half of its original value (at the low end) to double its original value (at the high end).
*   **1.2:** A much smaller range, allowing for very fine control and reducing the risk of a crash.

## Tuning & Behavior
*   **Recommendation:** Start with **1.2 or 1.5** for high-risk parameters like PID gains. Use **2.0** for less sensitive settings.