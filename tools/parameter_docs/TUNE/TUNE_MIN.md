---
layout: parameter
name: TUNE_MIN
display_name: Tuning minimum
description: Transmitter Tuning minimum value.
default_value: 0
range: 
units: 
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L911
---

# TUNE_MIN: Tuning minimum

## Description
Transmitter Tuning minimum value. The parameter being tuned will have its value set to this minimum value when the tuning knob is at its lowest position.

## Values
- **Default:** 0

## Description
This parameter works with the "In-Flight Tuning" feature (usually assigned to Channel 6).

- **Function:** When you rotate your transmitter's tuning knob to its minimum position, the parameter you have selected in `TUNE` will be set to this value (`TUNE_MIN`).
- **Example:** If you are tuning `PSC_POSXY_P`, and you set `TUNE_MIN = 0.5` and `TUNE_MAX = 2.0`, rotating the knob fully counter-clockwise sets P to 0.5.

