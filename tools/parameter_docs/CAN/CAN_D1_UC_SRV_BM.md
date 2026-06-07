---
layout: parameter
name: CAN_D1_UC_SRV_BM
display_name: DroneCAN Servo Bitmask
description: A bitmask that determines which servo outputs are sent as actuator commands over the DroneCAN bus.
default_value: 0
range: 0 4294967295
units: 
group: CAN
visual_asset_id: dronecan_servo_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L115
---

# DroneCAN Servo Bitmask (CAN_D1_UC_SRV_BM)

## Description
`CAN_D1_UC_SRV_BM` maps specific output channels to DroneCAN Servo commands.

If you are using CAN-based servos (like the Hitag series), you use this bitmask to tell ArduPilot which logical outputs (Aileron, Elevator, etc.) should be routed to the CAN bus instead of the PWM rail.

## The Engineer's View
Sends `uavcan.equipment.actuator.ArrayCommand`.
Can be configured to send raw PWM values or normalized -1 to +1 commands depending on `CAN_D1_UC_OPTION`.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Only set bits for channels physically connected to CAN servos.