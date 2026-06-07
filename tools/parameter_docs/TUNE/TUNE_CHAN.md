---
layout: parameter
name: TUNE_CHAN
display_name: Transmitter Tuning Channel
description: Selects the RC channel connected to a knob or slider used for in-flight parameter tuning.
default_value: 0
range: 0 16
units: 
group: TUNE
visual_asset_id: radio_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Tuning/AP_Tuning.cpp#L19
---

# Transmitter Tuning Channel (TUNE_CHAN)

## Description
`TUNE_CHAN` enables you to tune your drone's PIDs or other parameters while you are actually flying, using a knob or slider on your transmitter.

Instead of landing, changing a parameter, and taking off again, you can map a knob to a parameter (e.g., Roll P) and find the perfect value by turning the knob in mid-air.

*   **0:** Disabled.
*   **5-16:** RC Channel number.

## Tuning & Behavior
*   **Prerequisite:** You must also set [TUNE_CHAN_MIN](TUNE_CHAN_MIN.html) and [TUNE_CHAN_MAX](TUNE_CHAN_MAX.html) to match the output of your knob.
*   **Safety:** Always start with a small [TUNE_RANGE](TUNE_RANGE.html) to avoid making the drone unstable with a small turn of the knob.