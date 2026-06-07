---
layout: parameter
name: PRX_BAUDRATE
display_name: Proximity Sensor Baud Rate
description: The serial communication speed (baud rate) for the proximity sensor.
default_value: 0
range: 1 1000000
units: 
group: PRX
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp#L554
---

# Proximity Sensor Baud Rate (PRX_BAUDRATE)

## Description
`PRX_BAUDRATE` sets the communication speed for proximity sensors (like Lidars) that connect via a Serial (UART) port.

This parameter is primarily found on **AP_Periph** nodes that are being used as CAN bridges for serial sensors.

## Tuning & Behavior
*   **Default:** 0 (Use driver default).
*   **Common Values:** 115200 (Most common), 921600 (High speed).
*   **Reboot Required:** Yes.