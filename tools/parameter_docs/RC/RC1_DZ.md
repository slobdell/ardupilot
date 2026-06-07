---
layout: parameter
name: RC1_DZ
display_name: RC Input Channel 1 Deadzone
description: The PWM deadzone around the trim (center) position for Channel 1.
default_value: 30
range: 0 200
units: PWM
group: RC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L91
---

# RC Input Channel 1 Deadzone (RC1_DZ)

## Description
`RC1_DZ` creates a small "Null Zone" in the center of your stick. If the PWM signal changes by less than this amount, the autopilot ignores it. This prevents "Stick Jitter" or poor stick centering from causing the drone to twitch or drift.