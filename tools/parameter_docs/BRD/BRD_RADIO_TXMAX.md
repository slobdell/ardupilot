---
layout: parameter
name: BRD_RADIO_TXMAX
display_name: Internal Radio Max TX Power
description: Sets the maximum allowed transmit power for the handheld transmitter.
default_value: 8
range: 1 8
units: 
group: BRD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Radio/AP_Radio.cpp#L115
---

# Internal Radio Max TX Power (BRD_RADIO_TXMAX)

## Description
`BRD_RADIO_TXMAX` sets the maximum power limit for the **Handheld Transmitter** (remote control) when using a two-way integrated radio system (like SkyViper). 

The autopilot sends this value back to the transmitter via telemetry, commanding it to limit its output power to the specified level. This is useful for adhering to regional power regulations or managing battery life on the controller.

## Tuning & Behavior
*   **Default:** 8 (Maximum).
*   **Range:** 1 (Lowest) to 8 (Highest).
*   **Usage:** For maximum control range outdoors, leave at **8**. If you are only flying in a small indoor arena and want to reduce interference with other electronics, you can lower this value.