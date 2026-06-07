---
layout: parameter
name: CAN_D1_UC_S1_BD
display_name: DroneCAN Serial 1 Baud Rate
description: The baud rate for the first virtual serial bridge over DroneCAN.
default_value: 57
range: 1 2000
units: 
group: CAN
visual_asset_id: serial_baud_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L170
---

# DroneCAN Serial 1 Baud Rate (CAN_D1_UC_S1_BD)

## Description
`CAN_D1_UC_S1_BD` sets the speed of the "Virtual UART" bridge.

This allows you to tunnel serial data (like GPS or telemetry) through the CAN bus. The value is in kilobaud (e.g., 57 = 57600 baud).

## Tuning & Behavior
*   **Default Value:** 57 (57600).
*   **Recommendation:** Set this to match the physical baud rate of the device plugged into your remote CAN node (e.g. 115 for a high-speed GPS).