---
layout: parameter
name: GPS_NAVFILTER
display_name: Navigation filter setting
description: Navigation filter engine setting for the GPS receiver.
default_value: 8
range: 0 8
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# Navigation filter setting (GPS_NAVFILTER)

## Description
Configures the GPS module's internal dynamic model. Setting this correctly for your vehicle type (e.g., Airborne 4G) helps the GPS maintain a more stable fix during high-acceleration maneuvers.

## Tuning & Behavior
*   **Default Value:** 8 (Airborne 4G)
*   **Values:** 0:Portable, 2:Stationary, 3:Pedestrian, 4:Automotive, 5:Sea, 6:Airborne1G, 7:Airborne2G, 8:Airborne4G