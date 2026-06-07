---
alias_target: RC1_MIN
default_value: 1100
description: RC minimum PWM pulse width in microseconds. Typically 1000 is lower limit,
  1500 is neutral and 2000 is upper limit.
display_name: RC min PWM
group: RC
investigation_status: alias
layout: parameter
name: RC4_MIN
range: 800 2200
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L73
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.h#L90
units: PWM
visual_asset_id: null
---

# RC min PWM

**Note:** This parameter functions identically to [RC1_MIN](../RC/RC1_MIN.html).
