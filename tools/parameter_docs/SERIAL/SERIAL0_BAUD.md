---
layout: parameter
name: SERIAL0_BAUD
display_name: Console/USB Baud Rate
description: Sets the communication speed for the SERIAL0 (primary console/USB) port.
default_value: 115
range: 1 12500000
units: 
group: SERIAL
visual_asset_id: serial_baud_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SerialManager/AP_SerialManager.cpp#L130
---

# Console/USB Baud Rate (SERIAL0_BAUD)

## Description
`SERIAL0_BAUD` defines the speed of the primary connection to your computer.

On most flight controllers, `SERIAL0` is the **USB** port. While USB itself doesn't have a "Baud Rate" in the traditional sense (it runs at high speed), the autopilot uses this parameter to determine the speed of the virtual UART bridged over USB. 

*   **115 (Default):** 115200 baud. standard for most connections.

## Tuning & Behavior
*   **Usage:** For most users, leave at **115**. 
*   **ESP32-S3 / Linux:** On boards where the primary console is a physical UART instead of a dedicated USB-Serial bridge, setting this correctly is essential for accessing the bootloader and terminal.