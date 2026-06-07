---
layout: parameter
name: SERIAL_PASS2
display_name: Serial Passthrough Port 2
description: Selects the second serial port for the UART-to-UART bridge.
default_value: -1
range: -1 10
units: 
group: SERIAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SerialManager/AP_SerialManager.cpp#L329
---

# Serial Passthrough Port 2 (SERIAL_PASS2)

## Description
Defines the other end of the serial bridge initiated by [SERIAL_PASS1](SERIAL_PASS1.html).