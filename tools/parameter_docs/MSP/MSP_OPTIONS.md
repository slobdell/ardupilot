---
layout: parameter
name: MSP_OPTIONS
display_name: MSP OSD Options
description: Bitmask for configuring MSP-based digital OSD behavior (Font compatibility, Telemetry mode).
default_value: 0
range: 0 15
units: 
group: MSP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_MSP/AP_MSP.cpp#L50
---

# MSP OSD Options (MSP_OPTIONS)

## Description
`MSP_OPTIONS` provides compatibility settings for digital video systems (like DJI, FatShark Avatar, and HDZero) that use the **MSP** protocol for their On-Screen Display.

Since digital OSDs often have their own internal font sets and communication styles, this parameter ensures the flight controller sends data in a format the goggles can understand.

*   **Bit 0 (1): EnableTelemetryMode.** Allows "push" mode telemetry if only the RX line is connected.
*   **Bit 1 (2): EnableBTFLFonts.** Use character mapping compatible with Betaflight-style fonts.
*   **Bit 2 (4): EnableINAVFonts.** Use character mapping compatible with INAV-style fonts.

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** If your OSD icons (like the battery or GPS symbols) look like random letters or garbled blocks, try toggling the **BTFL** or **INAV** font bits to match your goggle's firmware.