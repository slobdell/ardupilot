---
alias_target: RC1_MAX
default_value: 1900
description: RC maximum PWM pulse width in microseconds. Typically 1000 is lower limit,
  1500 is neutral and 2000 is upper limit.
display_name: RC max PWM
group: RC
investigation_status: alias
layout: parameter
name: RC2_MAX
range: 800 2200
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L91
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.h#L92
units: PWM
visual_asset_id: null
---

# RC max PWM

**Note:** This parameter functions identically to [RC1_MAX](../RC/RC1_MAX.html).
