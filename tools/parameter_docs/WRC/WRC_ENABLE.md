---
layout: parameter
name: WRC_ENABLE
display_name: Wheel Rate Control Enable
description: Enables the PID controller for wheel rotation speed.
default_value: 0
range: 0 1
units: 
group: WRC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_WheelEncoder/AP_WheelRateControl.cpp#L11
---

# Wheel Rate Control Enable (WRC_ENABLE)

## Description
`WRC_ENABLE` activates the closed-loop speed controller for a Rover's wheels.

Standard Rovers often use "Open-Loop" control – if you command 50% throttle, the autopilot sends 1500 PWM to the ESC. With **Wheel Rate Control**, the autopilot uses sensors (Wheel Encoders) to measure exactly how fast the wheels are turning and adjusts the throttle in real-time to maintain the requested speed, even when driving over uneven terrain or up hills.

## Tuning & Behavior
*   **Default:** 0 (Disabled).
*   **Requirement:** Requires functional wheel encoders ([WENC_TYPE](WENC_TYPE.html)).
*   **Benefit:** Dramatically improves speed consistency and navigation accuracy for ground vehicles.