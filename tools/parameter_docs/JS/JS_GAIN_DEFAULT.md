---
layout: parameter
name: JS_GAIN_DEFAULT
display_name: Joystick Default Gain
description: The initial sensitivity (gain) for joystick control when the vehicle boots.
default_value: 0.5
range: 0.1 1.0
units: 
group: JS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduSub/Parameters.cpp#L238
---

# Joystick Default Gain (JS_GAIN_DEFAULT)

## Description
`JS_GAIN_DEFAULT` defines the "Responsiveness" of the vehicle when using a USB joystick (most common in **ArduSub** ROV applications). 

It acts as a master multiplier for all control sticks. 

*   **0.5 (Default):** 50% sensitivity. Moving the stick all the way only commands 50% power. This is excellent for beginners or precision maneuvering.
*   **1.0:** 100% sensitivity. Full stick movement commands full power.

## Tuning & Behavior
*   **Default:** 0.5.
*   **Usage:** If you find the vehicle is too "twitchy" or difficult to control smoothly at boot, decrease this value. If you always find yourself needing more speed, increase it.
*   **Live Adjustment:** In ArduSub, this gain is often adjusted in real-time during a dive using buttons on the joystick, but it will revert to this default value when the vehicle is rebooted.