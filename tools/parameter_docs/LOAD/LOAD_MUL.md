---
layout: parameter
name: LOAD_MUL
display_name: Load test multiplier
description: This scales the load test output, as a value between 0 and 1.
default_value: 1.0
range: 0 1
units: 
group: LOAD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L159
---

# LOAD_MUL: Load test multiplier

## Description
This scales the load test output, as a value between 0 and 1.

## Values
- **Range:** 0 to 1
- **Increment:** 0.01
- **Default:** 1.0

## Description
This parameter controls the overall intensity of the motor load test.

- **Usage:** It multiplies the PWM values defined in the test pattern (`LOAD_TYPE`) by this factor.
- **Example:** Setting this to 0.5 reduces the power output of the entire test sequence by 50%, useful for running initial tests without stressing the hardware to its maximum.

## Source Code
[ardupilot/ArduCopter/toy_mode.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L159)

