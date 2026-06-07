---
layout: parameter
name: LOAD_FILT
display_name: Load test filter
description: This filters the load test output. A value of 1 means no filter. 2 means values are repeated once. 3 means values are repeated 3 times, etc.
default_value: 1
range: 0 100
units: 
group: LOAD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L166
---

# LOAD_FILT: Load test filter

## Description
This filters the load test output. A value of 1 means no filter. 2 means values are repeated once. 3 means values are repeated 3 times, etc.

## Values
- **Range:** 0 to 100
- **Default:** 1

## Description
This parameter is part of the **Toy Mode** motor load testing suite (used primarily for factory endurance testing). It acts as a simple low-pass filter by holding each output value for multiple cycles.

- **1:** Updates motor output every cycle (No filtering).
- **>1:** Holds the motor output constant for this many cycles before updating to the next value in the test sequence. This smooths out rapid changes in the load test profile.

## Source Code
[ardupilot/ArduCopter/toy_mode.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L166)

