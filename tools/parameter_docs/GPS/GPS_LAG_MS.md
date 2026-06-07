---
layout: parameter
name: GPS_LAG_MS
display_name: User-defined delay
description: Manual override for the processing and transmission delay of the GPS sensor.
default_value: 0
range: 0 250
units: ms
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp
---

# User-defined delay (GPS_LAG_MS)

## Description
Allows the user to manually specify the latency of the GPS data. If set to 0, ArduPilot will use a hardcoded delay based on the detected GPS type.