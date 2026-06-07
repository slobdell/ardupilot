---
layout: parameter
name: CAN_D1_UC_ESC_BM
display_name: DroneCAN ESC Bitmask
description: A bitmask that determines which motor outputs are sent as ESC commands over the DroneCAN bus.
default_value: 0
range: 0 4294967295
units: 
group: CAN
visual_asset_id: dronecan_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L123
---

# DroneCAN ESC Bitmask (CAN_D1_UC_ESC_BM)

## Description
`CAN_D1_UC_ESC_BM` maps specific ArduPilot servo output channels to DroneCAN ESC commands.

If you have 4 DroneCAN ESCs controlling motors 1-4, you must set this bitmask to include channels 1, 2, 3, and 4. This tells the flight controller: "Don't send PWM for these motors; send a digital CAN message instead."

*   **Bit 0 (1):** Motor/Servo 1
*   **Bit 1 (2):** Motor/Servo 2
*   **Bit 2 (4):** Motor/Servo 3
*   **Bit 3 (8):** Motor/Servo 4

## The Engineer's View
Defined in `AP_DroneCAN.cpp`.
When a bit is set, the standard PWM output for that channel is suppressed (or acts as a backup, depending on configuration), and `uavcan.equipment.esc.RawCommand` messages are broadcast on the CAN bus.

## Tuning & Behavior
*   **Default Value:** 0
*   **QuadCopter (Motors 1-4):** Set to **15** (1+2+4+8).
*   **HexaCopter (Motors 1-6):** Set to **63**.