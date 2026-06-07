---
layout: parameter
name: GPS_PRIMARY
display_name: Primary GPS
description: Selects the default primary GPS instance.
default_value: 0
range: 0 1
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# Primary GPS (GPS_PRIMARY)

## Description
Determines which GPS module (1st or 2nd) is treated as the primary source when GPS_AUTO_SWITCH is disabled or in specific priority modes.
*   **0: First GPS**
*   **1: Second GPS**