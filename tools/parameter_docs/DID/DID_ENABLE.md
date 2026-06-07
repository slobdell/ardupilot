---
layout: parameter
name: DID_ENABLE
display_name: Enable ODID subsystem
description: Enables the OpenDroneID (Remote ID) subsystem.
default_value: 0
range: 0 1
units: 
group: DID
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_OpenDroneID/AP_OpenDroneID.cpp
---

# Enable ODID subsystem (DID_ENABLE)

## Description
Master switch for OpenDroneID (Remote ID) functionality. Enables compliance with broadcast ID regulations.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Requires reboot to take effect.**