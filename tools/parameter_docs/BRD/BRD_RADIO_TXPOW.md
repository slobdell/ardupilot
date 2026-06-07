---
layout: parameter
name: BRD_RADIO_TXPOW
display_name: Internal Radio Transmit Power
description: Sets the output power level for the integrated telemetry radio.
default_value: 8
range: 1 8
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L73
---

# Internal Radio Transmit Power (BRD_RADIO_TXPOW)

## Description
`BRD_RADIO_TXPOW` controls the strength of the signal sent from the drone's internal radio back to the transmitter (Telemetry). 

This is used on flight controllers with built-in SPI receivers (like the SkyViper or some small AIO boards). Increasing the power improves range but consumes more battery and generates more heat on the radio chip.

*   **1:** Minimum power (Short range, safe for bench testing).
*   **8:** Maximum power (Long range).

## Tuning & Behavior
*   **Default:** 8.
*   **Recommendation:** Leave at **8** for outdoor flight. Reduce to **1** or **2** if you are only flying indoors or working on the bench to reduce electrical noise.