---
layout: parameter
name: TMODE_LOAD_MUL
display_name: Load test multiplier
description: This scales the load test output, as a value between 0 and 1.
default_value: 1.0
range: 0 1
units: 
group: TMODE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L159
---

# TMODE_LOAD_MUL: Load test multiplier

## Description
This scales the load test output, as a value between 0 and 1.

## Values
- **Range:** 0 to 1
- **Default:** 1.0

## Description
This parameter is part of the **Toy Mode** factory test suite (`ENABLE_LOAD_TEST` must be compiled in).

- **Function:** It multiplies the motor PWM output during the automated load test sequence.
- **Usage:** Used to run the motors at a reduced power level (e.g., **0.5**) during endurance testing to verify battery life or thermal performance without running at full hover power.

