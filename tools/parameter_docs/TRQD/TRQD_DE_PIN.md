---
layout: parameter
name: TRQD_DE_PIN
display_name: Torqeedo RS485 Data Enable Pin
description: The GPIO pin used to toggle the RS485 driver's transmit/receive mode (DE/RE).
default_value: -1
range: -1 103
units: 
group: TRQD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L29
---

# Torqeedo RS485 Data Enable Pin (TRQD_DE_PIN)

## Description
`TRQD_DE_PIN` is required when using a generic RS485-to-Serial converter module to talk to the Torqeedo motor.

RS485 is a half-duplex protocol. The converter needs a signal to know when to transmit and when to listen. This pin provides that "Push-to-Talk" signal.

## Tuning & Behavior
*   **-1 (Default):** Use the serial port's CTS pin (if hardware flow control is supported).
*   **0-103:** Physical GPIO pin number connected to the DE/RE pin on the RS485 module.