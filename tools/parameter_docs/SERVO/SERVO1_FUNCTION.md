---
layout: parameter
name: SERVO1_FUNCTION
display_name: Servo 1 Output Function
description: Assigns a specific control role (e.g., Motor 1, Aileron, RCPassThru) to physical Output 1.
default_value: 0
range: 0 300
units: 
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.cpp#L161
---

# Servo 1 Output Function (SERVO1_FUNCTION)

## Description
`SERVO1_FUNCTION` tells the autopilot what is physically plugged into the first output pin on your flight controller.

By default, pins do nothing. You must assign a function to each pin so the autopilot knows where to send the motor commands, steering signals, or auxiliary triggers.

## Common Values
*   **0: Disabled.** Output remains at neutral/off.
*   **33-40: Motor 1 - Motor 8.** (Standard multicopter motor mapping).
*   **4: Aileron.** (Fixed-wing).
*   **19: Elevator.** (Fixed-wing).
*   **21: Rudder.** (Fixed-wing).
*   **51-66: RCIN Passthrough.** Directly mirrors the signal from an RC channel.
*   **120+: Relay.** Simple digital ON/OFF control.

## Tuning & Behavior
*   **Default:** 0.
*   **Safety:** Never change these values while a battery is connected and propellers are attached. A change in function can cause a motor to spin up unexpectedly.
*   **Redundancy:** You can assign the same function to multiple pins (e.g., two pins set to "Aileron") if you have dual servos on a single control surface.