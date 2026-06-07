---
layout: parameter
title: MSP_PORT
name: MSP Serial Port
group: MSP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L472
---

# MSP_PORT: MSP Serial Port

## Description
This is the serial port number where `SERIALx_PROTOCOL` will be set to MSP (MultiWii Serial Protocol).

## Values
- **Range:** 0 to 10
- **Increment:** 1
- **Default:** 1

## Description
This parameter automatically configures a specific hardware UART (Serial Port) to speak the **MSP** protocol.

- **Purpose:** Used for integrating with peripherals that primarily speak MSP, such as DJI FPV Goggles (for OSD data) or certain ESC telemetry systems.
- **Auto-Configuration:** Setting this parameter effectively overrides the manual `SERIALx_PROTOCOL` setting for the selected port, ensuring the correct driver is loaded for MSP communication.

## Source Code
[ardupilot/Tools/AP_Periph/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L472)

