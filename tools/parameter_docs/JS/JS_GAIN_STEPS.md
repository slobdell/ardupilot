---
layout: parameter
name: JS_GAIN_STEPS
display_name: Joystick Gain Steps
description: The number of increments (steps) used when increasing or decreasing joystick sensitivity.
default_value: 4
range: 1 10
units: Steps
group: JS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L259
---

# Joystick Gain Steps (JS_GAIN_STEPS)

## Description
`JS_GAIN_STEPS` determines how many times you have to click a button to go from [JS_GAIN_MIN](JS_GAIN_MIN.html) to [JS_GAIN_MAX](JS_GAIN_MAX.html).

It sets the "Resolution" of the in-flight gain adjustment.
*   **Default:** 4 steps. (e.g., 25%, 50%, 75%, 100%).
*   **Usage:** Increase this if you want finer control over your vehicle's speed and responsiveness during a mission.