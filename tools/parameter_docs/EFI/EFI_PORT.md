---
layout: parameter
name: EFI_PORT
display_name: EFI Serial Port
description: Specifies the serial port number where an EFI device is connected (AP_Periph).
default_value: -1
range: 0 10
units: 
group: EFI
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp
---

# EFI Serial Port (EFI_PORT)

## Description
Defines the hardware serial port instance used by the AP_Periph node to communicate with the EFI ECU.