---
layout: parameter
name: GPIO_MASK
display_name: Servo GPIO Mask
description: Bitmask of servo outputs to use as GPIOs.
default_value: 0
range: 
units: 
group: GPIO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SRV_Channel/SRV_Channels.cpp
---

# Servo GPIO Mask (GPIO_MASK)

## Description
Allows specific PWM output pins to be repurposed as general-purpose input/output (GPIO) pins. This is useful for controlling external hardware like LEDs, relays, or camera triggers that don't use standard PWM signals.
*   **Bitmask corresponds to output channels 1 through 16.**