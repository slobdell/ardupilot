---
layout: parameter
name: BRD_RADIO_TYPE
display_name: Internal Radio Type
description: Enables and selects the protocol for the flight controller's built-in radio receiver (SPI).
default_value: 0
range: 0 3
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L24
---

# Internal Radio Type (BRD_RADIO_TYPE)

## Description
`BRD_RADIO_TYPE` enables the integrated radio receiver found on some flight controllers (like the SkyViper or specialized AIO racing boards). These receivers are connected directly to the CPU via an SPI bus, rather than a standard UART.

*   **0: None.** Internal radio is disabled.
*   **1: CYRF6936.** DSM/Spektrum compatible.
*   **2: CC2500.** FrSky/Futaba compatible.
*   **3: BK2425.** 

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Setup:** Once enabled, you must bind your transmitter. Use the board-specific binding procedure (usually a button or a MAVLink command).