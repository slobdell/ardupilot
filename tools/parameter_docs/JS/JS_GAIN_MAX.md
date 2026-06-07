---
layout: parameter
name: JS_GAIN_MAX
display_name: Joystick Maximum Gain
description: The upper limit for joystick sensitivity adjustments.
default_value: 1.0
range: 0.1 1.0
units: 
group: JS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L245
---

# Joystick Maximum Gain (JS_GAIN_MAX)

## Description
`JS_GAIN_MAX` sets the upper boundary for the real-time gain adjustment feature.

In many applications (like ROVs), pilots use joystick buttons to "Turn up" or "Turn down" the sensitivity during a mission. This parameter ensures that even if you click the "Increase Gain" button many times, the sensitivity will never exceed this safe limit.

## Tuning & Behavior
*   **Default:** 1.0 (Allow full 100% sensitivity).
*   **Safety:** If you find that the vehicle is dangerously fast or unstable at 100% gain, reduce this value to **0.8** or **0.7** to "Cap" the maximum performance.