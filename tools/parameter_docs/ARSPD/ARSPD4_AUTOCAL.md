---
alias_target: ARSPD_AUTOCAL
default_value: 0
description: Enables automatic adjustment of airspeed ratio during a calibration flight
  based on estimation of ground speed and true airspeed. New ratio saved every 2 minutes
  if change is > 5%. Should not be left enabled.
display_name: Automatic airspeed ratio calibration
group: ARSPD
investigation_status: alias
layout: parameter
name: ARSPD4_AUTOCAL
range: null
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Airspeed/AP_Airspeed_Params.cpp#L90
units: ''
visual_asset_id: null
---

# Automatic airspeed ratio calibration

**Note:** This parameter functions identically to [ARSPD_AUTOCAL](../ARSPD/ARSPD_AUTOCAL.html).
