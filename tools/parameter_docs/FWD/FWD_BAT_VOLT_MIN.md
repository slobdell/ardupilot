---
layout: parameter
name: FWD_BAT_VOLT_MIN
display_name: Forward Battery Voltage Min
description: Minimum voltage of the battery used for forward thrust.
default_value: 0
range: 0 100
units: V
group: FWD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp
---

# Forward Battery Voltage Min (FWD_BAT_VOLT_MIN)

## Description
Defines the "empty battery" voltage for the forward propulsion system. Used in conjunction with FWD_BAT_VOLT_MAX for throttle scaling.