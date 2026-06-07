---
layout: parameter
name: SERIAL1_BAUD
display_name: Telem1 Baud Rate
description: Sets the baud rate (communication speed) for the SERIAL1 port.
default_value: 57
range: 1 12500000
units: 
group: SERIAL1
visual_asset_id: serial_baud_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_SerialManager/AP_SerialManager.cpp#L143
---

# Telem1 Baud Rate (SERIAL1_BAUD)

## Description
`SERIAL1_BAUD` sets the speed of the serial connection.

The value is generally in **baud / 1000** (e.g., 57 = 57600 baud). However, very high speeds (like 2Mbaud) can be entered directly as integers in some GCS implementations, but the parameter storage is compressed.

*   **57:** 57600 (Standard for SiK Telemetry Radios).
*   **115:** 115200 (Standard for most GPS units and Wifi bridges).
*   **921:** 921600 (High speed, good for fast logging or offboard control).
*   **1500:** 1.5 Mbaud.

## The Mathematics
$$ \text{Baud Rate} = \text{SERIAL1\_BAUD} \times 1000 $$
*(For values < 2000. Values > 2000 are interpreted literally).*

## The Engineer's View
Used in `AP_SerialManager::init()`.
The port configuration (start bits, stop bits, parity) is usually determined by the Protocol, but Baud is set here.
MAVLink usually requires 8N1 (8 data bits, No parity, 1 stop bit). S.Bus requires 100k baud, 8E2.

## Tuning & Behavior
*   **Default Value:** 57 (57600)
*   **Recommendation:**
    *   **SiK Radio:** 57
    *   **GPS:** 115 or 230 (Ensure the GPS is configured to match, or use auto-baud).
    *   **ESP8266/ESP32 Wifi:** 921 (for fast Mavlink).
    *   **RC Receiver (ELRS/Crossfire):** Usually auto-negotiated or fixed by protocol (e.g., CRSF runs at ~400k).
