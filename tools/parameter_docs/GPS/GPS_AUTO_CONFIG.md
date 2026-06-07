---
layout: parameter
name: GPS_AUTO_CONFIG
display_name: Automatic GPS configuration
description: Controls if the autopilot should automatically configure the GPS.
default_value: 1
range: 0 2
units: 
group: GPS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# Automatic GPS configuration (GPS_AUTO_CONFIG)

## Description
Allows ArduPilot to automatically send the required initialization commands and baudrate settings to the GPS module.

## Tuning & Behavior
*   **Default Value:** 1 (Serial only)
*   **Values:** 0:Disabled, 1:Enable for Serial GPS, 2:Enable for DroneCAN as well