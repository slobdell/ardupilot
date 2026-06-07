---
layout: parameter
name: SERVO1_REVERSED
display_name: Servo 1 Reversal
description: Reverses the direction of movement for physical Output 1.
default_value: 0
range: 0 1
units: 
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.cpp#L62
---

# Servo 1 Reversal (SERVO1_REVERSED)

## Description
`SERVO1_REVERSED` allows you to flip the direction of a motor or servo output without swapping wires. 

If you move your transmitter stick right, but the drone rolls left, you can use this parameter to correct the behavior. This is safer than reversing the channel on your transmitter, as it ensures that the autopilot's internal stabilization logic also moves in the correct direction.

*   **0: Normal.**
*   **1: Reversed.**

## Tuning & Behavior
*   **Safety:** Always verify your control surface directions on the ground before taking off. 
*   **Motors:** For DShot motors, it is usually better to reverse the direction in the ESC firmware (using BLHeliSuite), but this parameter can also be used for simple reversals.