---
layout: parameter
name: SERVO_FTW_MASK
display_name: FETtec OneWire Motor Mask
description: A bitmask of motor channels using the FETtec OneWire protocol.
default_value: 0
range: 0 65535
units: 
group: SERVO
visual_asset_id: sim_esc_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_FETtecOneWire/AP_FETtecOneWire.cpp#L100
---

# FETtec OneWire Motor Mask (SERVO_FTW_MASK)

## Description
`SERVO_FTW_MASK` enables the high-speed digital **FETtec OneWire** protocol on specific output channels.

OneWire is a specialized ESC protocol (similar to DShot but using a different electrical standard) that allows for bidirectional communication (RPM, voltage, current) over a single signal wire. By setting a bit in this mask, you tell ArduPilot to use the OneWire driver for that specific motor.

*   **Bit 0 (1):** Motor 1
*   **Bit 1 (2):** Motor 2
*   ...

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **Reboot Required:** Yes.
*   **Requirement:** You must also set the `SERIALx_PROTOCOL` to **43** (FETtec OneWire) on the UART connected to the ESCs.