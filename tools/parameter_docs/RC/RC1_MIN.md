---
layout: parameter
name: RC1_MIN
display_name: RC Input Channel 1 Minimum
description: The minimum PWM value received from Channel 1 (typically full left/down).
default_value: 1100
range: 800 2200
units: PWM
group: RC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L64
---

# RC Input Channel 1 Minimum (RC1_MIN)

## Description
`RC1_MIN` defines the lowest PWM value your transmitter sends on the first channel. This is calibrated automatically and ensures the autopilot knows the full physical range of your stick movement.