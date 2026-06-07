---
layout: parameter
name: CAN_D1_UC_SER_EN
display_name: DroneCAN Serial Bridge Enable
description: Master switch to enable serial-over-CAN (SLCAN or virtual UART) for this driver.
default_value: 0
range: 0 1
units: 
group: CAN
visual_asset_id: dronecan_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L160
---

# DroneCAN Serial Bridge Enable (CAN_D1_UC_SER_EN)

## Description
`CAN_D1_UC_SER_EN` activates the "Virtual Serial Port" system on the first CAN bus.

When enabled, you can map physical serial devices (like a GPS or telemetry radio) that are connected to remote DroneCAN nodes (like an AP_Periph adapter) as if they were plugged directly into the flight controller.

## Tuning & Behavior
*   **0:** Disabled.
*   **1:** Enabled.
*   **Reboot Required:** Yes.