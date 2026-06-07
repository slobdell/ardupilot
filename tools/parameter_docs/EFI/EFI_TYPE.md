---
layout: parameter
name: EFI_TYPE
display_name: EFI communication type
description: What method of communication is used for Electronic Fuel Injection.
default_value: 0
range: 
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI.cpp
---

# EFI communication type (EFI_TYPE)

## Description
Enables the Electronic Fuel Injection (EFI) subsystem and selects the communication protocol used to talk to the engine's ECU.

## Tuning & Behavior
*   **Default Value:** 0 (None)
*   **Values:** 1:Serial-MS (MegaSquirt), 2:NWPMU, 3:Serial-Lutan, 5:DroneCAN, 6:Currawong-ECU, 7:Scripting, 8:Hirth, 9:MAVLink
*   **Requires reboot after changing to initialize the driver.**