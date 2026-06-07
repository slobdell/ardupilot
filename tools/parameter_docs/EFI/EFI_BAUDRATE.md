---
layout: parameter
name: EFI_BAUDRATE
display_name: EFI Port Baud Rate
description: The serial communication speed for the EFI (Electronic Fuel Injection) system.
default_value: 0
range: 1 1000000
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_EFI/AP_EFI.cpp
---

# EFI Port Baud Rate (EFI_BAUDRATE)

## Description
`EFI_BAUDRATE` sets the speed for the serial connection between the flight controller and the engine's ECU.

*   **Default:** 0 (Use driver default).
*   **Usage:** Set this to match the output rate of your ECU (e.g. 57600 or 115200).
*   **Reboot Required:** Yes.