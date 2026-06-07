---
layout: parameter
name: MOT_SAFE_TIME
display_name: Motor PWM Safety Transition Time
description: The delay (in seconds) for enabling or disabling motor output signals during arming/disarming.
default_value: 0.1
range: 0 5.0
units: s
group: MOT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L216
---

# Motor PWM Safety Transition Time (MOT_SAFE_TIME)

## Description
`MOT_SAFE_TIME` defines a short buffer period when the drone's output signal is transitioning between "Safe" (Disarmed) and "Live" (Armed) states. 

This delay ensures that the ESCs and other hardware have a consistent signal before the drone attempts to apply flight power. It helps prevent "Twitches" or unexpected motor jumps the moment the arming switch is toggled.

## Tuning & Behavior
*   **Default:** 0.1 seconds.
*   **Safety:** This is a low-level hardware safety parameter. It is recommended to leave it at the default setting unless you have specialized ESCs that require more time to synchronize.