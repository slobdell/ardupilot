---
alias_target: SERVO1_TRIM
default_value: 1500
description: Trim PWM pulse width in microseconds. Typically 1000 is lower limit,
  1500 is neutral and 2000 is upper limit.
display_name: Trim PWM
group: SERVO
investigation_status: alias
layout: parameter
name: SERVO3_TRIM
range: 800 2200
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.cpp#L55
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.h#L247
units: PWM
visual_asset_id: null
---

# Trim PWM

**Note:** This parameter functions identically to [SERVO1_TRIM](../SERVO/SERVO1_TRIM.html).
