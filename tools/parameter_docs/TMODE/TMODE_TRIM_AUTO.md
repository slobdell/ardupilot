---
layout: parameter
name: TMODE_TRIM_AUTO
display_name: Toy Mode Auto Stick Trim
description: The maximum allowed PWM offset for automatic stick re-centering while disarmed.
default_value: 50
range: 0 100
units: PWM
group: TMODE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/toy_mode.cpp#L104
---

# Toy Mode Auto Stick Trim (TMODE_TRIM_AUTO)

## Description
`TMODE_TRIM_AUTO` is a convenience feature for consumer drones using low-cost transmitters (RC controllers).

Cheap transmitters often have "Drift" in their gimbal sticks – the center point might not be exactly 1500 PWM every time. In Toy Mode, while the vehicle is **Disarmed**, the autopilot monitors the sticks. If they are near the center and remain steady for several seconds, the autopilot assumes that position is the intended "Neutral" and applies a small trim offset automatically.

## Tuning & Behavior
*   **Default:** 50 PWM.
*   **Safety:** This only happens while disarmed. If the stick is too far from center (more than this parameter's value), the autopilot will NOT apply the trim, assuming you are intentionally holding the stick.
*   **Benefit:** Prevents the drone from slowly drifting in one direction just because your transmitter's potentiometers are slightly aged or imprecise.