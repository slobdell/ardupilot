---
layout: parameter
name: CAN_D1_PROTOCOL
display_name: Primary protocol for virtual driver 1
description: Selects the primary high-level protocol running on virtual driver 1.
default_value: 1
range: 
units: 
group: CAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CANManager/AP_CANManager_CANDriver_Params.cpp
---

# Primary protocol for virtual driver 1 (CAN_D1_PROTOCOL)

## Description
Defines the software protocol (e.g., DroneCAN, PiccoloCAN) used by the first virtual CAN driver.

## Tuning & Behavior
*   **Default Value:** 1 (DroneCAN)
*   **Values:** 0:Disabled, 1:DroneCAN, 4:PiccoloCAN, 6:EFI_NWPMU, 8:KDECAN, 10:Scripting
