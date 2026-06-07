---
layout: parameter
name: SERIAL1_PROTOCOL
display_name: Telem1 protocol selection
description: Selects the communication protocol for the SERIAL1 port (usually labeled "TELEM1" on the board).
default_value: 2
range: -1 49
units: 
group: SERIAL1
visual_asset_id: serial_protocol_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_SerialManager/AP_SerialManager.cpp#L137
---

# Telem1 protocol selection (SERIAL1_PROTOCOL)

## Description
`SERIAL1_PROTOCOL` determines what language ArduPilot speaks on the first telemetry port.

*   **2: MAVLink2 (Default).** Modern telemetry protocol. Use this for SiK Radios, Wifi Bridges, and Onboard Computers (Raspberry Pi/Jetson).
*   **5: GPS.** Connect an external GPS unit here.
*   **10: FrSky SPort Passthrough.** For OpenTX/EdgeTX telemetry on Taranis/Radiomaster radios.
*   **23: RCIN.** If you want to connect your ELRS/Crossfire receiver to this UART instead of the dedicated RCIN pin.

## The Mathematics
This parameter is an enumeration (integer ID) that selects the driver backend instantiated for this UART.

## The Engineer's View
Used in `AP_SerialManager::init()`.
Changing this parameter usually requires a **Reboot** to initialize the correct driver.
ArduPilot supports concurrent protocols on different ports (e.g., MAVLink on Serial 1, GPS on Serial 3, FrSky on Serial 4).

## Tuning & Behavior
*   **Default Value:** 2 (MAVLink2)
*   **Recommendation:**
    *   **Telemetry Radio:** 2
    *   **GPS:** 5
    *   **Crossfire/ELRS:** 23 (RCIN) - Note: Crossfire VTX control uses protocol 29.
    *   **DJI FPV (OSD):** 33
    *   **Disabled:** -1 (Use to free up resources or if port is broken).