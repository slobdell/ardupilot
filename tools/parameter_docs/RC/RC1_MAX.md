---
layout: parameter
name: RC1_MAX
display_name: RC Input Channel 1 Maximum
description: The maximum PWM value received from Channel 1 (typically full right/up).
default_value: 1900
range: 800 2200
units: PWM
group: RC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L73
---

# RC Input Channel 1 Maximum (RC1_MAX)

## Description
`RC1_MAX` defines the highest PWM value your transmitter sends on the first channel. This is used to scale your stick inputs so that "Full Stick" equals "Maximum Demand" in the flight code.