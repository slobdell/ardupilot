---
layout: parameter
name: SERIAL_PASS1
display_name: Serial Passthrough Port 1
description: Selects the first serial port for the UART-to-UART bridge.
default_value: -1
range: -1 10
units: 
group: SERIAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_SerialManager/AP_SerialManager.cpp#L322
---

# Serial Passthrough Port 1 (SERIAL_PASS1)

## Description
`SERIAL_PASS1` and `SERIAL_PASS2` create a "Virtual Wire" inside the flight controller.

When you set both of these to valid port numbers (e.g., 0 for USB and 3 for GPS), the flight controller stops processing the data on those ports and simply forwards it back and forth. This is used to "talk through" the drone to reach external sensors for configuration (like using the u-blox u-center software to update GPS firmware while it is plugged into the drone).

## Tuning & Behavior
*   **Default:** -1 (Disabled).
*   **Usage:**
    1.  Set `SERIAL_PASS1` to **0** (USB).
    2.  Set `SERIAL_PASS2` to the index of the port you want to reach (e.g. 3 for SERIAL3).
    3.  Connect with your external software.
*   **Safety:** normal flight functionality on these ports is **Disabled** while passthrough is active. Do not attempt to fly while this is enabled.