---
alias_target: RC1_TRIM
default_value: 1500
description: RC trim (neutral) PWM pulse width in microseconds. Typically 1000 is
  lower limit, 1500 is neutral and 2000 is upper limit.
display_name: RC trim PWM
group: RC
investigation_status: alias
layout: parameter
name: RC9_TRIM
range: 800 2200
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L82
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.h#L94
units: PWM
visual_asset_id: null
---

# RC trim PWM

**Note:** This parameter functions identically to [RC1_TRIM](../RC/RC1_TRIM.html).
