---
alias_target: LEAK1_TYPE
default_value: DISABLED
description: Enables leak detector 3. Use this parameter to indicate the signal type
  (0:analog, 1:digital) of an appropriately configured input pin, then specify its
  pin number using the LEAK3_PIN parameter. NOT FOR USE by default with Pixhawk, Pixhawk
  4 or Navigator flight controllers.
display_name: Leak detector pin type (analog/digital)
group: LEAK
investigation_status: alias
layout: parameter
name: LEAK3_TYPE
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LeakDetector/AP_LeakDetector.cpp#L77
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LeakDetector/AP_LeakDetector.h#L53
units: ''
visual_asset_id: null
---

# Leak detector pin type (analog/digital)

**Note:** This parameter functions identically to [LEAK1_TYPE](../LEAK/LEAK1_TYPE.html).
