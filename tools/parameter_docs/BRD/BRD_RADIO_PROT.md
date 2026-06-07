---
layout: parameter
name: BRD_RADIO_PROT
display_name: Internal Radio Protocol
description: Selects the wireless protocol for the integrated radio receiver.
default_value: 0
range: 0 2
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L31
---

# Internal Radio Protocol (BRD_RADIO_PROT)

## Description
`BRD_RADIO_PROT` defines the communication standard used between the drone's internal receiver and your handheld transmitter. This is used on flight controllers with integrated SPI radios (like the SkyViper).

*   **0: Auto (Recommended).** The autopilot will attempt to detect if the transmitter is using DSM2 or DSMX.
*   **1: DSM2.** Legacy Spektrum protocol.
*   **2: DSMX.** Current Spektrum protocol (more robust against interference).

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Leave at **0 (Auto)** unless you have a transmitter that is known to only support one specific protocol.