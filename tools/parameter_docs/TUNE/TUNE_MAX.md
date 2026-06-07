---
layout: parameter
name: TUNE_MAX
display_name: Tuning maximum
description: Transmitter Tuning maximum value.
default_value: 0
range: 
units: 
group: TUNE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L917
---

# TUNE_MAX: Tuning maximum

## Description
Transmitter Tuning maximum value. The parameter being tuned will have its value set to this maximum value when the tuning knob is at its highest position.

## Values
- **Default:** 0

## Description
This parameter works with the "In-Flight Tuning" feature.

- **Function:** When you rotate your transmitter's tuning knob to its maximum position, the parameter you have selected in `TUNE` will be set to this value (`TUNE_MAX`).
- **Example:** If tuning `PSC_POSXY_P` and you want to test P-gains up to 2.0, set `TUNE_MAX = 2.0`.

