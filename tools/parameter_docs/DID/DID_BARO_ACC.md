---
layout: parameter
name: DID_BARO_ACC
display_name: Barometer vertical accuracy
description: Barometer Vertical Accuracy in meters when installed in the vehicle.
default_value: -1.0
range: 
units: m
group: DID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpenDroneID/AP_OpenDroneID.cpp
---

# Barometer vertical accuracy (DID_BARO_ACC)

## Description
Specifies the vertical position error (accuracy) of the barometer for Remote ID reporting.
*   **-1.0 (default) disables reporting this metric.**