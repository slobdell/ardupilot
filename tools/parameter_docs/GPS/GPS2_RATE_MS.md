---
alias_target: GPS_RATE_MS
default_value: 200
description: Controls how often the GPS should provide a position update. Lowering
  below 5Hz(default) is not allowed. Raising the rate above 5Hz usually provides little
  benefit and for some GPS (eg Ublox M9N) can severely impact performance.
display_name: GPS update rate in milliseconds
group: GPS
investigation_status: alias
layout: parameter
name: GPS2_RATE_MS
range: 50 200
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp#L47
units: ms
visual_asset_id: null
---

# GPS update rate in milliseconds

**Note:** This parameter functions identically to [GPS_RATE_MS](../GPS/GPS_RATE_MS.html).
