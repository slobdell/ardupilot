---
layout: parameter
name: CAN_D1_UC_SRV_RT
display_name: DroneCAN Servo Transmit Rate
description: Maximum transmit rate (in Hz) for DroneCAN servo output messages.
default_value: 50
range: 1 200
units: Hz
group: CAN
visual_asset_id: dronecan_servo_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_DroneCAN/AP_DroneCAN.cpp#L100
---

# DroneCAN Servo Transmit Rate (CAN_D1_UC_SRV_RT)

## Description
`CAN_D1_UC_SRV_RT` sets the "Update Frequency" for CAN-based servos.

If you are using DroneCAN servos (or an AP_Periph node acting as a servo adapter), this parameter determines how many times per second the flight controller sends new position commands.

## Tuning & Behavior
*   **Default Value:** 50 Hz.
*   **High Performance:** Set to **100 Hz** or **200 Hz** for modern digital CAN servos to improve control response and stabilization.
*   **Bandwidth:** Higher rates use more CAN bus bandwidth. If your bus is congested, keep this at 50Hz.