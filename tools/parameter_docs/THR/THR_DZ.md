---
layout: parameter
name: THR_DZ
display_name: Throttle Deadzone
description: Deadzone around the center stick position for altitude-controlled modes.
default_value: 30
range: 0 300
units: PWM
group: THR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp
---

# Throttle Deadzone (THR_DZ)

## Description
`THR_DZ` defines the "Idle Area" in the middle of your throttle stick when flying in modes like **AltHold**, **Loiter**, or **PosHold**. 

In these modes, the autopilot tries to maintain a steady altitude. When the stick is near the center, the drone holds its height. If you push the stick above or below this deadzone, the drone starts to climb or descend. `THR_DZ` ensures that tiny movements or "jitter" in your transmitter sticks don't cause the drone to slowly drift up or down.

## Tuning & Behavior
*   **Default:** 30 PWM (e.g. if center is 1500, the deadzone is 1470 to 1530).
*   **Recommendation:** If your drone starts climbing or falling the moment you let go of the stick, increase this value to **40** or **50**.
*   **Physics:** This parameter only affects stick input interpretation; it does not change the motor's physical response.