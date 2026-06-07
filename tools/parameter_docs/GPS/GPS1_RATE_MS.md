---
alias_target: GPS_RATE_MS
default_value: 100
description: NMEA Output rate. This controls the interval at which all the enabled
  NMEA messages are sent. Most NMEA systems expect 100ms (10Hz) or slower.
display_name: NMEA Output rate
group: GPS
investigation_status: alias
layout: parameter
name: GPS1_RATE_MS
range: 20 2000
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NMEA_Output/AP_NMEA_Output.cpp#L57
- https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_NMEA_Output/AP_NMEA_Output.h#L63
units: ms
visual_asset_id: null
---

# NMEA Output rate

**Note:** This parameter functions identically to [GPS_RATE_MS](../GPS/GPS_RATE_MS.html).
