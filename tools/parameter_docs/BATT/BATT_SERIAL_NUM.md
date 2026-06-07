---
layout: parameter
name: BATT_SERIAL_NUM
display_name: Battery serial number
description: Battery serial number, automatically filled in for SMBus batteries, otherwise will be -1. With DroneCan it is the battery_id.
default_value: -1
range: 
units: 
group: BATT
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_BattMonitor/AP_BattMonitor_Params.cpp
---

# Battery serial number (BATT_SERIAL_NUM)

## Description
Unique serial number or ID assigned to the battery pack. Primarily used for distinguishing between multiple "Smart" or DroneCAN batteries.