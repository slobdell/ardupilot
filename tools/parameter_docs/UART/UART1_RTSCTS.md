---
layout: parameter
name: UART1_RTSCTS
display_name: UART 1 Flow Control
description: Enables hardware flow control (RTS/CTS) for the first serial port.
default_value: 2
range: 0 3
units: 
group: UART
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SerialManager/AP_SerialManager.cpp
---

# UART 1 Flow Control (UART1_RTSCTS)

## Description
`UART1_RTSCTS` enables Hardware Flow Control for the first telemetry port.

Flow control uses two extra wires (RTS and CTS) to signal when a device is ready to receive data. This prevents "Buffer Overflows" where one device sends data faster than the other can process it, which would otherwise result in corrupted or missing telemetry.

*   **0: Disabled.** 
*   **1: Enabled.**
*   **2: Auto (Default).** The autopilot will attempt to detect if the connected device supports flow control.

## Tuning & Behavior
*   **Recommendation:** Leave at **2 (Auto)**.
*   **SiK Radios:** These radios support hardware flow control. If you have the RTS/CTS wires connected, this setting will ensure maximum data reliability.