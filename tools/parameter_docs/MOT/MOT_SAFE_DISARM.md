---
layout: parameter
name: MOT_SAFE_DISARM
display_name: Motor PWM output disabled when disarmed
description: Controls whether PWM signals are sent to the ESCs while the vehicle is disarmed.
default_value: 0
range: 0 1
units: 
group: MOT
visual_asset_id: mot_safe_disarm_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L162
---

# Motor PWM output disabled when disarmed (MOT_SAFE_DISARM)

## Description
`MOT_SAFE_DISARM` adds an extra layer of safety on the ground.

*   **0 (Default):** The flight controller sends a "Min PWM" (e.g. 1000us) signal to the ESCs even when disarmed. This keeps the ESCs initialized and ready.
*   **1 (Safe):** The flight controller stops sending *any* signal to the motors when disarmed. 

## The Engineer's View
Some ESCs will beep annoyingly if they don't receive a signal. However, stopping the signal ensures that a glitch (or a user bumping the throttle stick on a non-ArduPilot system) cannot spin the props.
For DShot, this parameter might stop the packet stream entirely.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:** Leave at **0** for most ESCs to prevent them from entering "Programming Mode" or beeping.
*   **Safety:** If your ESCs support it, setting this to **1** prevents accidental spin-ups.