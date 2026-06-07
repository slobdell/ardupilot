---
layout: parameter
name: AUTO_KICKSTART
display_name: Auto Kickstart Acceleration
description: The acceleration threshold (in m/s/s) required to trigger the motor start when in AUTO mode.
default_value: 0
range: 0 20.0
units: m/s/s
group: AUTO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp#L81
---

# Auto Kickstart Acceleration (AUTO_KICKSTART)

## Description
`AUTO_KICKSTART` allows you to delay the start of an autonomous mission until the vehicle is physically pushed or launched.

Normally, when you switch to AUTO mode, the vehicle starts its mission immediately. If you set this parameter to a value like **2.0**, the vehicle will sit still until it detects an acceleration of 2.0 m/s/s (a firm push). This is useful for starting missions where you want to manually launch the rover or ensuring the motors only start once the vehicle is on its way.

*   **0 (Default):** Mission starts immediately upon entering AUTO mode.
*   **Value:** Acceleration threshold to trigger the start.

## Tuning & Behavior
*   **Usage:** Common in racing rovers or hand-launched small vehicles where a "Push-to-Start" behavior is desired for safety or convenience.