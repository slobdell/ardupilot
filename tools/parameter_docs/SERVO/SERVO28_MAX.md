---
alias_target: SERVO1_MAX
default_value: 1900
description: maximum PWM pulse width in microseconds. Typically 1000 is lower limit,
  1500 is neutral and 2000 is upper limit.
display_name: Maximum PWM
group: SERVO
investigation_status: alias
layout: parameter
name: SERVO28_MAX
range: 800 2200
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.cpp#L46
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.h#L236
units: PWM
visual_asset_id: null
---

# Maximum PWM

**Note:** This parameter functions identically to [SERVO1_MAX](../SERVO/SERVO1_MAX.html).
