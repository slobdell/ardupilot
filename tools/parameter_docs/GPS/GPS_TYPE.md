---
layout: parameter
name: GPS_TYPE
display_name: GPS type
description: Specifies the hardware type for the primary GPS receiver.
default_value: 1
range: 
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS_Params.cpp
---

# GPS type (GPS_TYPE)

## Description
Enables the primary GPS and selects the specific driver for the connected hardware (e.g., u-blox, NMEA, DroneCAN).

## Tuning & Behavior
*   **Default Value:** 1 (u-blox)
*   **Common Values:** 1:u-blox, 2:MTK, 5:NMEA, 9:DroneCAN, 14:MAVLink, 100:SITL
*   **Requires reboot after changing to initialize the new driver.**