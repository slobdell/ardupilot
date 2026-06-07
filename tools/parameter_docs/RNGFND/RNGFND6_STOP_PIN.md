---
alias_target: RNGFND1_STOP_PIN
default_value: -1
description: Digital pin that enables/disables rangefinder measurement for the pwm
  rangefinder. A value of -1 means no pin. If this is set, then the pin is set to
  1 to enable the rangefinder and set to 0 to disable it. This is used to enable powersaving
  when out of range. Some common values are given, but see the Wiki's "GPIOs" page
  for how to determine the pin number for a given autopilot.
display_name: Rangefinder stop pin
group: RNGFND
investigation_status: alias
layout: parameter
name: RNGFND6_STOP_PIN
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.cpp#L73
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_RangeFinder/AP_RangeFinder_Params.h#L28
units: ''
visual_asset_id: null
---

# Rangefinder stop pin

**Note:** This parameter functions identically to [RNGFND1_STOP_PIN](../RNGFND/RNGFND1_STOP_PIN.html).
