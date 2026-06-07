---
layout: parameter
name: GPS_INJECT_TO
display_name: Destination for GPS_INJECT_DATA
description: Controls which GPS receiver(s) receive raw RTCM/correction data from the GCS.
default_value: 127
range: 
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# Destination for GPS_INJECT_DATA (GPS_INJECT_TO)

## Description
Directs the flow of RTK correction data received from the ground station.
*   **0: First GPS**
*   **1: Second GPS**
*   **127: All (Broadcast to all active receivers)**