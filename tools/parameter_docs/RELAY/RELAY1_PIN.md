---
layout: parameter
name: RELAY1_PIN
display_name: Relay Pin (Instance 1)
description: The physical GPIO pin used for Relay 1.
default_value: -1
range: -1 103
units: 
group: RELAY
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Relay/AP_Relay_Params.cpp#L59
---

# Relay Pin (RELAY1_PIN)

## Description
`RELAY1_PIN` tells the autopilot which digital connector on the flight controller is wired to the relay hardware.

*   **-1:** Disabled (No physical pin assigned).
*   **0-103:** Physical GPIO pin number.

## Tuning & Behavior
*   **Setup:** Refer to your flight controller's "GPIOs" documentation to find the correct number for the pin you are using.
*   **Hardware Constraint:** Standard servo outputs on many Pixhawk-style boards cannot be used as relays unless they are first "freed" by setting their `SERVOx_FUNCTION` to -1.