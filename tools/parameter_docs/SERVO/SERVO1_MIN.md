---
layout: parameter
name: SERVO1_MIN
display_name: Servo 1 Minimum
description: The minimum PWM value for Output 1.
default_value: 1100
range: 800 2200
units: PWM
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.cpp#L37
---

# Servo 1 Minimum (SERVO1_MIN)

## Description
`SERVO1_MIN` sets the "Lower Limit" for a servo or ESC. 

It defines the shortest pulse width that the autopilot will ever send to this pin. This is used to prevent a servo from trying to push past a physical wall or to set the "Off" point for an ESC.

*   **Standard Setting:** 1100 (µs).
*   **Safety:** Ensure that at this setting, the servo is not "stalling" (making a buzzing sound) against a mechanical limit.