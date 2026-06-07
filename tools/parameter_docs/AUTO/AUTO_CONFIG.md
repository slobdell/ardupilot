---
layout: parameter
name: AUTO_CONFIG
display_name: GPS Auto Configuration
description: Whether the GPS driver should automatically configure the GPS module with the required messages and baudrate.
default_value: 1
range: 0 1
units: 
group: AUTO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_GPS/AP_GPS.cpp
---

# GPS Auto Configuration (AUTO_CONFIG)

## Description
Allows ArduPilot to automatically send configuration commands to the GPS module on boot. This ensures the GPS is outputting the correct MAVLink-compatible sentences at the optimal rate.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Only disable this if using a specialized GPS module that requires a static, pre-programmed configuration.**