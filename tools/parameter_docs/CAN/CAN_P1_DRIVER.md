---
layout: parameter
name: CAN_P1_DRIVER
display_name: Index of virtual driver for CAN interface 1
description: Enabling this option enables use of CAN bus 1 and assigns it to a virtual driver instance.
default_value: 1
range: 0 3
units: 
group: CAN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_CANManager/AP_CANIfaceParams.cpp
---

# Index of virtual driver for CAN interface 1 (CAN_P1_DRIVER)

## Description
Enables the first CAN port and links it to one of the virtual CAN driver instances (D1, D2, or D3).

## Tuning & Behavior
*   **Default Value:** 1
*   **Values:** 0:Disabled, 1:First driver (D1), 2:Second driver (D2), 3:Third driver (D3)
*   **Requires reboot to take effect.**
