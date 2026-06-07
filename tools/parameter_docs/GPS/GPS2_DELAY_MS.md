---
alias_target: GPS1_DELAY_MS
default_value: 0
description: Controls the amount of GPS  measurement delay that the autopilot compensates
  for. Set to zero to use the default delay for the detected GPS type.
display_name: GPS delay in milliseconds
group: GPS
investigation_status: alias
layout: parameter
name: GPS2_DELAY_MS
range: 0 250
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp#L81
units: ms
visual_asset_id: null
---

# GPS delay in milliseconds

**Note:** This parameter functions identically to [GPS1_DELAY_MS](../GPS/GPS1_DELAY_MS.html).
