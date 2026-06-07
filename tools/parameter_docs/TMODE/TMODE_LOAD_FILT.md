---
layout: parameter
name: TMODE_LOAD_FILT
display_name: Toy Mode Load Test Filter
description: Determines the "Sample Rate" or repetition of thrust commands during a load test.
default_value: 1
range: 0 100
units: 
group: TMODE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/toy_mode.cpp#L166
---

# Toy Mode Load Test Filter (TMODE_LOAD_FILT)

## Description
`TMODE_LOAD_FILT` controls the temporal resolution of thrust commands during a Toy Mode Load Test.

Instead of applying a new thrust value on every loop, this parameter "stretches" each value.
*   **1:** No filtering. Commands are applied at the full loop rate.
*   **X:** Each thrust value from the test sequence is repeated X times. 

## Tuning & Behavior
*   **Default:** 1.
*   **Usage:** Used to slow down the rate of change during battery stress tests to see how the voltage recovers between steps.
*   **Context:** Only applicable when [TMODE_LOAD_TYPE](TMODE_LOAD_TYPE.html) is set to a Log Replay mode.