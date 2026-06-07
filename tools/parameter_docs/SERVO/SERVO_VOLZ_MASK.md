---
layout: parameter
name: SERVO_VOLZ_MASK
display_name: Volz Servo Mask
description: A bitmask of output channels that use the Volz serial servo protocol.
default_value: 0
range: 0 4294967295
units: 
group: SERVO
visual_asset_id: servo_volz_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Volz_Protocol/AP_Volz_Protocol.cpp#L36
---

# Volz Servo Mask (SERVO_VOLZ_MASK)

## Description
`SERVO_VOLZ_MASK` allows you to control high-end industrial actuators from **Volz**.

These servos use a proprietary RS-485 serial protocol instead of PWM. By setting a bit in this mask, you tell ArduPilot to send position commands for that channel over the configured serial port (`SERIALx_PROTOCOL = 14` or similar) addressed to the specific actuator ID.

## The Engineer's View
Defined in `AP_Volz_Protocol.cpp`.
The Volz driver runs a separate thread to handle the 115200 baud serial traffic.
*   **Bit 0 (1):** Channel 1
*   **Bit 1 (2):** Channel 2
*   ...

The driver calculates the required CRC and sends the "Extended Position" command.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Recommendation:** Set bits corresponding to the servo channels you have wired to the RS-485 bus.
*   **Prerequisite:** You must configure a Serial Port for the Volz protocol.