---
layout: parameter
name: CAN_LOGLEVEL
display_name: CAN Loglevel
description: Loglevel for recording initialisation and debug information from CAN Interface.
default_value: 0
range: 0 4
units: 
group: CAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CANManager/AP_CANManager.cpp
---

# CAN Loglevel (CAN_LOGLEVEL)

## Description
Controls the verbosity of CAN-related diagnostic messages sent to the internal log. Useful for troubleshooting device initialization issues.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Values:** 0:Log None, 1:Log Error, 2:Log Warning, 3:Log Info, 4:Log Everything