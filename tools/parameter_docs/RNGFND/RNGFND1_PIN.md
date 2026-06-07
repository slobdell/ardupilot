---
layout: parameter
name: RNGFND1_PIN
display_name: Rangefinder Pin
description: The analog pin that the rangefinder is connected to.
default_value: -1
range: -1 100
units: 
group: RNGFND
visual_asset_id: rngfnd_pin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L32
---

# Rangefinder Pin (RNGFND1_PIN)

## Description
`RNGFND1_PIN` sets the Analog Input pin used for **Analog** rangefinders (Type 1).

*   **-1: Not used.**
*   **0-9: Analog Pin Number.** (e.g. 0 for A0).
*   **Note:** This parameter is only relevant if `RNGFND1_TYPE` = 1.

## Tuning & Behavior
*   **Default:** -1