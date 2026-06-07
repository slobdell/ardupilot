---
layout: parameter
name: BRD_RADIO_TELEM
display_name: Internal Radio Telemetry Enable
description: Enables sending telemetry data back to the transmitter (e.g., DSM).
default_value: 0
range: 0 1
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L66
---

# Internal Radio Telemetry Enable (BRD_RADIO_TELEM)

## Description
`BRD_RADIO_TELEM` enables the downlink of flight data from the drone's integrated radio receiver back to the pilot's handset.

This is primarily used for the **Cypress (DSM)** radio driver on specific flight controllers (like the SkyViper) to send battery status and other simple telemetry data to a Spektrum-compatible transmitter.

*   **0: Disabled.**
*   **1: Enabled.**

## Tuning & Behavior
*   **Default:** 0.
*   **Note:** This parameter is specific to the internal SPI radio and does not affect external telemetry radios connected to UART ports.