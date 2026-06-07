---
layout: parameter
name: SERVO_GPIO_MASK
display_name: Servo GPIO Mask
description: A bitmask of servo output channels to treat as GPIOs.
default_value: 0
range: 0 4294967295
units: 
group: SERVO
visual_asset_id: brd_io_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SRV_Channel/SRV_Channel.cpp#L100
---

# Servo GPIO Mask (SERVO_GPIO_MASK)

## Description
`SERVO_GPIO_MASK` converts PWM servo headers into digital switches.

By setting a bit in this mask, the corresponding servo output pin stops sending PWM pulses and becomes a standard GPIO pin. You can then use it with `RELAY_PIN` or Lua scripts to toggle lights, cameras, or other digital devices.

## Tuning & Behavior
*   **Default Value:** 0.
*   **Bit 0:** Servo 1.
*   **Bit 1:** Servo 2.
*   **Reboot Required:** Yes.