---
layout: parameter
name: JS_GAIN_MIN
display_name: Joystick Minimum Gain
description: The lower limit for joystick sensitivity adjustments.
default_value: 0.25
range: 0.1 0.8
units: 
group: JS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L252
---

# Joystick Minimum Gain (JS_GAIN_MIN)

## Description
`JS_GAIN_MIN` sets the lower boundary for the real-time gain adjustment feature.

This ensures that even if you click the "Decrease Gain" button many times, the vehicle's sensitivity will never drop so low that it becomes unresponsive. This prevents a pilot from accidentally "Disabling" their controls while trying to slow down for precision work.

## Tuning & Behavior
*   **Default:** 0.25 (Minimum 25% sensitivity).
*   **Usage:** If you need extremely fine precision (e.g. using a robotic arm on an ROV), you might lower this to **0.1** (10%).