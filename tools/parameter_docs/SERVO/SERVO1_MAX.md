---
layout: parameter
name: SERVO1_MAX
display_name: Servo 1 Maximum
description: The maximum PWM value for Output 1.
default_value: 1900
range: 800 2200
units: PWM
group: SERVO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channel.cpp#L46
---

# Servo 1 Maximum (SERVO1_MAX)

## Description
`SERVO1_MAX` sets the "Upper Limit" for a servo or ESC. 

It defines the longest pulse width that the autopilot will ever send to this pin. 

*   **Standard Setting:** 1900 (µs).
*   **Recommendation:** Match this to the physical limit of your aircraft's hardware to prevent mechanical binding.