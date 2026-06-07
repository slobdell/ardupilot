---
alias_target: ARSPD_USE
default_value: 0
description: Enables airspeed use for automatic throttle modes and replaces control
  from THR_TRIM. Continues to display and log airspeed if set to 0. Uses airspeed
  for control if set to 1. Only uses airspeed when throttle = 0 if set to 2 (useful
  for gliders with airspeed sensors behind propellers).
display_name: Airspeed use
group: ARSPD
investigation_status: alias
layout: parameter
name: ARSPD2_USE
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp#L60
units: ''
visual_asset_id: null
---

# Airspeed use

**Note:** This parameter functions identically to [ARSPD_USE](../ARSPD/ARSPD_USE.html).
